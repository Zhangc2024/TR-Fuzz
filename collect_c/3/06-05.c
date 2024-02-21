#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *s);

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

main()
{
    install("min", "100");
    install("max", "1000");

    struct nlist *p;
    p = lookup("min");
    printf(p->defn);

	undef("min");
    if (lookup("min") == NULL)
        printf("no found");
}

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof (*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/* undef: remove a name and definition from the table */
void undef(char *s)
{
	int h;
	struct nlist *prev, *np;

	prev = NULL;
	h = hash(s);
	for (np = hashtab[h]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0)
			break;
		prev = np;
	}
	if (np != NULL) {
		if (prev == NULL)
			hashtab[h] = np->next;
		else
			prev->next = np->next;
		free((void *) np->name);
		free((void *) np->defn);
		free((void *) np);
	}
}
