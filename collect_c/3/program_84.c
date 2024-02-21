// store information in the form of structure

#include <stdio.h>

struct student {
	char name[50];
	int roll;
	float marks;
} s;

int main()
{
	printf("Please enter the information:\n");

	printf("Please enter the name: ");
	scanf("%s", s.name);

	printf("Please enter the roll number: ");
	scanf("%d", &s.roll);

	printf("Please enter the marks: ");
	scanf("%f", &s.marks);

	printf("Displaying the stored information:\n");
	printf("Student's name: %s,\n", s.name);
	printf("Student's roll: %d,\n", s.roll);
	printf("Student's marks: %f.\n", s.marks);

	return 0;
}
