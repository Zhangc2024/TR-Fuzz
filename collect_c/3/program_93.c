#include <stdio.h>
#include <stdlib.h>

char findGender(unsigned long int n, unsigned long int x) {
    if (n == 1) {
        return 'M';
    }

    if (findGender(n - 1, (x + 1) / 2) == 'F') {
        return (x % 2) ? 'F' : 'M';
    }

    return (x % 2) ? 'M' : 'F';
}

int main() {
    int t;

    FILE *fin = fopen("t4", "r");
    FILE *fout = fopen("t4.out", "w");

    if(fin == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fin, "%d", &t);

    while(t != 0) {
        unsigned long int n, x;

        fscanf(fin, "%lu %lu", &n, &x);

        fprintf(fout,"%c\n",findGender(n, x));

        t--;
    }

    fclose(fin);
    fclose(fout);

    return 0;
}