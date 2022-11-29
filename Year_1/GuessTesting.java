class GuessTesting {
    private static String chosenWord = "SPORT";

    public static void main(String[] args) {
        String str = "SPURT";
        String str2 = "SPORT";

        if(GuessTesting.matches(str2)) {
            System.out.println("wtf");
        }
        else {
            System.out.println("bruuuuuuh");
        }
    }

    public static boolean matches(String target) {
        if(target == chosenWord) {
            return true;
        }
        else {
            return false;
        }
    }
}