//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Workshop:       3 (in-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>

#define NUMS 4

int main(void)
{
	// Variable section
	int i, invalid = 0, lowTemp, highTemp, lowestDay = 0, highestDay = 0, lowestTemp = 40, highestTemp = -40, totalHigh = 0, totalLow = 0;
	
	// Get low and high temperatures for NUMS days
	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++)
	{
		// Prompt for temperatures and enforce range/values
		do
		{
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);
			printf("\n");

			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);
			printf("\n");

			if (lowTemp < -40 || highTemp <= lowTemp || highTemp > 40)
			{
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
				invalid = 1;
			}
			else
			{						
				invalid = 0;
			}
		} while (invalid == 1);

		// Determine the highest and lowest temperatures/days
		if (highestTemp < highTemp)
		{
			highestTemp = highTemp;
			highestDay = i + 1;
		}

		if (lowestTemp > lowTemp)
		{
			lowestTemp = lowTemp;
			lowestDay = i + 1;
		}

		// Calculate the total temperatures
		totalHigh += highTemp;
		totalLow += lowTemp;
	}

	// Calculate the mean temperatures and lowest/highest temperatures/days
	printf("The average (mean) LOW temperature was: %.2f\n", (float)totalLow / NUMS);

	printf("The average (mean) HIGH temperature was: %.2f\n", (float)totalHigh / NUMS);

	printf("The average (mean) temperature was: %.2f\n", (totalLow + totalHigh) / (2.0f * NUMS));

	printf("The highest temperature was %d, on day %d\n", highestTemp, highestDay);

	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowestDay);
	
	return 0;
}

