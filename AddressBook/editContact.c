//Header File Inclusion
#include "contact.h"
#include<string.h>

/*
    This is the function definition of updateCSV.
    Function helps to overwrite the existing data a ith position
*/
void updateCSV(AddressBook *addressBook)
{
    FILE *file = fopen("contacts.csv", "w"); //Opening file in Write mode
    if (file == NULL)
    {
        printf("Error opening file!\n"); //File Error Handling
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(file, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(file);
}

//Function Definition
void editContact(AddressBook *addressBook) 
{
    int choice;
    char str[50], copy[50];
    int found = 0;

    printf("Search by\n1. Name\n2. Phone\n3. Email\nEnter choice: "); //Prompt
    scanf("%d", &choice); //Choice can have 1, 2, 3

    if (choice == 1)
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", str);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, str) == 0)
            {
                found = 1;
                printf("Do you want to edit\n1. Name\n2. Phone\n3. Email\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Enter new name: ");
                    scanf(" %[^\n]", addressBook->contacts[i].name);
                }

                if (choice == 2)
                {
                    int flag = 0;
                    while (!flag)
                    {
                        printf("Enter new Phone Number: ");
                        scanf(" %[^\n]", copy);

                        //Validation
                        for (int i = 0; i < addressBook->contactCount; i++)
                        {
                            if (!strcmp(addressBook->contacts[i].phone, copy))
                            {
                                printf("Error: Phone Number already exists!\n");
                                flag = 0;
                                break;
                            }

                            strcpy(addressBook->contacts[i].phone, copy);
                            flag = 1;
                        }
                    }
                }

                if (choice == 3)
                {
                    int flag = 0;
                    while (!flag)
                    {
                        printf("Enter new Email Id: ");
                        scanf(" %[^\n]", copy);

                        //Validation
                        for (int i = 0; i < addressBook->contactCount; i++)
                        {
                            if (!strcmp(addressBook->contacts[i].email, copy))
                            {
                                printf("Error: Email Id already exists!\n");
                                flag = 0;
                                break;
                            }

                            
                            strcpy(addressBook->contacts[i].email, copy);
                            flag = 1;
                        }
                    }
                }

                //Printing Updated Details of a contac
                printf("\n<-- Updated Details Below -->\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("\n");

                updateCSV(addressBook);
                break;
            }
        }
        if (!found)
        {
            printf("No contact found with the given name.\n");
        }
    }

    if (choice == 2)
    {
        printf("Enter Phone Number: ");
        scanf(" %[^\n]", str);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, str) == 0)
            {
                found = 1;
                printf("Do you want to edit\n1. Name\n2. Phone\n3. Email\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Enter new name: ");
                    scanf(" %[^\n]", addressBook->contacts[i].name);
                }

                if (choice == 2)
                {
                    int flag = 0;
                    while (!flag)
                    {
                        printf("Enter new Phone Number: ");
                        scanf(" %[^\n]", copy);

                        //Validation
                        for (int i = 0; i < addressBook->contactCount; i++)
                        {
                            if (!strcmp(addressBook->contacts[i].phone, copy))
                            {
                                printf("Error: Phone Number already exists!\n");
                                flag = 0;
                                break;
                            }

                            strcpy(addressBook->contacts[i].phone, copy);
                            flag = 1;
                        }
                    }
                }

                if (choice == 3)
                {
                    int flag = 0;
                    while (!flag)
                    {
                        printf("Enter new Email Id: ");
                        scanf(" %[^\n]", copy);
                        for (int i = 0; i < addressBook->contactCount; i++)
                        {

                            //Validation
                            if (!strcmp(addressBook->contacts[i].email, copy))
                            {
                                printf("Error: Email Id already exists!\n");
                                flag = 0;
                                break;
                            }

                            strcpy(addressBook->contacts[i].email, copy);
                            flag = 1;
                        }
                    }
                }
                
                //Printing Updated Details
                printf("\n<-- Updated Details Below -->\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("\n");

                updateCSV(addressBook);
                break;
            }
        }
        if (!found)
        {
            printf("No contact found with the given phone number.\n");
        }
    }

    if (choice == 3)
    {
        printf("Enter Email Id: ");
        scanf(" %[^\n]", str);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                found = 1;
                printf("Do you want to edit\n1. Name\n2. Phone\n3. Email\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Enter new name: ");
                    scanf(" %[^\n]", addressBook->contacts[i].name);
                }

                if (choice == 2)
                {
                    int flag = 0;
                    while (!flag)
                    {
                        printf("Enter new Phone Number: ");
                        scanf(" %[^\n]", copy);
                        for (int i = 0; i < addressBook->contactCount; i++)
                        {
                            if (!strcmp(addressBook->contacts[i].phone, copy))
                            {
                                printf("Error: Phone Number already exists!\n");
                                flag = 0;
                                break;
                            }

                            strcpy(addressBook->contacts[i].phone, copy);
                            flag = 1;
                        }
                    }
                }

                if (choice == 3)
                {
                    int flag = 0;
                    while (!flag)
                    {
                        printf("Enter new Email Id: ");
                        scanf(" %[^\n]", copy);

                        //Validation
                        for (int i = 0; i < addressBook->contactCount; i++)
                        {
                            if (!strcmp(addressBook->contacts[i].email, copy))
                            {
                                printf("Error: Email Id already exists!\n");
                                flag = 0;
                                break;
                            }

                            strcpy(addressBook->contacts[i].email, copy);
                            flag = 1;
                        }
                    }
                }

                //Printing Updated Details
                printf("\n<-- Updated Details Below -->\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("\n");

                updateCSV(addressBook);
                break;
            }
        }
        if (!found)
        {
            printf("No contact found with the given email.\n");
        }
    }
}

