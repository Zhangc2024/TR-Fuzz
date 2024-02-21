// program to input week day number and print week day name.

// using nested if-else

#include<stdio.h>

int main()
{
	int weekDayNumber;

	printf("Please input week day number (0-6) : ");
	scanf("%d", &weekDayNumber);

	if(weekDayNumber == 0)
		printf("Sunday");
	else
		if(weekDayNumber == 1)
			printf("Monday");
		else
			if(weekDayNumber == 2)
				printf("Tuesday");
			else
				if(weekDayNumber == 3)
					printf("Wednesday");
				else
					if(weekDayNumber == 4)
						printf("Thursday");
					else
						if(weekDayNumber == 5)
							printf("Friday");
						else
							if(weekDayNumber == 6)
								printf("Saturday");
							else
								printf("Invalid Week..");

	return 0;

}
