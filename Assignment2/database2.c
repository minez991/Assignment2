#include "database_main.h"
void clear_input_buffer();
void print_book();

struct Book* lookforbook(struct Book* book_tree, char* book_name){	/*look for the book in the tree*/

	if (book_tree == NULL){
		return NULL;					/*if it reaches NULL, book do not exist*/
	}


	int direction = strcmp(book_name,book_tree->title);		

	if (direction < 0){
	lookforbook(book_tree->left,book_name);			/*go left if the book_name strcmp return <0*/
	}else if(direction > 0){
	lookforbook(book_tree->right,book_name);
	}else if(direction == 0){				/*Book found if strcmp ==0, and return the pointer to the book*/
		return book_tree;
	}
	
}



void menu_get_book_details(void)
{	
	char *book_name = malloc(1000 * sizeof(char)); /*Create a dynamic memeory space for the book name*/
	struct Book* temp_book;

	fprintf(stderr,"What is the name of the book?: ");
	scanf("%[^\n]",book_name);
	clear_input_buffer();

	temp_book = lookforbook(book_tree,book_name);	/* try to find the book*/

	if (temp_book == NULL || temp_book->year == -1){	/*do not print if the book is deleted*/
		fprintf(stderr,"\nBook Not Found!\n");		/*Error message if the book is not found or "deleted" */
	}else{
		fprintf(stderr,"\nBook Found!\n");	/*if the book is found, print the book*/
		print_book(temp_book);
	}

	free(book_name);
}


void menu_delete_book(void)
{	
	char *book_name = malloc(1000 * sizeof(char)); /*Create a dynamic memeory space for the book name*/
	struct Book* temp_book;

	fprintf(stderr,"What is the name of the book?: "); 
	scanf("%[^\n]",book_name);
	clear_input_buffer();

	temp_book = lookforbook(book_tree,book_name);		/* look for the book*/

	if (temp_book == NULL || temp_book->year == -1){	
		fprintf(stderr,"\nBook Not Found!\n");		/*error message if the book do not exist or already deleted*/
	}else{
		temp_book->year = -1;				/* Set the year to -1, which indicates the book is deleted*/
	}


}

