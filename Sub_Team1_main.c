#include <stdio.h>
#include <stdlib.h>


#define DEPARTMENT  1
#define TITLE  2
#define AUTHOR  3
#define PUBLISHER 4
#define NUMBEROFPAGES 5
#define NUMBEROFBOOKS 6
#define NUMBEROFAVAILABEBOOKS 7
#define NUMBEROFBORROWEDBOOKS 8
#define PRICE  9

#define STOP   0


struct book {
    int ID;
    char Department[30];
    char title[30];
    char author[30];
    char publisher[30];
    int numberOfPages;
    int numberOfBooks;
    int numberOfAvailableBooks;
    int numberOfBorrowedBooks;
    int price;
};

struct Node {
    struct book b;
    struct book *book_ptr;
};

void Add_Book(struct Node **head, struct book new_book) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->b = new_book;
    new_node->book_ptr = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    //4 5 7 10 11
    struct Node *current = *head;
    struct Node *previous = NULL;

    while (current != NULL && current->b.ID < new_book.ID) {
        previous = current;
        current = current->book_ptr;
    }
    if (previous == NULL) {
        new_node->book_ptr = *head;
        *head = new_node;
    } else {
        new_node->book_ptr = current;
        previous->book_ptr = new_node;
    }
}

int Delete_Book(struct Node **head, int Book_ID) {

    if (*head == NULL) {
        return 0;
    }

    struct Node *current = *head;
    struct Node *previous = NULL;

    while (current != NULL && current->b.ID != Book_ID) {
        previous = current;
        current = current->book_ptr;
    }

    if (current == NULL) {
        return 0;
    }

    if (previous == NULL) {
        *head = current->book_ptr;
    } else {
        previous->book_ptr = current->book_ptr;
    }

    free(current);

    return 1;
}


void What_to_edit(struct Node **Book) {

    while (1) {
        printf("choose your thing to be edited\n");
        int choice;
        scanf("%d", &choice);

        if (choice == DEPARTMENT) {
            printf("enter the department\n");
            scanf("%[^\\n]", (*Book)->b.Department);
        } else if (choice == TITLE) {
            printf("enter the title\n");
            scanf("%[^\\n]", (*Book)->b.title);
        } else if (choice == AUTHOR) {
            printf("enter the author\n");
            scanf("%[^\\n]", (*Book)->b.author);
        } else if (choice == PUBLISHER) {
            printf("enter the publisher\n");
            scanf("%[^\\n]", (*Book)->b.publisher);
        } else if (choice == NUMBEROFPAGES) {
            printf("enter the number of pages\n");
            scanf("%d", &(*Book)->b.numberOfPages);
        } else if (choice == NUMBEROFBOOKS) {
            printf("enter the number of books\n");
            scanf("%d", &(*Book)->b.numberOfBooks);
        } else if (choice == NUMBEROFAVAILABEBOOKS) {
            printf("enter the number of available books\n");
            scanf("%d", &(*Book)->b.numberOfAvailableBooks);
        } else if (choice == NUMBEROFBORROWEDBOOKS) {
            printf("enter the number of borrowed books\n");
            scanf("%d", &(*Book)->b.numberOfBorrowedBooks);
        } else if (choice == PRICE) {
            printf("enter the price\n");
            scanf("%d", &(*Book)->b.price);
        } else if (choice == STOP) {
            break;
        } else {
            printf("invalid choice\n");
        }
    }
}


int Edit_Book(struct Node **head, int Book_ID) {
/*
    int choice ;
    scanf("%d",&choice);
*/
    if (*head == NULL) {
        return 0;
    }

    struct Node *current = *head;
    struct Node *previous = NULL;

    while (current != NULL && current->b.ID != Book_ID) {
        previous = current;
        current = current->book_ptr;
    }

    if (current == NULL) {
        return 0;
    }


    What_to_edit(&current);


    return 1;
}

void view_books(struct Node **head) {
    struct Node *p = head;
    while (p != NULL) {
        printf("ID: %d\n", p->b.ID);
        printf("Department: %s\n", p->b.Department);
        printf("Title: %s\n", p->b.title);
        printf("Author: %s\n", p->b.author);
        printf("Publisher: %s\n", p->b.publisher);
        printf("Number of pages: %d\n", p->b.numberOfPages);
        printf("Number of books: %d\n", p->b.numberOfBooks);
        printf("Number of available books: %d\n", p->b.numberOfAvailableBooks);
        printf("Number of borrowed books: %d\n", p->b.numberOfBorrowedBooks);
        printf("Price: %d\n", p->b.price);
        printf("\n");
        p = p->book_ptr;
    }
}


int main() {
    //struct Node* head = (struct Node*) malloc(sizeof(struct Node));

    struct Node *head = NULL;

    // Create some book objects
    struct book b1 = {10, "Computer Science", "The C Programming Language", "Brian Kernighan and Dennis Ritchie",
                      "Prentice Hall", 272, 10, 8, 2, 125};
    struct book b2 = {15, "Mathematics", "Calculus", "Michael Spivak", "Cambridge University Press", 670, 5, 3, 2, 200};
    struct book b3 = {8, "Physics", "The Feynman Lectures on Physics",
                      "Richard Feynman, Robert Leighton and Matthew Sands", "Addison-Wesley", 1552, 3, 1, 2, 500};
    struct book b4 = {1, "Literature", "Nineteen Eighty-Four", "George Orwell", "Secker & Warburg", 328, 9, 7, 1, 150};
    struct book b5 = {110, "History", "The Silk Roads: A New History of the World", "Peter Frankopan",
                      "Bloomsbury Publishing", 656, 8, 6, 1, 250};


    struct book b6 = {17, "Biography", "Becoming", "Michelle Obama", "Crown Publishing Group", 448, 9, 8, 2, 300};
    struct book b7 = {2, "Science Fiction", "Dune", "Frank Herbert", "Chilton Books", 412, 10, 9, 3, 200};
    struct book b8 = {140, "Thriller", "The Girl on the Train", "Paula Hawkins", "Riverhead Books", 336, 7, 5, 2, 150};
    struct book b9 = {19, "Fantasy", "The Name of the Wind", "Patrick Rothfuss", "DAW Books", 662, 9, 7, 2, 175};

    // Add the books to the list
    Add_Book(&head, b1);
    Add_Book(&head, b2);
    Add_Book(&head, b3);
    Add_Book(&head, b4);
    Add_Book(&head, b5);
    view_books(head);
    Delete_Book(&head, 1);
    Add_Book(&head, b6);
    Add_Book(&head, b7);
    Add_Book(&head, b8);
    Add_Book(&head, b9);
    // View the books in the list


    view_books(head);


    return 0;
}