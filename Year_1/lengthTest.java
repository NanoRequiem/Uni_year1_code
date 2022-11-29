import java.lang.StringBuffer;;

class lengthTest {
    public static void main(String[] args) {
        String chosenWord = "SOUPS";
        String target = "PAUSE";
        String output = "";
        char guessChar = ' ';
        char targetChar = ' ';
        boolean foundInWord = false;
        int y = 0;
        int x = 0;

        //Outer for loop to loop through the guess
        for (x = 0; x < 5; x++) {
            foundInWord = false; //Boolean to mark if the letter has been found in the word
            guessChar = chosenWord.charAt(x);
            y = 0;
            while(y < 5) {
                targetChar = target.charAt(y);
                System.out.printf("GuessChar at %d = %c\n", x, guessChar);
                System.out.printf("targetChar at %d = %c\n", y, targetChar);
                //If the letter is found in the target word mark foundInWord as true and stop the loop
                if(targetChar == guessChar) {
                    foundInWord = true;
                    target = target.replaceFirst(Character.toString(targetChar), " ");
                    break;
                }
            y = y + 1;
            }
            //Checks if current letter has been found and adds the appropriate colouring to the output string
            if(foundInWord && x == y) {
                output = output + "\033[30;102m " + guessChar + " \033[0m";
            }
            else if(foundInWord) {
                output = output + "\033[30;103m " + guessChar + " \033[0m";
            }
            else {
                output = output + "\033[30;107m " + guessChar + " \033[0m";
            }
        }

        System.out.println(output);
        System.out.println("\033[30;103m S \033[0m\033[30;107m O \033[0m\033[30;102m U \033[0m\033[30;103m P \033[0m\033[30;107m S \033[0m");

    }
}
