#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 997

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
struct nlist *undef(char *);

int main(int argc, char const *argv[])
{
	assert(hash("test string") > 0 && hash("second string") < HASHSIZE);
	assert(install("abc", "def") != NULL);
	assert(lookup("abc") != NULL);
	assert(strcmp(lookup("abc")->defn, "def") == 0);
	assert(install("abc", "ggg") != NULL);
	assert(strcmp(lookup("abc")->defn, "ggg") == 0);
	
	assert(undef("abc") != NULL);
	assert(lookup("abc") == NULL);

	assert(lookup("def") == NULL);
	assert(install("ddd", "eee") != NULL);
	assert(lookup("ddd") != NULL);
	
	return 0;
}

unsigned hash(char *s) {
	unsigned hashval;

	for (hashval = 0; *s; s++) {
		hashval = hashval * 256 + *s;
	}

	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
	struct nlist *p;
	for (p = hashtab[hash(s)]; p != NULL; p = p->next) {
		if (strcmp(p->name, s) == 0) {
			break;
		}
	}

	return p;
}

struct nlist *install(char *name, char *defn) {
	char *sdup(char *);
	struct nlist *p;

	if ((p = lookup(name)) != NULL) {
		// replace defn
		free((void *) p->defn);
		if ((p->defn = sdup(defn)) == NULL) {
			return NULL;
		}
	} else {
		// add new node to the list
		unsigned hashval = hash(name);
		p = (struct nlist*)malloc(sizeof(*p));
		if (p == NULL || (p->name = sdup(name)) == NULL || (p->defn = sdup(defn)) == NULL) {
			return NULL;
		}
		p->next = hashtab[hashval];
		hashtab[hashval] = p;
	}

	return p;
}

struct nlist *undef(char *s) {
	struct nlist *p;
	struct nlist *prevp = NULL;

	for (p = hashtab[hash(s)]; p != NULL; p = p->next) {
		if (strcmp(s, p->name) == 0) {
			if (prevp != NULL) {
				prevp->next = p->next;
			} else {
				// head
				hashtab[hash(s)] = p->next;
			}
			p->next = NULL;
			return p;
		}
		prevp = p;
	}

	return NULL;
}

char *sdup(char *s) {
	char *p = (char *)malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);
	}
	return p;
}
