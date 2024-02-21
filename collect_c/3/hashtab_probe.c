#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 9973

struct hentry {
	char *name;
	char *defn;
};

static struct hentry *hashtab[HASHSIZE];

unsigned hash(char *);
struct hentry *lookup(char *);
struct hentry *install(char *, char *);
struct hentry *undef(char *);

int main(int argc, char const *argv[])
{
	assert(hash("abc") > 0 && hash("def") < HASHSIZE);
	assert(install("aaa", "bbb") != NULL);
	assert(lookup("bbb") == NULL);
	assert(lookup("aaa") != NULL);
	assert(strcmp(lookup("aaa")->defn, "bbb") == 0);
	assert(install("aaa", "ccc") != NULL);
	assert(strcmp(lookup("aaa")->defn, "ccc") == 0);

	assert(undef("aaa") != NULL);
	assert(lookup("aaa") == NULL);
	assert(install("aaa", "ddd") != NULL);
	assert(strcmp(lookup("aaa")->defn, "ddd") == 0);

	assert(undef("bbb") == NULL);

	char p[12];
	int i;
	void itoa(int, char*);

	for (i = 0; i < 5000; ++i) {
		itoa(i, p);
		assert(install(p, p) != NULL);
	}
	for (i = 0; i < 2000; ++i) {
		itoa(i, p);
		assert(undef(p) != NULL);
	}
	for (i = 2000; i < 5000; ++i) {
		itoa(i, p);
		assert(lookup(p) != NULL);
		assert(strcmp(lookup(p)->name, p) == 0);
	}

	return 0;
}

unsigned hash(char *s) {
	unsigned hashval;
	for (hashval = 0; *s; s++) {
		hashval = hashval * 256 + *s;
	}

	return hashval % HASHSIZE;
}

/* itoa: convert an integer to characters in s */
void itoa(int n, char *s) {
	int sign, r;
	char *p = s;
	void reverse(char *);
	
	sign = n;

	do {
		r = n%10;
		if (r < 0) {
			r = -r;
		}
		*p++ = r + '0';
		n = n/10;
	} while (n != 0);

	if (sign < 0) {
		*p++ = '-';
	}

	*p = '\0';
	reverse(s);
}

/* reverse: reverse characters in a character array */
void reverse(char *s) {
	char *p;
	char temp;
	for (p = s; *p; p++)
		;
	p--;
	for (; s < p; s++, p--) {
		temp = *s;
		*s = *p;
		*p = temp;
	}
}

struct hentry *lookup(char *s) {
	int i;
	unsigned hashval = hash(s);

	for (i = hashval; i < HASHSIZE + hashval && hashtab[i % HASHSIZE] != NULL; ++i) {
		if (strcmp(hashtab[i % HASHSIZE]->name, s) == 0) {
			return hashtab[i % HASHSIZE];
		}
	}

	return NULL;
}

struct hentry *install(char *name, char *defn) {
	int i;
	unsigned hashval = hash(name);
	char *strd(char *);

	for (i = hashval; i < HASHSIZE + hashval && hashtab[i % HASHSIZE] != NULL; ++i) {
		if (strcmp(hashtab[i % HASHSIZE]->name, name) == 0) {
			break;
		}
	}
	
	i = i % HASHSIZE;
	if (hashtab[i] == NULL) {
		hashtab[i] = (struct hentry*)malloc(sizeof(hashtab[i]));
		if (hashtab[i] == NULL || (hashtab[i]->name = strd(name)) == NULL || (hashtab[i]->defn = strd(defn)) == NULL) {
			return NULL;
		}
	} else {
		free(hashtab[i]->defn);
		if ((hashtab[i]->defn = strd(defn)) == NULL) {
			return NULL;
		}
	}
	
	return hashtab[i];
}

struct hentry *undef(char *s) {
	int i, j;
	unsigned hashval = hash(s);
	struct hentry *p;
	struct hentry *e;

	for (i = hashval; i < HASHSIZE + hashval && hashtab[i % HASHSIZE] != NULL; ++i) {
		if (strcmp(hashtab[i % HASHSIZE]->name, s) == 0) {
			p = hashtab[i % HASHSIZE];
			hashtab[i % HASHSIZE] = NULL;

			// re-hash adjacent values
			for (j = i + 1; j < HASHSIZE + i && hashtab[j % HASHSIZE] != NULL; ++j) {
				e = hashtab[j % HASHSIZE];
				hashtab[j % HASHSIZE] = NULL;
				install(e->name, e->defn);
				free(e->name);
				free(e->defn);
				free(e);
			}

			return p;
		}
	}

	return NULL;
}

char *strd(char *s) {
	char *p = (char *)malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);
	}
	return p;
}
