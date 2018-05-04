#include "database_main.h"

void print_book(struct Book* book){		/*print a book*/
	printf("Title: %s\n",book->title);
	printf("Author: %s\n",book->author);
	printf("Year: %i\n\n",book->year);
}

void print_book_tree(struct Book* book_tree){		/*print the book tree alphabetically*/
	if (book_tree == NULL){
	return;				  /*return to the last layer if hit NULL*/	
	}
	print_book_tree(book_tree->left);	/*recursion go left*/
	if (book_tree->year != -1){		/*Task2, do not print if the book is deleted*/
		print_book(book_tree);		/*print the book*/
}
	print_book_tree(book_tree->right);	/*recursion go right*/

}


void addtotree(struct Book** book_tree,struct Book* newbook){
	if (*book_tree == NULL){
		*book_tree = newbook;					/*if the book tree is empty add the new book in*/
		fprintf(stderr,"'%s' Successfully Added\n",newbook->title);

	}else if(strcmp(newbook->title,(*book_tree)->title) > 0 ){	/*go left if the title is smaller than the current*/

		addtotree((&(*book_tree)->right),newbook);

	}else if(strcmp(newbook->title,(*book_tree)->title) < 0 ){	/*go right if the title is bigger than current*/
		addtotree((&(*book_tree)->left),newbook);
	}else if(strcmp(newbook->title,(*book_tree)->title) == 0 ){	/*Task 2, add the same book after it was 'deleted'*/
		strcpy((*book_tree)->author,newbook->author);
		(*book_tree)->year = newbook->year;
		fprintf(stderr,"Successfully Updated");
	};

};

void clear_input_buffer(){	/*clear input buffer*/
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	}

void menu_add_book(void){

	struct Book *new;
	new = (struct Book*) malloc(sizeof(struct Book));
	int temp;
	do{
	fprintf ( stderr,"Book Name:");						/*Scan in book name*/
	scanf ("%[^\n]", new->title);
	clear_input_buffer();
	}while((new->title)[0] == '\n' || (new->title)[0] == '\0');

	do{
	fprintf ( stderr,"Author: ");
	scanf ("%[^\n]", new->author);						/*Scan in Author */
	clear_input_buffer();
	}while((new->author)[0] == '\n' || (new->author)[0] == '\0');

	do{
	fprintf ( stderr,"Year: ");
	temp = scanf ("%d", &(new->year));	
	clear_input_buffer();							/*Scan in year */
	}while(temp != 1 || (new->year < 0));

	new->left=new->right=NULL;
	addtotree(&book_tree,new);
}



void menu_print_database(void){
	fprintf(stderr,"\nPrinting Database...\n\n");	 /*I dont want to change the main, so I made a new function*/
	print_book_tree(book_tree);
}	    

