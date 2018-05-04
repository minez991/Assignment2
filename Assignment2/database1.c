#include "database_main.h"


void print_book(struct Book* book){

	if (book == NULL){
	return;
	}
	print_book(book->left);
	if (book->year != -1){
	printf("Title: %s\n",book->title);
	printf("Author: %s\n",book->author);
	printf("Year: %i\n\n",book->year);
}
	print_book(book->right);

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

void clear_input_buffer(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}

void menu_add_book(void){

	struct Book *new;
	new = (struct Book*) malloc(sizeof(struct Book));
	int temp;
	do{
	fprintf ( stderr,"Book Name:");
	scanf ("%[^\n]", new->title);
	clear_input_buffer();
	}while((new->title)[0] == '\n' || (new->title)[0] == '\0');

	do{
	fprintf ( stderr,"Author: ");
	scanf ("%[^\n]", new->author);
	clear_input_buffer();
	}while((new->author)[0] == '\n' || (new->author)[0] == '\0');

	do{
	fprintf ( stderr,"Year: ");
	temp = scanf ("%i", &(new->year));	
	clear_input_buffer();
	}while(temp != 1 || (new->year < 0));

	new->left=new->right=NULL;
	addtotree(&book_tree,new);
}


/* menu_print_database():
 * Print database of books to standard output in alphabetical order of title.
 */
void menu_print_database(void){ /*I dont want to change the main, so I made a new function*/
   print_book(book_tree);
}	    

