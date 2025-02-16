//Header File Inclusion
#include "contact.h"
#include<string.h>

//Function Definition
void createContact(AddressBook *addressBook)
{
    Contact *currentcontact = &addressBook->contacts[addressBook->contactCount]; //Local pointer of type Contact
    FILE *file = fopen("contacts.csv", "a"); //Opening File in Append Mode to add new contact 
    if (file == NULL) //File Error handling
    {
        printf("Error opening contacts.csv file!\n");
        return;
    }

    // Enter Name
    printf("Enter name: ");
    scanf(" %[^\n]", currentcontact->name);
    getchar();

    // Phone Number Validation
    int isValidPhone = 0;
    while (!isValidPhone) 
    {
        printf("Enter Phone number: ");
        scanf(" %s", currentcontact->phone);
        getchar();

        // Check if the phone number already exists
        int isDuplicate = 0;
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
            if (strcmp(currentcontact->phone, addressBook->contacts[i].phone) == 0) 
            {
                printf("This contact already exists\n");
                isDuplicate = 1;
                break;
            }
        }

        // If no duplicate, continue to check the phone number
        if (!isDuplicate) 
        {
            int isDigitOnly = 1;
            for (int i = 0; currentcontact->phone[i] != '\0'; i++) 
            {
                if (currentcontact->phone[i] < '0' || currentcontact->phone[i] > '9') 
                {
                    isDigitOnly = 0;
                    break;
                }
            }

            // Check if the phone number is 10 digits and contains only digits
            if (isDigitOnly && strlen(currentcontact->phone) == 10) 
            {
                isValidPhone = 1;
            } 
            else 
            {
                printf("Please enter a valid 10-digit mobile number containing only digits\n"); //Print a Error Message
            }
        }
    }

    // Email Validation
    int isValidEmail = 0;
    while (!isValidEmail) 
    {
        printf("Enter Email Id: ");
        scanf(" %s", currentcontact->email);
        getchar();

        // Check if the email already exists
        int isDuplicateEmail = 0;
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
            if (strcmp(currentcontact->email, addressBook->contacts[i].email) == 0) 
            {
                printf("This email already exists\n");
                isDuplicateEmail = 1;
                break;
            }
        }

        // Check if the email contains only lowercase letters
        int isLowerCase = 1;
        for (int i = 0; currentcontact->email[i] != '\0'; i++) 
        {
            if (currentcontact->email[i] >= 'A' && currentcontact->email[i] <= 'Z') 
            {
                isLowerCase = 0;
                break;
            }
        }

        // Check if the email contains "@" and ".com"
        char *str1 = strstr(currentcontact->email, "@");
        char *str2 = strstr(currentcontact->email, ".com");

        // Ensure the email does not start with '@'
        if (!isDuplicateEmail && isLowerCase && str1 && str2 && currentcontact->email[0] != '@') 
        {
            isValidEmail = 1;
        } 
        else 
        {
            printf("Please enter a valid email id (lowercase, must contain '@' and end with '.com')\n"); //Print a error message
        }
    }

    // Save contact to the file
    fprintf(file, "%s,%s,%s\n", currentcontact->name, currentcontact->phone, currentcontact->email);
    fclose(file);
    addressBook->contactCount++; //Increment contactCount upon one successful contact Inclusion
}