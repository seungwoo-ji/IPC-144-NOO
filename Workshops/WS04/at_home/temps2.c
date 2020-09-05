//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include<stdio.h>

#define MAXDAYS 10
#define MINDAYS 3
#define MAXTEMP 40
#define MINTEMP -40

int main(void)
{
	int i, days, avgDays, totalTemp, highestTemp = MINTEMP, lowestTemp = MAXTEMP, highestDay = 0, lowestDay = 0;

	int highTemp[MAXDAYS] = { 0 };
	int lowTemp[MAXDAYS] = { 0 };

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	scanf("%d", &days);

	printf("\n");

	while (days < MINDAYS || days > MAXDAYS)
	{
		printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
		scanf("%d", &days);
		printf("\n");
	}

	for (i = 0; i < days; i++)
	{

		printf("Day %d - High: ", i + 1);
		scanf("%d", &highTemp[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowTemp[i]);

		while (lowTemp[i] < MINTEMP || highTemp[i] <= lowTemp[i] || highTemp[i] > MAXTEMP)
		{
			printf("\n");

			printf("Incorrect values, temperatures must be in the range %d to %d, high must be greater than low.\n\n", MINTEMP, MAXTEMP);
			printf("Day %d - High: ", i + 1);
			scanf("%d", &highTemp[i]);

			printf("Day %d - Low: ", i + 1);
			scanf("%d", &lowTemp[i]);
		}
		
		if (highTemp[i] > highestTemp)
		{
			highestTemp = highTemp[i];
			highestDay = i + 1;
		}

		if (lowTemp[i] < lowestTemp)
		{
			lowestTemp = lowTemp[i];
			lowestDay = i + 1;
		}
	}

	printf("\n");

	printf("Day  Hi  Low\n");
	
	for (i = 0; i < days; i++)
	{
		printf("%d %4d %5d\n", i + 1, highTemp[i], lowTemp[i]);
	}

	printf("\n");

	printf("The highest temperature was %d, on day %d\n", highestTemp, highestDay);

	printf("The lowest temperature was %d, on day %d\n\n", lowestTemp, lowestDay);


	do
	{
		totalTemp = 0;

		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &avgDays);
		printf("\n");

		while (avgDays > days || avgDays == 0)
		{
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &avgDays);

			printf("\n");
		}

		if (avgDays <= days && avgDays >= 1)
		{
			for (i = 0; i < avgDays; i++)
			{
				totalTemp += highTemp[i] + lowTemp[i];
			}
			printf("The average temperature up to day %d is: %.2f\n\n", avgDays, totalTemp / (2.0f * avgDays));
		}
	} while (avgDays > 0);

	printf("Goodbye!\n");

	return 0;
}