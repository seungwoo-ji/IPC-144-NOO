//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Date:           November 13, 2019
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	int value;
	char nl;

	do
	{
		scanf("%d%c", &value, &nl);

		if (nl != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}

	} while (nl != '\n');

	return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int value;

	do
	{
		value = getInt();

		if (value < min || value > max)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	
	} while (value < min || value > max);

	return value;
}

// yes function definition goes here:
int yes(void)
{
	int value = -1;
	char option, nl;

	do
	{
		scanf("%c%c", &option, &nl);

		if (nl == '\n')
		{
			if (option == 'Y' || option == 'y')
			{
				value = 1;
			}
			else if (option == 'N' || option == 'n')
			{
				value = 0;
			}
		}
		else if (nl != '\n')
		{
			clearKeyboard();
		}
		if (value == -1)
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	
	} while (value < 0);

	return value;
}

// menu function definition goes here:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");

	printf("Select an option:> ");
	
	return getIntInRange(0, 6);
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int option, exit = 0;

	do
	{
		option = menu();

		printf("\n");

		switch (option)
		{
		case 1:

			printf("<<< Feature 1 is unavailable >>>\n\n");
			pause();

			break;

		case 2:

			printf("<<< Feature 2 is unavailable >>>\n\n");
			pause();

			break;

		case 3:

			printf("<<< Feature 3 is unavailable >>>\n\n");
			pause();

			break;

		case 4:

			printf("<<< Feature 4 is unavailable >>>\n\n");
			pause();

			break;

		case 5:

			printf("<<< Feature 5 is unavailable >>>\n\n");
			pause();

			break;

		case 6:

			printf("<<< Feature 6 is unavailable >>>\n\n");
			pause();

			break;

		case 0:

			printf("Exit the program? (Y)es/(N)o: ");
			exit = yes();

			if (exit == 1)
			{
				printf("\nContact Management System: terminated");
			}

			break;
		}

		printf("\n");

	} while (exit == 0);
}