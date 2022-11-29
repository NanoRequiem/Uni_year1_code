import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoUnit;

class dateTesting {
    public static void main(String[] args) {
        LocalDate today = LocalDate.now();
        LocalDate firstWord = LocalDate.of (2021, 6, 19);
        int wordNumb = Period.between(firstWord, today).getDays();
        long wordNumb2 = ChronoUnit.DAYS.between(firstWord, today);

        int wordNumb3 = (int)wordNumb2;

        System.out.println(today);
        System.out.println(firstWord);
        System.out.println(wordNumb);
        System.out.println(wordNumb2);
        System.out.println(wordNumb3);

        for (int x = 1; x <= 6; x++) {
            System.out.println(x);
        }
    }
}