//==============================================
// Name:           Seung Woo Ji	
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Date:           November 13, 2019  
//==============================================
// Assignment:     2
// Milestone:      1
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
{
	char option;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);

}

// getAddress:
void getAddress(struct Address* address)
{
	char option;

	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);

	while (address->streetNumber <= 0)
	{
		printf("Please enter the number greater than 0 : ");
		scanf("%d", &address->streetNumber);
	}

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &address->apartmentNumber);

		while (address->apartmentNumber <= 0)
		{
			printf("Please enter the number greater than 0 : ");
			scanf("%d", &address->apartmentNumber);
		}
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);

}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
	char option;

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf(" %10[^\n]", numbers->cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's home phone number: ");
		scanf(" %10[^\n]", numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's business phone number: ");
		scanf(" %10[^\n]", numbers->business);
	}
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact)
{

}