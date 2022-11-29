#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "user.h"
#include "utility.h"

////
// Code module for the library user
// They can look for available books,
// borrow and return books

// List the books that are available to borrow
// Input
// bookList - the array of Book structures
// numBooks - the number of books

void listAvailableBooks( Book *bookList, int numBooks ) {
  int count = 0;
  // TO DO :

  // print out available books with format "list number - author - title" on each line
  while(count < numBooks)
  {
    if(bookList[count].available == 1)
    {
      printf("%i - %s - %s\n", count, bookList[count].author, bookList[count].title);
    }
    count = count + 1;
  }

  return;
}

// Borrow a book
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void borrowBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  int canBorrow = 0;
  int count = 0;
  int bookChoice;
  // TO DO :

  while (count < 4)
  {
    if(theUser->borrowed[count] == NULL)
    {
      canBorrow = 1;
      break;
    }
    count = count + 1;
  }

  if(canBorrow == 0)
  {
    printf("You have to return a book before you can borrow another\n");
    return;
  }

  else if(canBorrow == 1)
  {
    printf("Which book? (number):");
    bookChoice = optionChoice();
    if(bookChoice > 6 || bookChoice < 0)
    {
      printf("Error\nInvalid choice\n");
    }
    else if(bookList[bookChoice].available == 0)
    {
      printf("Book is not available\n");
    }
    else
    {
      bookList[bookChoice].available = 0;
      theUser->borrowed[count] = malloc( sizeof(Book));

      strcpy(theUser->borrowed[count]->author, bookList[bookChoice].author);
      strcpy(theUser->borrowed[count]->title, bookList[bookChoice].title);
      theUser->borrowed[count]->available = 0;
    }
  }

  // For any error message you should return to the menu
  //while()
  // check that the user can borrow a book

  // request the choice of book

  // check that the choice is valid
  // error messages

  // borrow the book, update the data structures

  return;
}

// List books I have borrowed
// Input
// theUser - user data structure
// bookList - the array of Book structures
// maxBorrowed - max books we can borrow

void listMyBooks( User *theUser, Book *bookList, int maxBorrowed ) {

  // TO DO :

  // list my books in format "number - author - title"
  int count = 0;

  while(count < maxBorrowed)
  {
    if(theUser->borrowed[count] != NULL)
    {
      printf("%i - %s - %s\n", count, theUser->borrowed[count]->author, theUser->borrowed[count]->title);
    }
    count = count + 1;
  }


  return;
}

// Return a book
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void returnBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  int count = 1;
  int haveBook = 0;
  int choice;
  int compare = 1;
  char bookListCheck[40];
  char borrowedCheck[40];
  // TO DO :

  // For any error message you should return to the menu
  while(count < maxBorrowed)
  {
    if(theUser->borrowed[count] != NULL)
    {
      haveBook = 0;
    }
    count = count + 1;
  }
  if(haveBook == 1)
  {
    // check that we have borrowed books
    printf("Error\nYou have not borrowed any books\n");
    return;
  }
  // error messages


  // request the choice of book
  // message
  printf("Which book? (number):");
  choice = optionChoice();

  if(choice > 3 || choice < 0)
  {
    printf("Error\nInvalid choice\n");
    return;
  }
  else if(theUser->borrowed[choice] == NULL)
  {
    printf("Error\nInvalid choice\n");
    return;
  }
  else
  {
    count = 0;
    strcpy(borrowedCheck, theUser->borrowed[choice]->author);
    while(count < numBooks)
    {
      compare = 1;
      strcpy(bookListCheck, bookList[count].author);
      compare = strcmp(bookListCheck, borrowedCheck);
      if(compare == 0)
      {
        bookList[count].available = 1;
      }
      count = count + 1;
    }
    theUser->borrowed[choice] = NULL;
  }
  // check the choice is valid
  // error messages

  // return the book and update data structures

  return;
}

// DO NOT ALTER THIS FUNCTION

// Menu system for library user

void userCLI( Library *theLibrary ) {
    int userLoggedIn = 1;
    int option;

    while( userLoggedIn ){
        printf("\n User options\n 1 List available books\n 2 Borrow book\n 3 Return book\n 4 Log out\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nList available books:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
        }
        else if( option == 2 ) {
            printf("\nBorrow book from library:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
            borrowBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 3 ) {
            printf("\nReturn book from my list:\n");
            listMyBooks( &(theLibrary->theUser), theLibrary->bookList, theLibrary->maxBorrowed );
            returnBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 4 ) {
            userLoggedIn = 0;
            printf("\nLogging out\n");
        }
        else
            printf("\nUnknown option\n");
    }
    return;
}
