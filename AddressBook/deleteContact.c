//Header File Inclusion
#include "contact.h"
#include<string.h>

//Function Definition
void deleteContact(AddressBook *addressBook) 
{
    char str[50];
    int flag = 0;

    printf("Enter Name to be deleted: ");
    scanf(" %[^\n]", str);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        int ret = strcmp(addressBook->contacts[i].name, str);

        if (ret == 0)
        {
            for (int j = i; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            printf("Contact deleted successfully\n"); //Print this message if contact was deleted from contacts array
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        printf("Please enter a valid name.\n"); //Error Handling
    }

    addressBook->contactCount--;
}