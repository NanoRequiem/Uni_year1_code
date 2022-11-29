package comp1721.cwk1;


import java.util.Scanner;

public class Guess {
  //Private fields
  private int guessNumber;
  private String chosenWord;

  // Use this to get player input in readFromPlayer()
  private static final Scanner INPUT = new Scanner(System.in);

  //constructor with int parameter
  public Guess(int num) {
    //Checks if number inputted is within the range 1-6 and if not
    //throws GameException error
    if(num < 1 || num > 6) {
      throw new GameException("Error: Guess number out of range");
    }
    else {
      guessNumber = num;
    }
    readFromPlayer();
  }

  //constructor with int and String parameters
  public Guess(int num, String word) {
    //Checks if number inputted is within the range 1-6 and if not
    //throws GameException error
    if(num < 1 || num > 6) {
      throw new GameException("Error: Guess number out of range");
    }
    else {
      guessNumber = num;
    }

    //Checks if inputted word is 5 characters
    //if not throws GameException Error
    if(word.length() != 5) {
      throw new GameException("Error: Guess should be 5 letters long");
    }

    //Check to see if all characters are alphanumeric
    Boolean alpha = true; //boolean to make sure that no character is numeric

    //for loop to search each character in the word
    //if any are not alphanumeric alpha is set to false
    for(int x = 0; x < word.length(); x++) {
      char c = word.charAt(x); //Creates character at current index
      if(!Character.isLetter(c)) {
        alpha = false;
      }
    }

    //if alpha is false throw GameException Error
    if(!alpha) {
      throw new GameException("Error: Word contains non-alphanumeric character");
    }
    else {
      chosenWord = word.toUpperCase();
    }
  }

  //returns Guess number
  public int getGuessNumber() {
    return guessNumber;
  }

  //returns chosenWord field
  public String getChosenWord() {
    return chosenWord;
  }

  //Takes input from the player and vaidates it
  public void readFromPlayer() {
    System.out.printf("Enter guess (%d/6): ", guessNumber);
    String word = INPUT.nextLine();

    //Checks if inputted word is 5 characters
    //if not throws GameException Error
    if(word.length() != 5) {
      throw new GameException("Error: Guess should be 5 letters long");
    }

    //Check to see if all characters are alphanumeric
    Boolean alpha = true; //boolean to make sure that no character is numeric

    //for loop to search each character in the word
    //if any are not alphanumeric alpha is set to false
    for(int x = 0; x < word.length(); x++) {
      char c = word.charAt(x); //Creates character at current index
      if(!Character.isLetter(c)) {
        alpha = false;
      }
    }

    //if alpha is false throw GameException Error
    if(!alpha) {
      throw new GameException("Error: Word contains non-alphanumeric character");
    }
    else {
      chosenWord = word.toUpperCase();
    }


  }

  //Compares guessed word with the actual word to check characters
  public String compareWith(String target) {
    String output = "";

    //Outer for loop to loop through the guess
    for (int x = 0; x < 5; x++) {
      boolean foundInWord = false; //Boolean to mark if the letter has been found in the word
      char guessChar = chosenWord.charAt(x);
      int y = 0;
      
      while(y < 5) {
        char targetChar = target.charAt(y);

        //If the letter is found in the target word mark foundInWord as true and stop the loop
        if(targetChar == guessChar) {
          foundInWord = true;
          target = target.replaceFirst(Character.toString(targetChar), " "); //Replaces found letter so it cannot be found again
          break;
        }
        y = y + 1;
      }

      //Checks if current letter has been found and adds the appropriate colouring to the output string
      if(foundInWord && x == y) {
        output = output + "\033[30;102m " + guessChar + " \033[0m";
      }
      else if(foundInWord && x != y) {
        output = output + "\033[30;103m " + guessChar + " \033[0m";
      }
      else {
        output = output + "\033[30;107m " + guessChar + " \033[0m";
      }
    }

    return output;
  }

  //Function checks if guess matches the word they're trying to guess
  //Outputs true if they are correct and false if they are not
  public boolean matches(String target) {
    //checks if guess matches actual word and outputs true if they are the same
    if(target.contains(chosenWord)) {
      return true;
    }
    else {
      return false;
    }
  }
}
