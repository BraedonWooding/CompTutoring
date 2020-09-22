package question_bank;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class SelectQuestion extends AQuestion {
    private Boolean multiSelect;

    protected SelectQuestion(String name, Boolean multiSelect, List<AQuestionVariation> variations) {
        super(name, variations);
        this.multiSelect = multiSelect;
    }

    @Override
    protected String AskQuestion(AQuestionVariation variation) {
        // you shouldn't close a scanner on System.in if you are expecting to use it again.
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println((this.multiSelect ? "Select multiple answers" : "Select one answer")
                + "\n" + variation.toString());
            String line = sc.nextLine();
            if (multiSelect) {
                String[] options = line.split(",");
                if (Arrays.stream(options).anyMatch(x -> !variation.IsValid(x.trim()))) {
                    System.err.println("Invalid Option");
                    continue;
                }
            } else if (!variation.IsValid(line.trim())) {
                System.err.println("Invalid Option");
                continue;
            }
            return line;
        }
    }
}
