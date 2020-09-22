package question_bank;

import java.util.List;

public class SelectQuestionVariation extends AQuestionVariation {
    private List<String> options;

    public SelectQuestionVariation(String name, String title, List<String> options) {
        super(name, title);
        this.options = options;
    }
    
    @Override
    public Boolean IsValid(String option) {
        return options.contains(option);
    }

    @Override
    public String toString() {
        return super.toString() + "\nPossible Options: " + String.join(", ", options);
    }
}
