/*
    AUTHOR: Rohit Kivanda
    TITLE: Address Book Project
    DESCRIPTION: AddressBook project can list, create, search, edit and deletee conatct.    
    DATE: 22/09/2024
*/

#include "contact.h"
void updateCSV(AddressBook *book);   // Function to update the CSV file with the address book data
int main()
{
    // Variable to store user menu choice
    int choice;

    AddressBook book;// Declaring a variable of type AddressBook
	// Initialize the address book
    initialize(&book);
    
	// Menu loop
    do 
    {
	// Display menu options to the user
	printf("\nAddress Book Menu:\n");  
	printf("1. Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	// Read user choice
	scanf("%d", &choice);

    // Execute corresponding action based on user choice
	switch (choice) 
	{
	    case 1:
		 // Create a new contact
                createContact(&book);
                break;
            case 2:
                // Search for a contact
                searchContact(&book);
                break;
            case 3:
                // Edit an existing contact
                editContact(&book);
                break;
            case 4:
                // Delete a contact
                deleteContact(&book);
                break;
            case 5:
                // List all contacts in the address book
                listContacts(&book);
                break;
            case 6:
                // Exit the program and save changes
                printf("Saving and Exiting...\n");
                updateCSV(&book);
                break;
            default:
                // Handle invalid menu choice
                printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);// Continue until the user chooses to exit

    return 0; // Return success
}

