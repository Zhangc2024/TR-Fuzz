// perform dynamic memory allocation for structures

#include <stdio.h>
#include <stdlib.h>

struct course {
	int marks;
	char subjects[10];
};

int main ()
{
	struct course *ptr;

	int i, num;

	printf("Enter the number of records: ");
	scanf("%d", &num);

	ptr = (struct course *) malloc(num * sizeof(struct course));

	for (i = 0; i < num; i++)
	{
		printf("Enter the course details: ");
		scanf("%s %d", (ptr + i)->subjects, &(ptr + i)->marks);
	}

	printf("Displaying information:\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\t%d.\n", (ptr + i)->subjects, (ptr + i)->marks);
	}

	return 0;
}
