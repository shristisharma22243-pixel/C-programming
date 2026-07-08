#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Book books[100];
int count = 0;

void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    getchar();

    printf("Enter Book Title: ");
    fgets(books[count].title, sizeof(books[count].title), stdin);
    books[count].title[strcspn(books[count].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(books[count].author, sizeof(books[count].author), stdin);
    books[count].author[strcspn(books[count].author, "\n")] = '\0';

    count++;

    printf("\nBook Added Successfully!\n");
}

void displayBooks() {
    if (count == 0) {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\n========== Library Books ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Book ID : %d\n", books[i].id);
        printf("Title   : %s\n", books[i].title);
        printf("Author  : %s\n", books[i].author);
    }
}

void searchBook() {
    int id, found = 0;

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!\n");
            printf("Book ID : %d\n", books[i].id);
            printf("Title   : %s\n", books[i].title);
            printf("Author  : %s\n", books[i].author);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook Not Found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("      LIBRARY MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("====================================\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                printf("\nThank You for Using Library Management System!\n");
                return 0;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }

    return 0;
}