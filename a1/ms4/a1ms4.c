/*
 ============================================================================
 Name        : a1ms2.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : February 19, 2019 - Assignment 1 - Milestone 4
 ============================================================================
 */

/*
 ============================================================================
 Description : Contact management system using a single Contact structure that
 	 	 	   contains all name address and numbers structures. Implemented
 	 	 	   functions for get name, get address, get numbers, display contact
 	 	 	   boolean function for optional data and a validate positive number
 	 	 	   for Street number and apartment number.
 ============================================================================
 */

// remove errors scanf() causes in MS VisualStudio
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include header file with structure definitions/declarations
#include "contacts.h"

int main (void){

	//declare and initialize contact structure
	struct Contact contact = {{"", "", ""}, {0, "", 0, "", ""}, {"", "", ""}};

	// Display the title
	printf("Contact Management System\n");
	printf("=========================\n");

	// get name information
	getNameInfo(&contact.name);

	// get address information
	getAddressInfo(&contact.address);

	// get optional phone number information
	getPhoneNumbers(&contact.phone);

	// display information entered Pointer not needed for displaying contact
	dispContact(&contact);

	// Display Completion Message
	printf("\nStructure test for Contact using functions done!\n");

	return 0;
}


