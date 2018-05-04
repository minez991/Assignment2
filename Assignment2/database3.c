#include "database_main.h"



/* read file containing database of books */
void read_book_database ( char *file_name )
{
  struct Book* newBook;
  int test;
  FILE* file;
  file = fopen(file_name,"r");	/*opens the file*/
  if (file==NULL){					/*Error if the file can not be read*/
  	fprintf(stderr,"unable to read the file\n");
  	exit(1);
  	  }
  do{
  newBook = (struct Book*) malloc(sizeof(struct Book));
  test = fscanf(file,"Title: %[^\n]\nAuthor: %[^\n]\nYear: %i\n\n",newBook->title,newBook->author,&(newBook->year));	/*Scan in the data with the standard format*/
  	if(test == 3){
  		addtotree(&book_tree,newBook);	/*add the book to tree if scan in successfully*/
 
  	}else if(test != EOF){			/*Exit the program if the data is not input correct*/
  		fprintf(stderr, "Incorrect Data input\n");	/*Error message*/
  		exit(EXIT_FAILURE);
  	}
  }while(test != EOF);     			/*Read until the end of file*/
}

