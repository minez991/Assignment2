#include "database_main.h"

void print_book(struct Book* book){

	if (book == NULL){
	return;
	}
	print_book(book->left);
	printf("Title: %s\n",book->title);
	printf("Author: %s\n",book->author);
	printf("Year: %i\n\n",book->year);
	print_book(book->right);

	/*if (book->left != NULL){
		print_book(book->left);

	}else{
		fprintf( stderr,"left: NULL\n");

	}
	if (book->right != NULL){
		print_book(book->right);
	}else{
		fprintf( stderr,"right: NULL\n");
	}*/

}


void addtotree(struct Book** book_tree,struct Book* newbook){
	/*if the book tree is empty add this in*/
	if (*book_tree == NULL){

		*book_tree = newbook;

	}else if(strcmp(newbook->title,(*book_tree)->title) > 0 ){

		addtotree((&(*book_tree)->right),newbook);

	}else if(strcmp(newbook->title,(*book_tree)->title) < 0 ){

		addtotree((&(*book_tree)->left),newbook);
	}

};

/* menu_add_book():
 *
 * Add new book to database
 */

void menu_add_book(void){
	char c;
	struct Book *new;
	new = (struct Book*) malloc(sizeof(struct Book));
	fprintf ( stderr,"Book Name:");
	scanf ("%[^\n]%*c", new->title);
	fprintf ( stderr,"Author: ");
	scanf ("%[^\n]%*c", new->author);
	fprintf ( stderr,"Year: ");
	scanf ("%i", &(new->year));	
	while ((c = getchar()) != '\n' && c != EOF) { }
	new->left=new->right=NULL;
	addtotree(&book_tree,new);
}


/* menu_print_database():
 * Print database of books to standard output in alphabetical order of title.
 */
void menu_print_database(void){
   print_book(book_tree);
}	    
