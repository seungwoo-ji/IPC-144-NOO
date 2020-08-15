//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji@myseneca.ca
// Section:        NOO
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:


#include <stdio.h>

int main(void)
{
	double amountOwing;
	int coin, iamountOwing;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountOwing);

	iamountOwing = amountOwing * 100 + 0.05;

	coin = iamountOwing / 100;
	iamountOwing = iamountOwing % 100;

	printf("Loonies required: %d, balance owing $%.2f\n", coin, (double)iamountOwing / 100);

	coin = iamountOwing / 25;
	iamountOwing = iamountOwing % 25;

	printf("Quarters required: %d, balance owing $%.2f\n", coin, (double)iamountOwing / 100);

	return 0;
}
