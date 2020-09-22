package question_bank;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

import org.json.JSONArray;
import org.json.JSONObject;

public class QuestionFactory {
    private static AQuestionVariation GetQuestionVariationSelect(JSONObject obj) {
        String name = obj.getString("name");
        String title = obj.getString("title");
        List<String> options = new ArrayList<String>();

        for (Object o : obj.getJSONArray("options")) {
            options.add(o.toString());
        }
        return new SelectQuestionVariation(name, title, options);
    }

    public static AQuestion GetQuestion(JSONObject obj) throws Exception {
        String type = obj.getString("type");
        String name = obj.getString("name");
        
        switch (type) {
            case "select": {
                Boolean isMultiSelect = obj.getBoolean("multiSelect");
                JSONArray array = obj.getJSONArray("variations");
                
                List<AQuestionVariation> variations = new ArrayList<>();
                for (Object o : array) {
                    JSONObject inner_obj = (JSONObject)o;
                    variations.add(GetQuestionVariationSelect(inner_obj));
                }
                
                return new SelectQuestion(name, isMultiSelect, variations);
            }
            case "text": {
                return null;
            }
            default: throw new Exception("Unknown type: " + type);
        }
    }
}
