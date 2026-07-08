#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[MAX];
int count = 0;

// Add Contact
void addContact()
{
    printf("\nEnter Name: ");
    scanf(" %[^\n]", contacts[count].name);

    printf("Enter Phone: ");
    scanf("%s", contacts[count].phone);

    printf("Enter Email: ");
    scanf("%s", contacts[count].email);

    count++;

    printf("\nContact Added Successfully!\n");
}

// Display Contacts
void displayContacts()
{
    if(count == 0)
    {
        printf("\nNo Contacts Found!\n");
        return;
    }

    printf("\n===== CONTACT LIST =====\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nContact %d\n", i + 1);
        printf("Name  : %s\n", contacts[i].name);
        printf("Phone : %s\n", contacts[i].phone);
        printf("Email : %s\n", contacts[i].email);
    }
}

// Search Contact
void searchContact()
{
    char searchName[50];
    int found = 0;

    printf("\nEnter Name to Search: ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(contacts[i].name, searchName) == 0)
        {
            printf("\nContact Found!\n");
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("Email : %s\n", contacts[i].email);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nContact Not Found!\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n==============================");
        printf("\n CONTACT MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Contact");
        printf("\n2. Display Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}