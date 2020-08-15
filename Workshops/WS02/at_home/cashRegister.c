//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include <stdio.h>

int main(void)
{
	double damountOwing, GST;
	int coin, iamountOwing;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &damountOwing);

	GST = damountOwing * 0.13;

	printf("GST: %.2lf\n", (double)GST);

	damountOwing += (double)GST;

	printf("Balance owing: $%.2lf\n", damountOwing);

	iamountOwing = damountOwing * 100 + 0.5; // manual rounding from double type to int type

	coin = iamountOwing / 100;
	iamountOwing = iamountOwing % 100;

	printf("Loonies required: %d, balance owing $%.2lf\n", coin, (double)iamountOwing / 100);

	coin = iamountOwing / 25;
	iamountOwing = iamountOwing % 25;

	printf("Quarters required: %d, balance owing $%.2lf\n", coin, (double)iamountOwing / 100);

	coin = iamountOwing / 10;
	iamountOwing = iamountOwing % 10;

	printf("Dimes required: %d, balance owing $%.2lf\n", coin, (double)iamountOwing / 100);

	coin = iamountOwing / 5;
	iamountOwing = iamountOwing % 5;

	printf("Nickels required: %d, balance owing $%.2lf\n", coin, (double)iamountOwing / 100);

	printf("Pennies required: %d, balance owing $0.00\n", iamountOwing);

	return 0;

}

