#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*help*/

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

struct Node* head = NULL;

int x = 0;
void DeleteBook()
{
    x=1;
}


const char Password[6]= {'1','2','3','4','5','6'};

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

void Add_Book(struct Node** head, struct book new_book)
{

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->b = new_book;
    new_node->book_ptr = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    //4 5 7 10 11
    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current != NULL && current->b.ID < new_book.ID)
    {
        previous = current;
        current = current->book_ptr;
    }
    if (previous == NULL)
    {
        new_node->book_ptr = *head;
        *head = new_node;
    }
    else
    {
        new_node->book_ptr = current;
        previous->book_ptr = new_node;
    }
}
void view_books(struct Node** head)
{
    struct Node* p = head;
    while (p != NULL)
    {

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

void MainMenu()
{
    system ("cls");
    while(1)
    {

        char Choise = 0;
        printf("\t\t\t\tMain Menu\n*****************************************************************************\n");
        printf("1) Add Book\n2) Delete Book\n3) Search Book\n4) Get Data\n5) Issue Book\n6) Issue Book\n7) View Issued Books\n8) Student Issue Record\n");
        scanf("%d",&Choise);
        switch(Choise)
        {
        case 1:
            system ("cls");
            DeleteBook();
            break;
        case 2:
            system ("cls");
            DeleteBook();
            break;
        case 3:
            system ("cls");
            SearchBook(head);
            break;
        case 4:
            system ("cls");
            GetData(head);
            system ("cls");
            break;
        case 5:
            system ("cls");
            DeleteBook();
            break;
        case 6:
            system ("cls");
            DeleteBook();
            break;
        case 7:
            system ("cls");
            DeleteBook();
            break;
        case 8:
            system ("cls");
            DeleteBook();
            break;
        default:
            system ("cls");
            printf("\t\t\t***********************\n\t\t\t*Wrong Entry Try Again*\n\t\t\t***********************\n");
        }
    }
}

void PassWord()
{

    char Flag = 0;
    char No_of_tries = 0;
    char* MainPassword = &Password;
    char Password_Entry[20] = {'0'};



    while (No_of_tries <= 2)
    {
        if (Flag  == 1 )
        {
            system("cls");
            printf("\t\t\t\t    Wrong Password\n\t\t\t\tTrails Remaining = %d\n",(3-No_of_tries));
        }
        printf("\n\t\t\tPlease Enter 6-Digit Password: ");
        scanf("%s", &Password_Entry);
        for (int i = 0; i < 6 ; i++)
        {
            Flag = 0;
            if(Password_Entry[i] != *MainPassword)
            {
                Flag = 1;
                No_of_tries++;
                break;


            }
            else
            {
               NULL;
            }
            MainPassword++;
        }
        if(Flag == 0)
        {
            MainMenu();
        }
        else
        {
            MainPassword = &Password;
        }
    }
    exit(0);
}

void GetData(struct Node** head)
{
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
}

void Return(){
    char Ret = 1;
    while(Ret == 1){
        Ret=0;
        scanf("%d",&Ret);
    }
    MainMenu();
}


void SearchBook(struct Node** head){
    char ret = 0;
    struct book c1;
    char Criteria_for_search =0;
    while (Criteria_for_search != 6){
        printf("\t\tSelect Criteria(s) for search\n**************************************************\n1) Department\n2) Title\n3) Author\n4) Publisher\n5) Price\n\t\t\t\t\t\t\6) Confirm Search\n Your entry No. is:");
        scanf("%d",&Criteria_for_search);
        printf("\nYour entry :");
        switch(Criteria_for_search){
            case 1: scanf("%s",&c1.Department);break;
            case 2: scanf("%s",&c1.title);break;
            case 3: scanf("%s",&c1.author);break;
            case 4: scanf("%s",&c1.publisher);break;
            case 5: scanf("%d",&c1.price);break;
        }
        system("cls");
    }
    struct Node* p = head;
    system("cls");
    while (p != NULL)
    {
        if( !strcmp(c1.Department , p->b.Department) || !strcmp(c1.title , p->b.title) || !strcmp(c1.author , p->b.author) || !strcmp(c1.publisher , p->b.publisher) || (c1.price == p->b.price))
        {
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
        }
        p = p->book_ptr;
    }
    printf("\t\t\t\t\t\t\t\t\t1)Return");
    Return();
}
void main()
{

    // Create some book objects
    struct book b1 = {7, "ComputerScience", "The C Programming Language", "Brian Kernighan and Dennis Ritchie", "Prentice Hall", 272, 10, 8, 2,125};
    struct book b2 = {5, "Mathematics", "Calculus", "Michael Spivak", "Cambridge University Press", 670, 5, 3, 2,200};
    struct book b3 = {8, "Physics", "The Feynman Lectures on Physics", "Richard Feynman, Robert Leighton and Matthew Sands", "Addison-Wesley", 1552, 3, 1, 2,500};

    // Add the books to the list
    Add_Book(&head, b1);
    Add_Book(&head, b2);
    Add_Book(&head, b3);

    PassWord();
    return 0;
}


