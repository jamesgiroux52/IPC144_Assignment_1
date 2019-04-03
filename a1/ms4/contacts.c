/*
 ============================================================================
 Name        : contacts.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section	 : SJJ
 Date        : March 3, 2019 - Assignment 1 - Milestone 4
 ============================================================================
*/

/*
 ============================================================================
 Description : Function definitions for contact management system
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

//------------------
// functions :
//------------------

// function to clear input buffer
void clearBuffer(void){
	while (getchar() != '\n'){
		;  // empty statement intentional - from IPC144 Notes
	}
	return;
}

// boolean function to check if user wants to enter an optional field
// text for option is passed into text[]
int optionalData(char text[]){
	int res = -1;
	char choice;

	// formatting work around for 'a'partment number prompt question ask with 'an' as opposed to 'a'
	if (text[0] == 'a'){
		printf("Do you want to enter an %s? (y or n): ", text);
	} else {
		printf("Do you want to enter a %s? (y or n): ", text);
	}

	do {   									// validate that user enters (y or n) or (Y or N)
		scanf(" %c", &choice);
		if (choice == 'n' || choice == 'N'){
			res = 0;
		} else if(choice == 'y' || choice == 'Y'){
			res = 1;
		} else {
			printf("Please enter only (y) or (n) to enter optional data for %s: ", text);
		}
	} while (res < 0);
	// return true/1 for y or Y (get optional data)
	return res;	// and return false/0 for n or N (do not get optional data)
}

// function to display the contact also does not display any optional data not gathered
// and prints a message if no phone numbers were entered
void dispContact(const struct Contact *contact){
	printf("\nContact Details\n");
	printf("===============\n");

	// display name of contact
	printf("Name Details\n");
	printf("------------\n");
	printf("First name: %s\n", contact->name.firstName);
	if (contact->name.middleInitial[0] != '\0'){
		printf("Middle initial(s): %s\n", contact->name.middleInitial);
	}
	printf("Last name: %s\n", contact->name.lastName);

	// display address details
	printf("\nAddress Details\n");
	printf("---------------\n");
	printf("Street number: %d\n", contact->address.stNum);
	printf("Street name: %s\n", contact->address.street);
	if (contact->address.aptNum != 0){
		printf("Apartment: %d\n", contact->address.aptNum);
	}
	printf("Postal code: %s\n", contact->address.pstCode);
	printf("City: %s\n", contact->address.city);

	// display phone numbers
	int flag = 0;
	printf("\nPhone Numbers\n");
	printf("-------------\n");
	if (*contact->phone.cell != '\0'){
		printf("Cell phone number: %s\n", contact->phone.cell);
		flag = 1;
	}
	if (*contact->phone.home != '\0'){
		printf("Home phone number: %s\n", contact->phone.home);
		flag = 1;
	}
	if (*contact->phone.business != '\0'){
		printf("Business phone number: %s\n", contact->phone.business);
		flag = 1;
	}
	if (flag == 0){
		printf("No phone numbers available\n");
	}
	return;
}

void valPos(int *num, char text[]){
	while(*num < 1){									// ensure that user has entered a positive number
		printf("Please enter a positive value for contact's %s: ", text);
		scanf("%d", num);
	}
	return;
}

/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  MS4 FUnctions /////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// get the name information about contact
void getNameInfo(struct Name *name){


	printf("Please enter the contact's first name: ");					// " %30[^\n]" means get up to 30 character and
	scanf(" %30[^\n]", name->firstName);						// don't store until user hits enter (i.e. \n)


	if (optionalData("middle initial(s)")){								// boolean function checks if the user wants to
		printf("Please enter the contact's middle initial(s): ");				// enter optional data
		scanf(" %6[^\n]", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);

	return;
}


// get the address information about contact
void getAddressInfo(struct Address *address){
	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf(" %d", &address->stNum);
	valPos(&address->stNum, "street number");

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);

	if (optionalData("apartment number")){								// optionalData is described in getNameInfo
		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &address->aptNum);
		valPos(&address->aptNum, "apartment number");
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->pstCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);

	return;
}

// get the contacts phone numbers
void getPhoneNumbers(struct Numbers *phone){

	if(optionalData("cell phone number")){										// optionalData is described in getNameInfo
		printf("Please enter the contact's cell phone number: ");
		scanf(" %14[^\n]", phone->cell);
	}
	clearBuffer();
	if(optionalData("home phone number")){
		printf("Please enter the contact's home phone number: ");
		scanf(" %14[^\n]", phone->home);
	}
	clearBuffer();
	if(optionalData("business phone number")){
		printf("Please enter the contact's business phone number: ");
		scanf(" %14[^\n]", phone->business);
	}
	clearBuffer();

	return;
}
