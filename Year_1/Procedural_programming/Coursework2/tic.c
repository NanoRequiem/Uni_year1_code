/************************************************************************
University of Leeds
School of Computing
COMP1711/XJCO1711- Procedural Programming
Coursework 2

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name: Brooklyn Mcswiney
Student ID: ed20b3m
Email: ed20b3m@leeds.ac.uk
Date Work Commenced: 15/11/21
*************************************************************************/


// ********************************************************************************************************************
// DO NOT CHANGE ANYTHING IN THE FOLLOWING SECTION. IF YOU CHANGE ANYTHING, YOUR CODE WILL FAIL THE AUTOGRADER TESTS.
// However, please read through this section and look at the array declaration and other functions that you will use in your code

#include <stdio.h>
#include <stdlib.h>
#include "tic.h"

// use this 2d array to store the moves of the game, please don't change its name or size
char grid[MaxGrid][MaxGrid]; // this is the grid that will be used to store the moves of the game

int __Check_Count; // do not use this variable, it is for the grader only

// USE THE FOLLOWING FUNCTIONS TO DISPLAY THE CORRECT PROMPTS AND MESSAGES WHEN YOU NEED THEM
// IN YOUR CODE. THIS WILL GUARANTEE THAT YOU PROGRAM'S OUTPUT MATCHES MINE AND FACILITATE AUTOGRADING

// please use this function to prompt the user to enter the grid size to start a new game
void promptEnterGridSize ()
{
  printf ("Enter grid size (3-10):");
}

// please use this function to prompt the user to enter the winning length for the new game
// the parameter represents the maximum winning length for this game
void promptEnterWinLength (int max_win_length)
{
	printf ("Enter winning length (3-%i):", max_win_length);
}

// please use this function to prompt the user to enter the location of the symbol
// this function takes as a parameter the symbol of the player to be prompted
void promptChooseLocation (char symbol)
{
	printf ("Player %c, Choose Location (row,col): ", symbol);
}

// please use this function to show an error message when an index is out of range
void showErrIndex ()
{
  printf ("Index out of range, please re-enter\n");
}

// please use this function to show an error message when a location is already taken
void showErrTaken ()
{
  printf ("This location is already taken\n");
}

// please use this function to show the win message at the end of the game
// this function takes as parameter the symbol of the player who won the game
void showWinMessage (char symbol)
{
	printf ("**************************\n");
	printf ("Player %c has won the game\n", symbol);
	printf ("**************************\n");
}

// please use this function to show a game over (draw) message at the end of the game
void showGameOverMessage ()
{
	printf ("Game over; there are no winners\n");
}

//  please use this function to prompt the user to choose if they want to play back the game (at the end of the game)
void promptPlayBackGame ()
{
  printf ("\nWould you like to play back the recorded game? (y,n)?");
}

// please use this function to prompt the user to answer with n (next) or e (exit)
// to indicate if they want to proceed with the game's replay or exit the program
void promptNextOrExit ()
{
  printf ("Next or Exit (n,e)?");
}

// You will use this function in effPlayerHasWon (see below).
// This function is basically a wrapper around an if statement to compare the content of the cell at row,col with symbol
// However, it also counts the number of times the function is called
// Needless to say again, don't change this function
int check (int row, int col, char symbol)
{
	__Check_Count++;
	if (grid[row][col] == symbol)
		return 1;
	return 0;
}

// Used by the grader to peek at a certain cell in the grid. Don't use this function
int peek (int row, int col)
{
	return grid[row][col];
}


// END OF CODE SECTION THAT SHOULD NOT BE CHANGED
// ************************************************

// --------------------------------------------------------------------------------------------------
// NOW IT IS YOUR TURN, YOU CAN DEFINE ANY OTHER GLOBAL VARIABLES YOU MAY NEED IN YOUR CODE BELOW THIS LINE
int chosenGridSize;
#define MaxTurns 100
int turnHistory[MaxTurns];


// END OF SECTION FOR DECLARRING ADDITIONAL GLOBAL VARIABLES
// ----------------------------------------------------------

