/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Book
{
	char title[50];
	char serial[50];
	char sub[50];
	bool issued;
	struct Book* nxt;
};

struct Subscriber
{
	char name[50];
	char title[5][50];
	char date[5][20];
	int books;
	struct Subscriber* nxt;
};

struct Book* book_head = NULL;
struct Subscriber* sub_head = NULL;

void push_book(struct Book** head)
{
	struct Book* nitm = (struct Book*) malloc(sizeof(struct Book));
	char name[50], id[50];
	printf("\n Enter the book name - ");
	scanf("%s", &name);
	printf("\n Enter the ID - ");
	scanf("%s", &id);
	strcpy(nitm -> title, name);
	strcpy(nitm -> serial, id);
	nitm -> issued = false;
	strcpy(nitm -> sub, "");
	(*head) = nitm;
}

void push_sub(struct Subscriber** head)
{
	struct Subscriber* nitm = (struct Subscriber*) malloc(sizeof(struct Subscriber));
	char name[50];
	printf("\n Enter the subscriber name - ");
	scanf("%s", &name);
	strcpy(nitm -> name, name);
	nitm -> books = 0;
	(*head) = nitm;
}

bool booksearch(struct Book** head, char x[50])
{
    if (*head == NULL)
        return false;
      
    if (strcmp((*head) -> title, x) == 0)
        return true;
  
    return booksearch((*head) -> nxt, x);
}

bool subsearch(struct Subscriber** head, char x[50])
{
    if (*head == NULL)
        return false;
      
    if (strcmp((*head) -> name, x) == 0)
        return true;
  
    return subsearch((*head) -> nxt, x);
}

void bookissuestatus(struct Book** head, char x[50], char y[50])
{
	struct Book* tmp = *head;
	
	while(tmp -> title != x)
	{
		tmp = tmp -> nxt;
	}
	
	strcpy(tmp -> sub, y);
	tmp -> issued = true;
}

void subissuestatus(struct Subscriber** head, char x[50], char y[50], char z[50])
{
	struct Subscriber* tmp = *head;
	
	while(tmp -> name != y)
	{
		tmp = tmp -> nxt;
	}
	
	strcpy(tmp -> title[tmp -> books], x);
	strcpy(tmp -> date[tmp -> books], z);
	tmp -> books = tmp -> books + 1;
}

void bookreturnstatus(struct Book** head, char x[50])
{
	struct Book* tmp = *head;
	
	while(tmp -> title != x)
	{
		tmp = tmp -> nxt;
	}
	
	tmp -> issued = false;
}

void subreturnstatus(struct Subscriber** head, char x[50], char y[50])
{
	struct Subscriber* tmp = *head;
	int i;
	
	while(tmp -> name != y)
	{
		tmp = tmp -> nxt;
	}
	
	for(i = 0; i < tmp -> books; i++)
	{
		if(tmp -> title[i] == x)
		{
			strcpy(tmp -> title[i], "");
			strcpy(tmp -> date[i], "");
			break;
		}
	}
	
}

void issue_book()
{
	char subname[50], bookname[50];
	printf("\n Enter the subscriber - ");
	scanf("%s", &subname);
	printf("\n Enter the book to be issued - ");
	scanf("%s", &bookname);
	if(booksearch(&book_head, bookname) && subsearch(&sub_head, subname))
	{
		bookissuestatus(&book_head, bookname, subname);
		char date[50];
		printf("Enter the date of issue - ");
		subissuestatus(&sub_head, bookname, subname, date);
	}
}

void return_book()
{
	char subname[50], bookname[50];
	printf("\n Enter the subscriber - ");
	scanf("%s", &subname);
	printf("\n Enter the book to be returned - ");
	scanf("%s", &bookname);
	if(booksearch(&book_head, bookname) && subsearch(&sub_head, subname))
	{
		bookreturnstatus(&book_head, bookname);
		subreturnstatus(&sub_head, bookname, subname);
	}
}

void issuedbooks(struct Subscriber** head)
{
	struct Subscriber* tmp = *head;
	char x[50];
	printf("\n Enter the subscriber - ");
	scanf("%s", &x);
	
	while(tmp -> name != x)
	{
		tmp = tmp -> nxt;
	}
	
	int i;
	printf("\n <<<<<< ISSUED BOOKS >>>>>> \n");
	printf("\n TITLE \t\t DATE \n");
	for(i = 0; i < tmp -> books; i++)
	{
		printf("\n %s \t\t %s", tmp -> title, tmp -> date);
	}
}

void findsub()
{
	struct Book* tmp = book_head;
	char book[50];
	printf("\n Enter the book to be searched - ");
	scanf("%s", &book);
	
	while(tmp -> title != book)
	{
		tmp = tmp -> nxt;
	}
	
	printf("The book is issued to - %s", tmp -> sub);
}

int main()
{
	int ch;
	first_menu:
	{
		printf("\n <<<<<< \t\t LIBRARY MENU \t\t >>>>>> \n");
		printf(" 1. Enter a Book \n 2. Enter a Subscriber \n 3. Issue a Book \n 4. Return a Book \n 5. Issued Books by a Subscriber \n 6. Find Subscriber of Book \n 7. Exit");
		printf("\n Enter a choice (1 - 7) - ");
		scanf("%d", &ch);
	}
	switch(ch)
	{
		case 1: push_book(&book_head);
				goto first_menu;
				
		case 2: push_sub(&sub_head);
				goto first_menu;
		
		case 3: issue_book();
				goto first_menu;
		
		case 4: return_book();
				goto first_menu;
		
		case 5: issuedbooks(&sub_head);
				goto first_menu;
		
		case 6: findsub();
				goto first_menu;
		
		case 7: exit(0);
	}
	
	return(0);
}
