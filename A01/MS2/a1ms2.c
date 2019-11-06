//==============================================
// Name:           Seung Woo Ji	
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Date:           October 30, 2019
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name name = { { 0 } };
	struct Address address = { 0 };
	struct Numbers phoneNum = { { 0 } };

	char option;

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name.middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &address.streetNumber);

	while (address.streetNumber <= 0)
	{
		printf("Please enter the number greater than 0 : ");
		scanf("%d", &address.streetNumber);
	}

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &address.apartmentNumber);

		while (address.apartmentNumber <= 0)
		{
			printf("Please enter the number greater than 0 : ");
			scanf("%d", &address.apartmentNumber);
		}
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address.postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address.city);

	// Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf(" %10[^\n]", phoneNum.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's home phone number: ");
		scanf(" %10[^\n]", phoneNum.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &option);

	if (option != 'n' && option != 'N')
	{
		printf("Please enter the contact's business phone number: ");
		scanf(" %10[^\n]", phoneNum.business);
	}

	printf("\n");

	// Display Contact Summary Details
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details:\n");
	printf("First name: %s\n", name.firstName);

	if (name.middleInitial[0] != 0)
	{
		printf("Middle initial(s): %s\n", name.middleInitial);
	}

	printf("Last name: %s\n", name.lastName);

	printf("\n");

	printf("Address Details:\n");
	printf("Street number: %d\n", address.streetNumber);
	printf("Street name: %s\n", address.street);

	if (address.apartmentNumber > 0)
	{
		printf("Apartment: %d\n", address.apartmentNumber);
	}

	printf("Postal code: %s\n", address.postalCode);
	printf("City: %s\n", address.city);

	printf("\n");

	printf("Phone Numbers:\n");

	if (phoneNum.cell[0] != '\0')
	{
		printf("Cell phone number: %s\n", phoneNum.cell);
	}

	if (phoneNum.home[0] != '\0')
	{
		printf("Home phone number: %s\n", phoneNum.home);
	}

	if (phoneNum.business[0] != '\0')
	{
		printf("Business phone number: %s\n", phoneNum.business);
	}

	printf("\n");

	// Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:

	Contact Management System
	-------------------------
	Please enter the contact's first name: Tom
	Do you want to enter a middle initial(s)? (y or n): y
	Please enter the contact's middle initial(s): L. A.
	Please enter the contact's last name: Wong Song
	Please enter the contact's street number: 20
	Please enter the contact's street name: Keele Street
	Do you want to enter an apartment number? (y or n): y
	Please enter the contact's apartment number: 40
	Please enter the contact's postal code: A8A 4J4
	Please enter the contact's city: North York
	Do you want to enter a cell phone number? (y or n): Y
	Please enter the contact's cell phone number: 9051116666
	Do you want to enter a home phone number? (y or n): Y
	Please enter the contact's home phone number: 7052227777
	Do you want to enter a business phone number? (y or n): Y
	Please enter the contact's business phone number: 4163338888

	Contact Details
	---------------
	Name Details
	First name: Tom
	Middle initial(s): L. A.
	Last name: Wong Song

	Address Details
	Street number: 20
	Street name: Keele Street
	Apartment: 40
	Postal code: A8A 4J4
	City: North York

	Phone Numbers:
	Cell phone number: 9051116666
	Home phone number: 7052227777
	Business phone number: 4163338888

	Structure test for Name, Address, and Numbers Done!
*/