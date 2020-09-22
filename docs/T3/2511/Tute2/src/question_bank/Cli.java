package question_bank;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Random;

import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;

public class Cli {
    public static void main(String args[]) throws IOException, Exception {
        try (InputStream reader = new FileInputStream("resources/bank/questions.json")) {
            JSONTokener tokener = new JSONTokener(reader);
            JSONArray array = new JSONArray(tokener);
            System.out.println(array.toString(4));
            Random rng = new Random();
            
            for (Object o : array) {
                AQuestion q = QuestionFactory.GetQuestion((JSONObject)o);
                System.out.println(q.RandomlyAskQuestion(rng));
            }
        }
    }
}
