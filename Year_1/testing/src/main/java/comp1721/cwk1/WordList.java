package comp1721.cwk1;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.nio.file.Paths;

public class WordList {
  //private fields
  private ArrayList<String> words = new ArrayList<String>();

  //constructor with a String parameter
  public WordList(String filename) throws IOException{
    //Scanner to read in the words
    Scanner word = new Scanner(Paths.get(filename));

    //Loop to read every line of the file and write it into the words list
    while(word.hasNextLine()) {
      words.add(word.nextLine());
    }
  }

  //Method to return size of the list
  public int size() {
    //Returns the size of the list
    return words.size();
  }

  //Method to return a word given an index
  public String getWord(int n) {
    //Checks if input is within array and outputs an exeption if it is
    if(n < 0 || n >= words.size()) {
      throw new GameException("Error: Invalid word index");
    }

    //If output is valid output the word
    return words.get(n);
    
  }
}
