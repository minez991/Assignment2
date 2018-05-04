#include "database_main.h"



/* read file containing database of books */
void read_book_database ( char *file_name )
{
  struct Book* newBook;
  int test;
  FILE* file;
  file = fopen(file_name,"r");
  if (file==NULL){
  	fprintf(stderr,"unable to read the file\n");
  	exit(1);
  	  }
  do{
  newBook = (struct Book*) malloc(sizeof(struct Book));
  test = fscanf(file,"Title: %[^\n]\nAuthor: %[^\n]\nYear: %i\n\n",newBook->title,newBook->author,&(newBook->year));
  	if(test == 3){
  		addtotree(&book_tree,newBook);
 
  	}else if(test != EOF){
  		fprintf(stderr, "Incorrect Data input\n");
  		exit(EXIT_FAILURE);
  	}
  }while(test != EOF);
}