// -------------------------------------------------------------------------------------------------
// NOW, IMPLEMENT THE FOLLOWING FUNCTIONS BY WRITING THE CORRECT CODE IN THE BODIES OF THE FUNCTIONS
// please, don't change the functions' name, return type, or parameters. If you change any of these the grader will crash
// initially these functions contain 'return -99'. Before implementing a function you should delete this statement

// The purpose of this function is to to start a new game
// It is used to initialise everything at the start of a new game
// This functions takes two integer parameters:
// The first parameter (gridsize) represents the size of the grid of the new game, .e.g. 3 for 3x3 game
// The minimum size of the grid is 3 and the maximum size is 10, if the value of the parameter is wrong (less than 3 or > 10)
// the function returns 0 indicating failure to start a new game.
// The second parameter (winlength) is the number of consecutive symbols for the winning case.
// This number cannot be less than 3 or > gridsize (why?), think but don't click :-)
// If the value of the second parameter is invalid (<3 or >gridsize) the function returns 0 (failure)
// If everything is correct the function returns 1 indicating success in initialising the game.
int newGame (int gridsize, int winlength)
{
  if(gridsize < 3 || gridsize > 10)
  {
    return 0;
  }
  if(winlength > gridsize || winlength < 3)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

// The purpose of this function is to show the game's grid on the screen
// The grid should exactly look like the examples in the assignment specification
// Please note the following when you implement the function:
// There is one empty line before the grid to make it stand out from text before it
// The column indices are printed at the top and the first one is indented by exactly one tab (\t); indices are separated by exactly one space
// The row indices are printed at the left followed by exactly one tab (\t)
// The grid symbols are separated by exactly one space
// There is one empty line after the grid to make it stand out from text after it
void showGrid ()
{
  printf("\n\t");
  int count;
  int county;

  for(count = 0; count < chosenGridSize; count++)
  {
    printf("%i ", count);
  }
  printf("\n");

  for(count = 0; count < chosenGridSize; count++)
  {
    printf("\n%i\t", count);
    for(county = 0; county < chosenGridSize; county++)
    {
      printf("%c ", grid[count][county]);
    }
  }
  printf("\n\n");
}

// The purpose of this function is to make a move by a player.
// Making a move means putting the player's symbol (letter) in the desired cell
// This function takes 3 parameters. The first two represent indices of the row and column of the cell in which the player
// wants to place their symbol.
// The last parameter is the symbol (letter) of that player.
// A move can only be made if:
// 1- The row and column numbers are valid (not less than 0 or greater than the game's grid size), and
// 2- the cell is not already occupied by another symbol, and
// 3- the symbol is a valid one (X or O).
// If the move can be made (because it is valid), the function makes the move (i.e. puts the symbol in the cell) and returns 1 indicating success.
// otherwise the function returns 0 indicating failure to make the move
// my solution is 4 lines only
int makeMove(int row, int col, char symbol)
{
    if(grid[row][col] != '.')
    {
      showErrTaken();
      return 0;
    }
    else if(row < 0 || row > chosenGridSize || col < 0 || col > chosenGridSize)
    {
      showErrIndex();
      return 0;
    }
    else if(symbol != 'X' && symbol != 'O')
    {
      return 0;
    }
    else
    {
      grid[row][col] = symbol;
      return 1;
    }
}

// This function is used to check if the board is full, i.e. every location in the grid is filled with either X or O
// it returns 1 if the grid is full, 0 otherwise
// my solution is 5 lines
int boardIsFull()
{
	int countx;
  int county;

  for(countx = 0; countx < chosenGridSize; countx++)
  {
    for(county = 0; county < chosenGridSize; county++)
    {
      if(grid[countx][county] == '.')
      {
        return 0;
      }
    }
  }
  return 1;
}


// This function is used to check if there is any horizontal line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a horizontal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a horizontal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkHorizontal (char symbol, int length)
{
  int countx;
  int county;
  int wincount;
  for(countx = 0; countx < chosenGridSize; countx++)
  {
    wincount = 0;
    for(county = 0; county < chosenGridSize; county++)
    {
      if(grid[countx][county] == symbol)
      {
        wincount = wincount + 1;
        if(wincount == length)
        {
          return 1;
        }
      }
      else if(grid[countx][county] != symbol && wincount > 0)
      {
        wincount = 0;
      }
    }
  }
	return 0;
}


// This function is used to check if there is any vertical line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a vertical run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a vertical line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkVertical (char symbol, int length)
{
  int countx;
  int county;
  int wincount;
  for(county = 0; county < chosenGridSize; county++)
  {
    wincount = 0;
    for(countx = 0; countx < chosenGridSize; countx++)
    {
      if(grid[countx][county] == symbol)
      {
        wincount = wincount + 1;
        if(wincount == length)
        {
          return 1;
        }
      }
      else if(grid[countx][county] != symbol && wincount > 0)
      {
        wincount = 0;
      }
    }
  }
  return 0;
}

// This function is used to check if there is any diagonal line in the grid that contains a consecutive sequence of the same symbol
// A diagonal line runs from higher left to lower right (or vice versa). Note that there are more than one diagonal line in a grid.
// It can be used to check that a player has won the game by forming a diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkDiagonals (char symbol, int length)
{
  int countx;
  int county;
  int wincount;
  int diaglen = chosenGridSize - 1;

  for(countx = 0; countx < chosenGridSize; countx++)
  {
    wincount = 0;
    for(county = 0; county <= diaglen; county++)
    {
      if(grid[countx + county][county] == symbol)
      {
        wincount = wincount + 1;
        if(wincount == length)
        {
          return 1;
        }
      }
      else if(grid[countx + county][county] != symbol && wincount > 0)
      {
        wincount = 0;
      }
    }
    diaglen = diaglen - 1;
  }

  diaglen = chosenGridSize -1;

  for(countx = 0; countx < chosenGridSize; countx++)
  {
    wincount = 0;
    for(county = 0; county <= diaglen; county++)
    {
      if(grid[county][countx + county] == symbol)
      {
        wincount = wincount + 1;
        if(wincount == length)
        {
          return 1;
        }
      }
      else if(grid[countx + county][county] != symbol && wincount > 0)
      {
        wincount = 0;
      }
    }
    diaglen = diaglen - 1;
  }
  return 0;
}

// This function is used to check if there is any anti-diagonal (reverse diagonal) section in the grid that contains a consecutive sequence of the same symbol
// An anti-diagonal line runs from higher right to lower left (or vice versa). Note that there are more than one anti-diagonal line in a grid.
// It can be used to check that a player has won the game by forming an anti-diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed an anti-diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating an failure to make a move
int checkAntiDiagonals (char symbol, int length)
{
  int countx;
  int county;
  int wincount;
  int cnt;
  int diaglen = chosenGridSize - 1;

  for(countx = chosenGridSize - 1; countx > 0; countx--)
  {
    wincount = 0;
    for(county = 0; county <= diaglen; county++)
    {
      if(grid[county][countx - county] == symbol)
      {
        wincount = wincount + 1;
        if(wincount == length)
        {
          return 1;
        }
      }
      else if(grid[county][countx - county] != symbol && wincount > 0)
      {
        wincount = 0;
      }
    }
    diaglen = diaglen - 1;
  }

  diaglen = chosenGridSize - 1;

  for(countx = 1; countx <= chosenGridSize - 1; countx++)
  {
    wincount = 0;
    cnt = countx;
    for(county = chosenGridSize - 1; county >= countx; county--)
    {
      if(grid[cnt][county] == symbol)
      {
        wincount = wincount + 1;
        if(wincount == length)
        {
          return 1;
        }
      }
      else if(grid[cnt][county] != symbol && wincount > 0)
      {
        wincount = 0;
      }
      cnt = cnt + 1;
    }
    diaglen = diaglen - 1;
  }
  return 0;
}


// This function is used to check if a player has won the game by forming a horizontal, vertical, diagonal, or anti-diagonal line
// of the required length. This function should use the above four functions (checkHorizontal, checkVertical, checkDiagonals, and checkAntiDiagonals)
// to determine if the player has one
// The function returns 1 if the player given by symbol has won, and 0 if the player has not won
// If any of the parameters is invalid the function returns -1 indicating failure to check
// my solution is 5 lines
int playerHasWon (char symbol , int length)
{
  if(checkHorizontal(symbol, length) == 1)
  {
    return 1;
  }
  if(checkVertical(symbol, length) == 1)
  {
    return 1;
  }
  if(checkDiagonals(symbol, length) == 1)
  {
    return 1;
  }
  if(checkAntiDiagonals(symbol, length) == 1)
  {
    return 1;
  }
	return 0;
}

// Do you think the above function (playerHasWon) is the most efficient way of detecting a win?
// Do we do this as humans when we play the game?
// The answer is NO.
// The purpose of this function is to implement a much more efficient version of the playerHasWon function
// The function takes four parameters.
// The first two parameters represent the location (row, and col) of the last move made
// by a player.
// The second parameter is the symbol of that player.
// The last parameter is the length of the winning line
// We will assess the efficiency of the function by the number of times we need to check the contents of a cell.
// To count the number of checks, I have prepared a function called check - see the top of this file - that you have
// to use instead of an if statement when you need to compare the contents of a cell to a given symbol.
//
// This function returns 1 if the player has formed a winning line immediately after placing their symbol in the
// cell given by row,col. If the player did not win, the function returns 0
// It returns -1 if any of the parameters have an invalid value.
int effPlayerHasWon (int row, int col, char symbol , int length)
{
	return -99;
}

// IF YOU NEED ADDITIONAL FUNCTIONS YOU CAN DEFINE THEM BELOW THIS LINE
//----------------------------------------------------------------------






// DON'T CHANGE THE FOLLOWING 3 LINES
#ifndef TEST
int  main (int argc, char* argv[])
{
	// ENTER THE CODE OF YOUR main FUNCTION BELOW
  int winsize;
  int row;
  int col;
  char curSymbol = 'X';
  char currentinp[3] = "";
  int HasWon = 0;
  int turncount = 0;

  promptEnterGridSize();
  scanf("%i", &chosenGridSize);
  promptEnterWinLength(chosenGridSize);
  scanf("%i", &winsize);

  if(newGame(chosenGridSize, winsize) == 0)
  {
    showErrIndex();
    return 0;
  }
  else if(newGame(chosenGridSize, winsize) == 1)
  {
    int countx;
    int county;
    for(countx = 0; countx < chosenGridSize; countx++)
    {
      for(county = 0; county < chosenGridSize; county++)
      {
        grid[countx][county] = '.';
      }
    }
  }

  while(HasWon == 0)
  {
    int movemade = -1;

    showGrid();
    promptChooseLocation(curSymbol);
    scanf("\n%s", currentinp);
    row = (int)(currentinp[0]) - 48;
    col = (int)(currentinp[2]) - 48;
    movemade = makeMove(row, col, curSymbol);

    if(playerHasWon(curSymbol, winsize) == 1)
    {
      showGrid();
      showWinMessage(curSymbol);
      HasWon = 1;
    }

    if(movemade == 1)
    {
      turnHistory[turncount] = row;
      turnHistory[turncount + 1] = col;
      if(curSymbol == 'X')
      {
        curSymbol = 'O';
      }
      else if(curSymbol == 'O')
      {
        curSymbol = 'X';
      }
    }
    turncount = turncount + 2;
    if(boardIsFull() == 1)
    {
      showGrid();
      showGameOverMessage();
      break;
    }
  }

  turnHistory[turncount] = -99;

  char playBack;
  promptPlayBackGame();
  scanf("\n%c", &playBack);
  if(playBack == 'y')
  {
    int countx;
    int county;
    curSymbol = 'X';
    turncount = 0;
    for(countx = 0; countx < chosenGridSize; countx++)
    {
      for(county = 0; county < chosenGridSize; county++)
      {
        grid[countx][county] = '.';
      }
    }
    while(playBack != 'e')
    {
      showGrid();
      promptNextOrExit();
      scanf("\n%c", &playBack);

      if(playBack == 'e')
      {
        break;
      }

      makeMove(turnHistory[turncount], turnHistory[turncount + 1], curSymbol);

      if(curSymbol == 'X')
      {
        curSymbol = 'O';
      }
      else if(curSymbol == 'O')
      {
        curSymbol = 'X';
      }
      turncount = turncount + 2;
      if(turnHistory[turncount] == -99)
      {
        playBack = 'e';
        showGrid();
      }
    }
  }


// DON'T CHANGE THE FOLLOWING 3 LINES
  return 0;
}
#endif
// DON'T WRITE ANYTHING BELOW THIS LINE
