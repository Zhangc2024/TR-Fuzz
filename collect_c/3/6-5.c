#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#define HASHSZ 5

typedef struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
} nlist;

unsigned hash(char *key);

static nlist *hashtab[HASHSZ];

nlist* lookup(char *val);
nlist* install(char *key, char *val);
void undef1(char *key);	//Recursive
void undef2(char *key);	//Non-Rec

nlist* nalloc();
void nfree(nlist*);

void hprint();

int main(int argc, char **argv) {
	install("TRUE", "0");
	install("FALSE", "0");
	install("TRUE", "1");
	install("UNDEF", NULL);
	install("MAXWORD", "1000");
	install("STATE", "1");
	install("MAXWORD", "999");
	install("MAXLEN", "512");
	install("BUFSIZ", "256");
	install("MAXLINE", "10000");
	install("STATE", "0");
	hprint();
	puts("---");
	undef2("STATE");
	undef1("BUFSIZ");
	undef2("FALSE");
	hprint();

	int i;
	for (i = 0; i < HASHSZ; i++)
		nfree(hashtab[i]);
}

/*Compute a non-negative Hash Value of the give name */
unsigned hash(char *name) {
	unsigned hashval;
	char *s = name;
	for (hashval = 0; *s; s++)
		hashval += *s + hashval * 31;

	return (hashval % HASHSZ);
}

/*	LookUp the hashtable and return the node with the name
 * if name is null or the node with the name does not exist, return null
 */
nlist* lookup(char *name) {
	nlist *np;

	if (!name)
		return NULL;

	for (np = hashtab[hash(name)]; np && strcmp(np->name, name); np = np->next)
		;

	return np;
}

/* Add a new entry if name is not present
 * if name is present, replace the defn
 * if defn is null, delete the entry with the name
 * if name is null, nothing will happen and will return null
 */
nlist* install(char *name, char *defn) {
	if (!name)
		return NULL;

	nlist *tmp;
	unsigned hashval;

	if (!(tmp = lookup(name))) {
		/*	name doesnt exists in table	*/
		if (!(tmp = nalloc()))
			return NULL;

		if (!(tmp->name = strdup(name))) {
			free(tmp);
			return NULL;
		}

		/*	Add tmp to the head	*/
		hashval = hash(name);
		tmp->next = hashtab[hashval];
		hashtab[hashval] = tmp;
	} else
		/*	Name exist in the table	*/
		free(tmp->defn);

	if (!defn || !(tmp->defn = strdup(defn)))
		tmp->defn = NULL;

	return tmp;
}

/*	Recursive Version
 * if name is null, nothing happens
 */
void undef1(char *name) {
	if (!name)
		return;

	nlist* recundef(char*, nlist*), *tmp;
	unsigned hashval;
	hashval = hash(name);
	tmp = hashtab[hashval];

	hashtab[hashval] = recundef(name, tmp);
}

nlist* recundef(char *name, nlist *np) {
	nlist *tmp;
	if (!np)
		return NULL;

	if (strcmp(np->name, name) == 0) {
		tmp = np->next;
		free(np->defn);
		free(np->name);
		free(np);
		return tmp;
	}

	np->next = recundef(name, np->next);
	return np;
}
/* Non-Recursive Version
 * if name is null, nothing happens and returns null
 */
void undef2(char *name) {
	if (!name)
		return;

	nlist *prev, *cur;
	unsigned hashval;
	hashval = hash(name);

	for (prev = NULL, cur = hashtab[hashval]; cur && strcmp(cur->name, name);
			cur = cur->next)
		prev = cur;

	if (cur) {
		/*	name Found	*/
		if (prev)
			prev->next = cur->next;
		else
			hashtab[hashval] = cur->next;

		free(cur->name);
		free(cur->defn);
		free(cur);
	}

}

nlist* nalloc() {
	return (nlist*) malloc(sizeof(nlist));
}

void nfree(nlist *np) {
	if (np) {
		nfree(np->next);
		free(np->name);
		free(np->defn);
	}
	free(np);
}

/*	Print the HashTable in pretty format */
void hprint() {
	void nprint(nlist*);
	int i;
	for (i = 0; i < HASHSZ; i++)
		if (hashtab[i]) {
			printf("HashValue: %3d\t", i);
			nprint(hashtab[i]);
		}

}

/*	Print the linked list in pretty format	*/
void nprint(nlist *np) {
	assert(np != NULL);
	nlist *tmp;
	for (tmp = np; tmp->next; tmp = tmp->next) {
		printf("[ name:%6s defn:%6s ]", tmp->name, tmp->defn);
		printf("-->");
	}

	printf("[ name:%6s defn:%6s ]\n", tmp->name, tmp->defn);
}
