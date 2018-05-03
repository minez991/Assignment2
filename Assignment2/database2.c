#include "database_main.h"
void clear_input_buffer();
struct Book* lookforbook(struct Book* book_tree, char* book_name){

	if (book_tree == NULL){

		return NULL;
	}


	int direction = strcmp(book_name,book_tree->title);

	if (direction < 0){
	lookforbook(book_tree->left,book_name);
	}else if(direction > 0){
	lookforbook(book_tree->right,book_name);
	}else if(direction == 0){
		return book_tree;
	}
	
}



void menu_get_book_details(void)
{	
	char *book_name = malloc(1000 * sizeof(char)); /*Create a dynamic memeory space for the book name*/
	struct Book* temp_book;

	fprintf(stderr,"What is the name of the book?: ");
	scanf("%s",book_name);
	clear_input_buffer();

	temp_book = lookforbook(book_tree,book_name);

	if (temp_book == NULL){
		fprintf(stderr,"Do not exist\n");
	}else{
		printf("Title: %s\n",temp_book->title);
		printf("author: %s\n",temp_book->author);
		printf("year: %i\n", temp_book->year);
	}
	free(book_name);
}

/* menu_delete_book():
 *
 * Delete new book from database.
 */
void menu_delete_book(void)
{	
	char *book_name = malloc(1000 * sizeof(char)); /*Create a dynamic memeory space for the book name*/
	struct Book* temp_book;

	fprintf(stderr,"What is the name of the book?: ");
	scanf("%s",book_name);
	clear_input_buffer();

	temp_book = lookforbook(book_tree,book_name);

	if (temp_book == NULL){
		fprintf(stderr,"Do not exist\n");
	}else{
		temp_book->year = -1;
	}


}

