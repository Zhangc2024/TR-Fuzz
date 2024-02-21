#include <stdio.h>

typedef enum
{
    summer, fall, winter, spring
} season;

enum months { JAN };

void printPhrase(season s);

int main() {
    season s = 0;
    printf("%d\n", s);

    enum months m = JAN;
    printf("%d\n", m);

    printPhrase(summer);
    printPhrase(2);
    return 0;
}

void printPhrase(season s) {
    if (s == summer) {
        printf("It's summer!\n");
    } else if (s == fall) {
        printf("It's fall!\n");
    } else if (s == winter) {
        printf("It's winter\n");
    } else {
        printf("It's spring\n");
    }
}
