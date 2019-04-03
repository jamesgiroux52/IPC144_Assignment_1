/*
 ============================================================================
 Name        : contacts.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : February 19, 2019 - Assignment 1
 ============================================================================
*/

/*
 ============================================================================
 Description : Structure declarations header file
 ============================================================================
*/


// Structure type Name declaration

struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
struct Address {
	int stNum;
	char street[41];
	int aptNum;
	char pstCode[8];
	char city[41];
};

// Structure type Numbers declaration
struct Numbers {
	char cell[14];
	char home[14];
	char business[14];
};


