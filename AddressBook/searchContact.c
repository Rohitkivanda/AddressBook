//Header File Inclusion
#include "contact.h"
#include<string.h>

//Function Definition
void searchContact(AddressBook *addressBook) 
{
    int choice;
    char str[50];

    printf("Search by\n1. Name\n2. Phone\n3. Email\nEnter choice: "); //Prompt
    scanf("%d", &choice); //Choice can have 3 values 1, 2, 3
    if (choice == 1)
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", str);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            int ret = strcmp(addressBook->contacts[i].name, str);

            if (ret == 0)
            {
                //Print details of ith contact if contact matches
                printf("\n<-- Details Below -->\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("\n");
                break;
            }
        }
    }

    if (choice == 2)
    {
        printf("Enter Phone: ");
        scanf(" %[^\n]", str);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            int ret = strcmp(addressBook->contacts[i].phone, str);

            if (ret == 0)
            {
                //Print details of ith contact if contact matches
                printf("\n<-- Details Below -->\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("\n");
                break;
            }
        }
    }

    if (choice == 3)
    {
        printf("Enter Email: ");
        scanf(" %[^\n]", str);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            int ret = strcmp(addressBook->contacts[i].email, str);

            if (ret == 0)
            {
                //Print details of ith contact if contact matches
                printf("\n<-- Details Below -->\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("\n");
                break;
            }
        }
    }
}