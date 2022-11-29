#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"
#include "user.h"
#include "librarian.h"
#include "utility.h"

////
// Code module for main library menu and file management
// Reads the book and initialises the problem data

// Initialise library data
// Input:
// bookfile - name of book file
// theLibrary - library data structure

void initLibrary( char *bookFile, Library *theLibrary ) {

  theLibrary->maxBooks = 12;
  theLibrary->maxBorrowed = 4;
  int count = 0;
  // TO DO :

  // dynamically allocate the bookList array for storing books
  Book *bookList = (Book *)calloc(12, sizeof(Book));


  // check the book file exists
  FILE *books;

  books = fopen (bookFile, "r");
  if(books == NULL)
  {
    printf("Error\nBook file does not exist: ");
    printf("%s\n", bookFile);
    exit(0);
  }
  else
  {
    User *theUser = (User *)malloc( sizeof(User));

    while(count < 4)
    {
      theUser->borrowed[count] = NULL;
      count = count + 1;
    }

    theLibrary->theUser = *theUser;
    theLibrary->numBooks = readBooks(books, bookList);
    theLibrary->bookList = bookList;

    fclose(books);
  }
  // use the error message and exit the program if it does not

  // open it if it exists

  // use the readBooks function to read in the file and add the book records into the bookList array

  // remember to close the file

  // Initialise the User data

  return;
}

// Read in book file and create the books data structure
// the book file is in a fixed format:
// * book author
// * book title
// * blank line
// Input:
//   books - file pointer to text input file
//   bookList - alocated array for storing Book structures
// Output:
//   numBooks - number of books read

int readBooks( FILE *books, Book *bookList ) {

  int numBooks = 0;
  int count = 1;
  char line[40];
  int orderNumb = 0;
  // TO DO:

  // read from the book file pointer

  // assign values to a Book structure in the bookList array for each complete record

  // read data until the file ends
  while(fgets(line, 40, books))
  {
    if(orderNumb == 0)
    {
      line[strlen(line)-1] ='\0';
      line[strlen(line)-1] ='\0';
      strcpy(bookList[numBooks].author, line);
    }
    else if(orderNumb == 1)
    {
      line[strlen(line)-1] ='\0';
      strcpy(bookList[numBooks].title, line);
    }
    if(orderNumb == 2)
    {
      orderNumb = -1;
      numBooks = numBooks + 1;
    }
    orderNumb = orderNumb + 1;
    count = count + 1;
  }

  count = 0;

  while(count < 8)
  {
    bookList[count].available = 1;
    count = count + 1;
  }

  return numBooks;
}

// Free any allocated library data
// Input:
// theLibrary - library data structure

void exitLibrary( Library *theLibrary ) {

  // TO DO:
  int count = 0;
  // free the allocated lists
  free(theLibrary->bookList);
  while(count < 4)
  {
    if(theLibrary->theUser.borrowed[count] != NULL)
    {
      free(theLibrary->theUser.borrowed[count]);
    }
    count = count + 1;
  }

  return;
}

// DO NOT ALTER THIS FUNCTION
// Library menu system

void libraryCLI( char *bookFile ) {
    int libraryOpen = 1;
    int option;

    // create the library structure
    Library *theLibrary = (Library *)malloc( sizeof(Library) );

    initLibrary( bookFile, theLibrary );

    while( libraryOpen ){
        printf("\n Main menu options\n 1 User login\n 2 Librarian login\n 3 Exit system\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nUser login\n");
            userCLI( theLibrary );
        }
        else if( option == 2 ) {
            printf("\nLibrarian login\n");
            librarianCLI( theLibrary );
        }
        else if( option == 3 ) {
            libraryOpen = 0;
            printf("\nClosing\n");
        }
        else
            printf("\nUnknown option\n");
    }

    exitLibrary( theLibrary );

    // free the library structure
    free( theLibrary );

    return;
}
