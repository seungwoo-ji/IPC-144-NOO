//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Date:           November 20, 2019
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
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

// getIntInRange:
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

// yes:
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
		else
		{
			clearKeyboard();
		}
		
		if (value == -1)
		{
			printf(">*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}

	} while (value < 0);

	return value;
}

// menu:
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

// contactManagerSystem:
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

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
	int i, count = 0, needInput = 1;

	while (needInput == 1)
	{
		scanf("%10s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
		{
			for (i = 0; i < 10; i++)
			{
				if (phoneNum[i] >= '0' && phoneNum[i] <= '9')
				{
					count++;
				}
			}
		}
		if (count == 10)
		{
			needInput = 0;
		}
		else
		{
			count = 0;
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{

}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{

}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{

}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{

}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{

}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{

}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{

}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{

}