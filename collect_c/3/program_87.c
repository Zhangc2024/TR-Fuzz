// calculate the difference between two time periods

#include <stdio.h>

struct time {
	int seconds;
	int minutes;
	int hours;
};

int main()
{
	struct time t1, t2, result;

	printf("Please enter hours, minutes and seconds of first time: ");
	scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

	printf("Please enter hours, minutes and seconds of second time: ");
	scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

	while (t2.seconds > t1.seconds)
	{
		--t1.minutes;
		t1.seconds += 60;
	}

	result.seconds = t1.seconds - t2.seconds;

	while (t2.minutes > t1.minutes)
	{
		--t1.hours;
		t1.minutes += 60;
	}

	result.minutes = t1.minutes - t2.minutes;

	result.hours = t1.hours - t2.hours;

	printf("Resulting time is: %d hours, %d minutes and %d seconds.\n", result.hours, result.minutes, result.seconds);

	return 0;
}
