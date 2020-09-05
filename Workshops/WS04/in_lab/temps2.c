//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include<stdio.h>

#define MINDAYS 3
#define MAXDAYS 10
#define MAXTEMP 40
#define MINTEMP -40

int main(void)
{
	int i, days;
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
	}

	printf("\n");

	printf("Day  Hi  Low\n");

	for (i = 0; i < days; i++)
	{
		printf("%d %4d %5d\n", i + 1, highTemp[i], lowTemp[i]);
	}

	return 0;
}
