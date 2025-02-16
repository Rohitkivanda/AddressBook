//Header File Inclusion
#include "contact.h"
#include<string.h> //for strtok() function


//Print all the contacts present in the AddressBook
void listContacts(AddressBook *addressBook) 
{
    //Print array
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("Name: %s\n", addressBook->contacts[i].name);
        printf("Phone: %s\n", addressBook->contacts[i].phone);
        printf("Email: %s\n", addressBook->contacts[i].email);
        printf("\n");
    }
}

//Function to pullout contacts from contacts.csv & push into contacts array
void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0; //Initializing contactCount to zero -> 0

        
    FILE *file;
    file = fopen("contacts.csv", "r"); //Opening file in read mode
    if (file == NULL)
    {
        printf("Error opening contacts.csv file\n"); //Error Handling
    }
    char buffer[150];
    int i = 0;
    while (fscanf(file, " %[^\n]", buffer) != EOF)
    {
        char *token = strtok(buffer, ","); 
        if (token != NULL)
        {
            strcpy(addressBook->contacts[i].name, token);
            token = strtok(NULL, ",");
        }

        if (token != NULL)
        {
            strcpy(addressBook->contacts[i].phone, token);
            token = strtok(NULL, ",");
        }

        if (token != NULL)
        {
            strcpy(addressBook->contacts[i].email, token);
            token = strtok(NULL, ",");
        }
        i++;
        addressBook->contactCount++; //Inrementing contactCount by 1 after each successful contact addition
    }
    fclose(file);
}