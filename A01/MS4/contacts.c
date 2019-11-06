//==============================================
// Name:           Seung Woo Ji	
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Date:           November 6, 2019
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
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
		scanf(" %6[^\n]", name.middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name.lastName);
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:




// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:

