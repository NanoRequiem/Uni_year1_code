package comp1721.cwk1;

import org.omg.CORBA.Current;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoUnit;
import java.util.Objects;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.io.PrintWriter;

public class Game {
  //Private fields
  private int gameNumber;
  private String target;
  private Guess[] guesses = new Guess[6];

  //Initializes the current game using today to get the game number
  public Game(String filename) throws IOException{
    //localDate variables to get the days since the first wordle game
    LocalDate today = LocalDate.now();
    LocalDate firstWord = LocalDate.of (2021, 6, 19);

    //Use of chronounit to calculate days between now and first wordle game
    long wordNumberLong = ChronoUnit.DAYS.between(firstWord, today);
    int gameNumber = (int)wordNumberLong;

    //Initializing WordList to get today's wordle
    WordList words = new WordList(filename);

    //Using wordList class to get today's wordle
    target = words.getWord(gameNumber);
  }

  //Initializes the current game using user input to get the game number
  public Game(int num, String filename) throws IOException{
    //Initializing WordList to get today's wordle
    WordList words = new WordList(filename);

    //Using wordList class to get today's wordle
    target = words.getWord(num);
    gameNumber = num;


    //Checks that the inputted game number is within bounds
    if(num < 0 || num > words.size()) {
      throw new GameException("Error: Game number out of bounds.");
    }
    else {
      //Initializes gameNumber based on user input
    gameNumber = num;
    }
  }

  //Play method that handles runnning the game and saving guesses
  public void play() {
    //Found value to check if the word has been guessed by the user
    int found = 0;
    int x;

    //for loop that goes through each guess allowed
    for (x = 0; x <= 5; x++) {

      //Initializes the current guess
      guesses[x] = new Guess(x + 1);

      //Printing the output of the comparison between guess and target word
      System.out.println(guesses[x].compareWith(target));

      //Checks if the word guessed is correct and if it is
      //Check which output message is appropriate and stop
      //running the loop
      if(guesses[x].matches(target)) {
        found = 1;

        break;
      }
    }

    //Checks if the word has been found
    //If it has been found output a victory message
    //If not output a defeat message
    if(found == 1) {
      if(x==0) {
        System.out.println("Superb - Got it in one!");
      }

      else if(x >= 1 && x <= 4) {
        System.out.println("Well done!");
      }

      else if(x == 5){
        System.out.println("That was a close call!");
      }
    }
    else {
      System.out.println("Nope - Better luck next time!");
    }
  }

  //Save method which handles saving the last game's outputs to a text file
  public void save (String filename) throws IOException{
    //Path variable to get output file path
    Path outputPath = Paths.get(filename);

    //Printwriter to output guesses to an output file
    try (PrintWriter out = new PrintWriter(
      Files.newBufferedWriter(outputPath))) {

        //For loop that goes through all guesses and writes them to a file
        for(int x = 0; x < 6; x++) {
          
          //Checks if a guess has not been made and skips this entry if it is
          if(Objects.isNull(guesses[x])) {
            continue;
          }

          //Outputs guess to the output file
          out.println(guesses[x].compareWith(target));
        }
    }
  }
}
