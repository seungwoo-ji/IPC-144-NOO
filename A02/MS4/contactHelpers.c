//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Section:        NOO
// Date:           November 20, 2019
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include ctype.h header file to use isdigit for
// getTenDigitPhone function.
#include <ctype.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
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
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
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
	struct Contact contacts[MAXCONTACTS] =
	{
		{
			{ "Rick", {'\0'}, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" }
		},
		{
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" }
		},
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
		{
			{ "Sasha", {'\0'}, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } },
	};

	int option, exit = 0;

	do
	{
		option = menu();

		printf("\n");

		switch (option)
		{
		case 1:

			displayContacts(contacts, MAXCONTACTS);
			pause();

			break;

		case 2:

			addContact(contacts, MAXCONTACTS);
			pause();

			break;

		case 3:

			updateContact(contacts, MAXCONTACTS);
			pause();

			break;

		case 4:

			deleteContact(contacts, MAXCONTACTS);
			pause();

			break;

		case 5:

			searchContacts(contacts, MAXCONTACTS);
			pause();

			break;

		case 6:

			sortContacts(contacts, MAXCONTACTS);
			pause();

			break;

		case 0:

			printf("Exit the program? (Y)es/(N)o: ");

			if (yes())
			{
				exit = 1;
				printf("\nContact Management System: terminated");
			}

			break;
		}

		printf("\n");

	} while (exit == 0);
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int i, count, needInput = 1;

	while (needInput == 1)
	{
		scanf("%10s", phoneNum);
		clearKeyboard();

		count = 0;

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10 )
		{
			// validate entry of 10 decimal digits
			for (i = 0; phoneNum[i] != '\0'; i++)
			{
				if (isdigit(phoneNum[i]) != 0)
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
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, pos = -1;

	for (i = 0; i < size && pos < 0; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			pos = i;
		}
	}

	return pos;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	// display contact full name
	printf(" %s", contact->name.firstName);

	if (strlen(contact->name.middleInitial) != 0)
	{
		printf(" %s", contact->name.middleInitial);
	}

	printf(" %s\n", contact->name.lastName);

	// display contact numbers
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	// display contact address
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

	if (contact->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i, validContacts = 0;

	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			validContacts++;
		}
	}

	displayContactFooter(validContacts);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char cellNumber[11] = { 0 };
	int idx;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	
	idx = findContactIndex(contacts, size, cellNumber);

	if (idx != -1)
	{
		printf("\n");
		
		displayContact(&contacts[idx]);
		
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int emptyIdx;
	char cellNumber[11] = { 0 };

	emptyIdx = findContactIndex(contacts, size, cellNumber);

	if (emptyIdx == -1)
	{
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	else
	{
		getContact(&contacts[emptyIdx]);
		printf("--- New contact added! ---\n\n");
	}
}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	struct Contact emptyContact = { { { 0 } } };
	int idx;
	char cellNumber[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);

	idx = findContactIndex(contacts, size, cellNumber);

	if (idx == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[idx]);

		printf("\n");

		printf("Do you want to update the name? (y or n): ");

		if (yes())
		{
			contacts[idx].name = emptyContact.name;
			getName(&contacts[idx].name);
		}

		printf("Do you want to update the address? (y or n): ");

		if (yes())
		{
			contacts[idx].address = emptyContact.address;
			getAddress(&contacts[idx].address);
		}

		printf("Do you want to update the numbers? (y or n): ");

		if (yes())
		{
			contacts[idx].numbers = emptyContact.numbers;
			getNumbers(&contacts[idx].numbers);
		}

		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	struct Contact emptyContact = { { { 0 } } };
	int idx;
	char cellNumber[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);

	idx = findContactIndex(contacts, size, cellNumber);

	if (idx == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[idx]);

		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
				
		if (yes())
		{
			contacts[idx] = emptyContact;

			printf("--- Contact deleted! ---\n");
		}

		printf("\n");
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j;
	struct Contact temp = { { { 0 } } };

	for (i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0)
			{
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
	}

	printf("--- Contacts sorted! ---\n\n");
}
