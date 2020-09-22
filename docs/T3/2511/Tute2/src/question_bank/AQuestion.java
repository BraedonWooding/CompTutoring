package question_bank;

import java.util.List;
import java.util.Random;

public abstract class AQuestion {
    private String name;
    private List<AQuestionVariation> variations;

    protected AQuestion(String name, List<AQuestionVariation> variations) {
        this.name = name;
        this.variations = variations;

        // this.variation_names = variations.stream()
        //     .map(x -> x.GetName())
        //     .collect(Collectors.toList());
        // this.variation_map = variations.stream()
        //     .collect(Collectors.toMap(x -> x.GetName(), x -> x));
    }
    
    public String GetName() {
        return name;
    }

    protected abstract String AskQuestion(AQuestionVariation variation);

    public String RandomlyAskQuestion(Random rng) {
        int next = rng.nextInt(variations.size());
        AQuestionVariation variation = variations.get(next);
        return AskQuestion(variation);
    }
}
