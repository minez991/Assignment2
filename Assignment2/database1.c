#include "database_main.h"


void addtotree(struct Book* book_tree,struct Book* newbook){
	/*if the book tree is empty add this in*/

	if (book_tree == NULL){

		book_tree = newbook;
		printf("\n%s\n",newbook->title );
		printf("%s\n",book_tree->title );

	}else if(strcmp(newbook->title,book_tree->title) > 0 ){

		addtotree(book_tree->right,newbook);

	}else if(strcmp(newbook->title,book_tree->title) < 0 ){

		addtotree(book_tree->left,newbook);
	}

};

/* menu_add_book():
 *
 * Add new book to database
 */
void menu_add_book(void){
	struct Book *new;
	new = (struct Book*) malloc(sizeof(struct Book));
	fprintf ( stderr,"Book Name:");
	scanf ("%[^\n]%*c", new->title);
	fprintf ( stderr,"Author: ");
	scanf ("%[^\n]%*c", new->author);
	fprintf ( stderr,"Year: ");
	scanf ("%i", &(new->year);	
	fprintf(stderr,"Year = %i",new->year);
	new->left=new->right=NULL;
	addtotree(book_tree,new);
}


/* menu_print_database():
 *
 * Print database of books to standard output in alphabetical order of title.
 */
void menu_print_database(void){
   /* fill in the code here in part 1, and add any extra functions you need */
}	    
