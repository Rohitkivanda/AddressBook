/*
    This Header File all the function prototypes.
*/

#ifndef CONTACT_H
#define CONTACT_H

//Macron 
#define MAX_CONTACTS 100

//Header File Inclusiom
#include <stdio.h>
#include <string.h>

//Struct of alias->Contact
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

//Struct of alias->AddressBook
typedef struct {
    Contact contacts[MAX_CONTACTS]; 
    int contactCount;
} AddressBook;

//Function Prototypes. Seperate .c file created for each function
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void populate(AddressBook *addressBook);

#endif
