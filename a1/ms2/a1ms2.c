/*
 ============================================================================
 Name        : a1ms2.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : February 19, 2019 - Assignment 1 - Milestone 2
 ============================================================================
 */

/*
 ============================================================================
 Description : Contact management application using structures of strings
 	 	 	   and integers.  Implemented functions for clearing the
 	 	 	   buffer, getting string and number input from user, boolean
 	 	 	   function for optional data entries, and displaying contact
 	 	 	   information.
 ============================================================================
 */

// remove errors scanf() causes in MS VisualStudio
#define _CRT_SECURE_NO_WARNINGS

// standard input output library
#include <stdio.h>

// include header file with structure definitions/declarations and function prototypes
#include "contacts.h"

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// clear input buffer
void clearBuffer(void);

// boolean optional data function
int optionalData(char text[]);

// display contact excluding any values not gathered
void dispContact(struct Name name, struct Address address, struct Numbers phone);

// get textual data from user
void getTextInfo(char contactInfo[], char text[]);

// get numerical data from user
void getPosNumInfo(int *contactInfo, char text[]);


int main (void){

	//declare and initialize structures
	struct Name name;
	name.firstName[0] = '\0';
	name.middleInitial[0] = '\0';
	name.lastName[0] = '\0';

	struct Address address;
	address.city[0] = '\0';
	address.pstCode[0] ='\0';
	address.street[0] = '\0';
	address.aptNum = 0;
	address.stNum = 0;

	struct Numbers phone;
	phone.business[0] = '\0';
	phone.cell[0] = '\0';
	phone.home[0] = '\0';

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// get name information
	getTextInfo(name.firstName, "first name:");
	if (optionalData("middle initial(s)")) {
		getTextInfo(name.middleInitial, "middle initial(s):");
	}
	getTextInfo(name.lastName, "last name:");

	// get address information
	getPosNumInfo(&address.stNum, "street number:");
	getTextInfo(address.street, "street name:");

	if (optionalData("apartment number")){
		getPosNumInfo(&address.aptNum, "apartment number:");
	}
	getTextInfo(address.pstCode, "postal code:");
	getTextInfo(address.city, "city:");

	// get optional phone number information
	if(optionalData("cell phone number")){
		getTextInfo(phone.cell, "cell phone number:");
	}
	if(optionalData("home phone number")){
		getTextInfo(phone.home, "home phone number:");
	}
	if(optionalData("business phone number")){
		getTextInfo(phone.business, "business phone number:");
	}

	// display contact information
	dispContact(name, address, phone);

	// Display Completion Message
	printf("\nStructure test for Name, Address, and Numbers Done!\n");

	return 0;
}

// functions :

// function to clear input buffer
void clearBuffer(void){
	while (getchar() != '\n'){
		;  // empty statement intentional - from IPC144 Notes
	}
	return;
}

// function to get textual information about contact
void getTextInfo(char contactInfo[], char text[]){
	printf("Please enter the contact's %s ", text);
	scanf(" %40[^\n]", contactInfo);
	clearBuffer();
	return;
}

// function to get numerical information about contact
// and verify that it is a positive number
void getPosNumInfo(int *contactInfo, char text[]){
	printf("Please enter the contact's %s ", text);
	scanf(" %d", contactInfo);
	while(*contactInfo < 1){		// verify that the user has entered a positive number
		printf("Error -> Please enter a positive value for %s ", text);
		scanf("%d", contactInfo);
	}
	return;
}

// boolean function to check if user wants to enter an optional field
int optionalData(char text[]){
	int res = -1;
	char choice;

	// formating work around
	if (text[0] == 'a'){ // if requesting 'a'partment number' use 'an' instead of 'a' in the prompt question
		printf("Do you want to enter an %s? (y or n): ", text);
	} else {
		printf("Do you want to enter a %s? (y or n): ", text);
	}

	do {   									// validate that user enters (y or n)
		scanf(" %c", &choice);
		if (choice == 'n' || choice == 'N'){
			res = 0;
		} else if(choice == 'y' || choice == 'Y'){
			res = 1;
		} else {
			printf("Error -> Please enter (y) or (n) to enter optional data for %s: ", text);
		}
	} while (res < 0);

	return res;								// return true/1 for y or Y and return false/0 for n or N
}

// function to display the contact also does not display any optional data not gathered
// and prints a message if no phone numbers were entered
void dispContact(struct Name name, struct Address address, struct Numbers phone){
	printf("\nContact Details\n");
	printf("---------------\n");

	// display name of contact
	printf("Name Details\n");
	printf("First name: %s\n", name.firstName);
	if (*name.middleInitial != '\0'){
		printf("Middle initial(s): %s\n", name.middleInitial);
	}
	printf("Last name: %s\n", name.lastName);

	// display address details
	printf("\nAddress Details\n");
	printf("Street number: %d\n", address.stNum);
	printf("Street name: %s\n", address.street);
	if (address.aptNum != 0){
		printf("Apartment: %d\n", address.aptNum);
	}
	printf("Postal code: %s\n", address.pstCode);
	printf("City: %s\n", address.city);

	// display phone numbers
	int flag = 0;
	printf("\nPhone Numbers:\n");
	if (*phone.cell != '\0'){
		printf("Cell phone number: %s\n", phone.cell);
		flag = 1;
	}
	if (*phone.home != '\0'){
		printf("Home phone number: %s\n", phone.home);
		flag = 1;
	}
	if (*phone.business != '\0'){
		printf("Business phone number: %s\n", phone.business);
		flag = 1;
	}
	if (flag == 0){
		printf("No phone numbers available"); // display message if no numbers were entered
	}
	return;
}


