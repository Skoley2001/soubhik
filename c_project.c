#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
    int book_id;
    char book_name[100];
    char author[50];
    float price;
    struct Book *next;
};
struct Book* createBook(int id, char name[], char author[], float price) {
    struct Book *newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->book_id = id;
    strcpy(newBook->book_name, name);
    strcpy(newBook->author, author);
    newBook->price = price;
    newBook->next = NULL;
    return newBook;
}
void display(struct Book *head) {
    struct Book *temp = head;
    while (temp != NULL) {
        printf("Book ID: %d, Name: %s, Author: %s, Price: %.2f\n", temp->book_id, temp->book_name, temp->author, temp->price);
        temp = temp->next;
    }
}

struct Book* insertAtBeginning(struct Book *head, struct Book *newBook) {
    newBook->next = head;
    return newBook;
}

struct Book* insertAtEnd(struct Book *head, struct Book *newBook) {
    if (head == NULL) {
        return newBook;
    }

    struct Book *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newBook;
    return head;
}

struct Book* insertInMiddle(struct Book *head, int position, struct Book *newBook) {
    if (position <= 1) {
        newBook->next = head;
        return newBook;
    }

    struct Book *temp = head;
    int count = 1;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position. Insertion at the end.\n");
        return insertAtEnd(head, newBook);
    }

    newBook->next = temp->next;
    temp->next = newBook;
    return head;
}

struct Book* deleteFromBeginning(struct Book *head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Book *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Book* deleteFromEnd(struct Book *head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Book *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Book* deleteFromMiddle(struct Book *head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (position <= 1) {
        struct Book *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Book *temp = head;
    int count = 1;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position. Nothing to delete.\n");
        return head;
    }

    struct Book *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return head;
}
void modifyRecord(struct Book *head, int id) {
    struct Book *temp = head;
    while (temp != NULL) {
        if (temp->book_id == id) {
            printf("Enter new book name: ");
            scanf("%s", temp->book_name);

            printf("Enter new author name: ");
            scanf("%s", temp->author);

            printf("Enter new price: ");
            scanf("%f", &temp->price);

            printf("Record modified successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

void searchByID(struct Book *head, int id) {
    struct Book *temp = head;
    while (temp != NULL) {
        if (temp->book_id == id) {
            printf("Book ID: %d, Name: %s, Author: %s, Price: %.2f\n", temp->book_id, temp->book_name, temp->author, temp->price);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

void searchByName(struct Book *head, char name[]) {
    struct Book *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->book_name, name) == 0) {
            printf("Book ID: %d, Name: %s, Author: %s, Price: %.2f\n", temp->book_id, temp->book_name, temp->author, temp->price);
            return;
        }
        temp = temp->next;
    }
    printf("Book with name %s not found.\n", name);
}

void freeList(struct Book *head) {
    struct Book *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Book *head = NULL;
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Create a New Book\n");
        printf("2. Display all books\n");
        printf("3. Insert at First\n");
        printf("4. Insert at Last\n");
        printf("5. Insert in Middle\n");
        printf("6. Delete from First\n");
        printf("7. Delete from Last\n");
        printf("8. Delete from Middle\n");
        printf("9. Modify a record\n");
        printf("10. Search by book ID\n");
        printf("11. Search by book name\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id;
                char name[100], author[50];
                float price;
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book name: ");
                scanf("%s", name);
                printf("Enter author name: ");
                scanf("%s", author);
                printf("Enter price: ");
                scanf("%f", &price);

                struct Book *newBook = createBook(id, name, author, price);
                head = insertAtEnd(head, newBook);
                break;
            }
            case 2:
                display(head);
                break;
            case 3: {
                int id;
                char name[100], author[50];
                float price;
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book name: ");
                scanf("%s", name);
                printf("Enter author name: ");
                scanf("%s", author);
                printf("Enter price: ");
                scanf("%f", &price);

                struct Book *newBook = createBook(id, name, author, price);
                head = insertAtBeginning(head, newBook);
                break;
            }
            case 4: {
                int id;
                char name[100], author[50];
                float price;
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book name: ");
                scanf("%s", name);
                printf("Enter author name: ");
                scanf("%s", author);
                printf("Enter price: ");
                scanf("%f", &price);

                struct Book *newBook = createBook(id, name, author, price);
                head = insertAtEnd(head, newBook);
                break;
            }
            case 5: {
                int id, position;
                char name[100], author[50];
                float price;
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book name: ");
                scanf("%s", name);
                printf("Enter author name: ");
                scanf("%s", author);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter position: ");
                scanf("%d", &position);

                struct Book *newBook = createBook(id, name, author, price);
                head = insertInMiddle(head, position, newBook);
                break;
            }
            case 6:
                head = deleteFromBeginning(head);
                break;
            case 7:
                head = deleteFromEnd(head);
                break;
            case 8: {
                int position;
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromMiddle(head, position);
                break;
            }
            case 9: {
                int id;
                printf("Enter book ID to modify: ");
                scanf("%d", &id);
                modifyRecord(head, id);
                break;
            }
            case 10: {
                int id;
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                searchByID(head, id);
                break;
            }
            case 11: {
                char name[100];
                printf("Enter book name to search: ");
                scanf("%s", name);
                searchByName(head, name);
                break;
            }
            case 12:
                freeList(head);
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 12);

    return 0;
}
