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
 Description : Structure declarations and function prototypes header file
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
	char cell[15];
	char home[15];			// I added a few more memory locations for inputs like
	char business[15];		// 905-123-1234 or (905) 123-4567
};

// Structure type Contact declaration
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers phone;
};


//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// clear input buffer used in getTextInfo to clear any whitespace or random characters
void clearBuffer(void);

// boolean optional data function
int optionalData(char text[]);

// display contact excluding any values not gathered
void dispContact(const struct Contact *contact);

// validate that number entered is positive
void valPos(int *num, char text[]);

// Get and store from standard input the values for Name
void getNameInfo(struct Name *name);

// Get and store from standard input the values for Address
void getAddressInfo(struct Address *address);

// Get and store from standard input the values for Numbers
void getPhoneNumbers(struct Numbers *phone);


