#include <stdio.h>

#define HASHSIZE 101

// table entry
struct nlist {
    // next entry in chain
    struct nlist *next;
    // defined name
    char *name;
    //replacement text
    char *defn;
};

// pointer table
static struct nlist *hashtab[HASHSIZE];

// hash: form hash value fro string s
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

// lookup: look for s in hashtable
struct nlist *lookup(char *s) {
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}

// install: put (name, defn) in hashtab
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    // not found
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        // This is a chain to handle different names with same
        // hash value. np is a new node here. This code makes
        // new node np point to the current head of the chain
        np->next = hashtab[hashval];
        // Now hashtab point to np, so that np will be current
        // head, and the previous head becomes the second in 
        // the chain
        hashtab[hashval] = np;
    } else {
        // already there
        // free previous defn, to assign it a new replacement
        free((void *) np->defn);
    }
    if ((np->defn == strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}