#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int book_id;
    char book_name[50];
    char auth_name[50];
    char publication[50];
    int edition;
    char date_issue[20];
    char isbn_no[15];
    struct Book *next;
};

struct Book *head = NULL;

struct Book *createNode(int id, char name[], char auth[], char pub[], int edition, char date[], char isbn[]) {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newBook->book_id = id;
    strcpy(newBook->book_name, name);
    strcpy(newBook->auth_name, auth);
    strcpy(newBook->publication, pub);
    newBook->edition = edition;
    strcpy(newBook->date_issue, date);
    strcpy(newBook->isbn_no, isbn);
    newBook->next = NULL;
    return newBook;
}

void insertAtBeginning(int id, char name[], char auth[], char pub[], int edition, char date[], char isbn[]) {
    struct Book *newBook = createNode(id, name, auth, pub, edition, date, isbn);
    newBook->next = head;
    head = newBook;
    printf("Book inserted at the beginning of the list.\n");
}

void insertAtEnd(int id, char name[], char auth[], char pub[], int edition, char date[], char isbn[]) {
    struct Book *newBook = createNode(id, name, auth, pub, edition, date, isbn);
    if (head == NULL) {
        head = newBook;
        printf("Book inserted at the end of the list.\n");
        return;
    }
    struct Book *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBook;
    printf("Book inserted at the end of the list.\n");
}

void displayBooks() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Book *temp = head;
    printf("Book records:\n");
    while (temp != NULL) {
        printf("Book ID: %d\nBook Name: %s\nAuthor: %s\nPublication: %s\nEdition: %d\nDate of Issue: %s\nISBN: %s\n\n",
               temp->book_id, temp->book_name, temp->auth_name, temp->publication, temp->edition, temp->date_issue, temp->isbn_no);
        temp = temp->next;
    }
}

void searchById(int id) {
    struct Book *temp = head;
    while (temp != NULL) {
        if (temp->book_id == id) {
            printf("Book found!\nBook ID: %d\nBook Name: %s\nAuthor: %s\nPublication: %s\nEdition: %d\nDate of Issue: %s\nISBN: %s\n",
                   temp->book_id, temp->book_name, temp->auth_name, temp->publication, temp->edition, temp->date_issue, temp->isbn_no);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}
void addBook() {
    int id, edition;
    char name[50], auth[50], pub[50], date[20], isbn[15];

    printf("Enter Book ID: ");
    scanf("%d", &id);
    printf("Enter Book Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Author's Name: ");
    scanf(" %[^\n]", auth);
    printf("Enter Publication: ");
    scanf(" %[^\n]", pub);
    printf("Enter Edition: ");
    scanf("%d", &edition);
    printf("Enter Date of Issue: ");
    scanf(" %[^\n]", date);
    printf("Enter ISBN: ");
    scanf(" %[^\n]", isbn);
    insertAtEnd(id, name, auth, pub, edition, date, isbn);
}


int main() {


    int choice, bookID;
    char bookName[50];

    do {
        printf("\nMenu:\n1. Display Book\n2. Search by Book ID\n3. Insert Book\n4. Modify Book Record\n5. Delete Book Record\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks();
                break;
            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &bookID);
                searchById(bookID);
                break;
            case 3:
                addBook();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (1);

    return 0;
}