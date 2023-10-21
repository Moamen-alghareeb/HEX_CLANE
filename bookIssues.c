#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#inlcude "books.h";
#define NOK 0
#define OK 1



struct book
{
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

struct Node
{
    struct book b;
    struct book* book_ptr;
};

typedef struct student
{
	char name[30];		
	char issuedBookTitle[30];
    int ID;
	int issuedBookID;

}student_t;

typedef struct Student_Node
{
    struct student s;
    struct student *student_ptr;
}Student_Node_t;

void Add_Student(struct Student_Node **head, struct student new_student) {
    struct Student_Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->s = new_student;
    new_node->student_ptr = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    //4 5 7 10 11
    struct Student_Node *current = *head;
    struct Student_Node *previous = NULL;

    while (current != NULL && current->s.ID < new_student.ID) {
        previous = current;
        current = current->student_ptr;
    }
    if (previous == NULL) {
        new_node->student_ptr = *head;
        *head = new_node;
    } else {
        new_node->student_ptr = current;
        previous->student_ptr = new_node;
    }
}


void issue_book(struct Node** head,)
{
    char ret = 0;
    struct book c1;
    char Criteria_for_search =0;
    while (Criteria_for_search != 6){
        printf("\t\tSelect Criteria(s) for search\n**************************************************\n1) Department\n2) Title\n3) Author\n4) Publisher\n5) Price\n\t\t\t\t\t\t\6) Confirm Search\n Your entry No. is:");
        scanf("%d",&Criteria_for_search);
        printf("\nYour entry :");
        switch(Criteria_for_search){
            case 1: scanf("%s",&c1.ID);break;
            case 2: scanf("%s",&c1.title);break;
        }
        system("cls");
    }
    struct Node* p = head;
    system("cls");
    while (p != NULL)
    {
        if( !strcmp(c1.ID , p->b.ID) || !strcmp(c1.title , p->b.title))
        {
			if((p->b.numberOfBooks) > (p->b.numberOfBorrowedBooks))
			{
				p->b.numberOfAvailableBooks = (p->b.numberOfBooks) - (b.numberOfBorrowedBooks);
				p->b.numberOfBorrowedBooks +=1;
				
			}
/*            printf("ID: %d\n", p->b.ID);
            printf("Department: %s\n", p->b.Department);
            printf("Title: %s\n", p->b.title);
            printf("Author: %s\n", p->b.author);
            printf("Publisher: %s\n", p->b.publisher);
            printf("Number of pages: %d\n", p->b.numberOfPages);
            printf("Number of books: %d\n", p->b.numberOfBooks);
            printf("Number of available books: %d\n", p->b.numberOfAvailableBooks);
            printf("Number of borrowed books: %d\n", p->b.numberOfBorrowedBooks);
            printf("Price: %d\n", p->b.price);
			*/
        }
        p = p->book_ptr;
    }

	
	
	
/***********************************
    char Flag =0;
    int id;
    printf("\n\t\tPlease Enter Book ID: ");
    scanf("%d",&id);
    struct Node* p = head;
    while (p != NULL && Flag == 0)
    {

        if(p->b.ID == id)
        {
            system ("cls");
            Flag =1;
			
			if( ((p->numberOfBooks) > (p->b.numberOfBorrowedBooks)) )
			{
				
			}
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
            printf("\t\t\t\t\t\t\R)Return");
        }
        p = p->book_ptr;
    }
    if (Flag == 0){
        system ("cls");
        printf("\n\t\t\t\tBook ID No: %d is not Found", id);
        delay(10000);
    }
    else{

        Return();
    }	
	*/
}