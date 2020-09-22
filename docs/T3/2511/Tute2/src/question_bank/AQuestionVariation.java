package question_bank;

public abstract class AQuestionVariation {
    private String name;
    private String title;
    
    public AQuestionVariation(String name, String title) {
        this.name = name;
        this.title = title;
    }
    
    public String GetName() {
        return this.name;
    }
    
    public String GetTitle() {
        return this.title;
    }
    
    public abstract Boolean IsValid(String option);
    
    @Override
    public String toString() {
        return this.title;
    }
}
