# Composite Pattern

Composite pattern is a nice way to handle recursive rules and is used in tons of cases!

We are going to represent a simple boolean language (might sound similar to what you peeps are doing :D).

```json
{
    "Rules": {
        "type": "OR",
        "args": [
            { "type": "EQUALS", "args": [true, false] },
            {
                "type": "AND",
                "args": [
                    { "type": "NOT_EQUALS", "args": [true, false] },
                    { "type": "EQUALS", "args": [true, true] }
                ]
            }
        ]
    }
}
```

We are going to use 2 patterns to implement this.  The first one is 'composite' to represent the problem, then we'll use visitor to implement the evaluation.  The reason why visitor is nice here is that we can add new types independent of our composite.

We'll start with purely defining it in composite though!

```java
public interface CompositeEvaluator {
    public boolean getResult(List<Boolean> arg);
}

public class EvaluatorFactory {
    private static final Map<String, BiFunction> evaluators = new HashMap<>();
    
    static {
        evaluators.put("EQUALS", (b1, b2) -> b1.equals(b2));
        evaluators.put("NOT_EQUALS", (b1, b2) -> !b1.equals(b2));
        evaluators.put("AND", (b1, b2) -> b1.logicalAnd(b2));
        evaluators.put("OR", (b1, b2) -> b1.logicalOr(b2));
    }

    public static CompositeEvaluator getCompositeEvaluator(String name) {
        var eval = evaluators.get(name);
        return (a) ->
            a.stream().reduce(a.size() > 0 ? a.get(0) : Boolean.TRUE, eval);
    }
}

public class ExpressionFactory {
    private static Expression deserializeLeaf(JSONObject json) {
        // Get type 
    }
    
    private static Expression deserializeComposite(JSONObject json) {
        
    }
    
    private static Expression getValue(JSONObject json) {
        
    }

    public static Expression deserialize(JSONObject json) {
        
    }
}

public class LeafExpressionCondition {
    private Expression a;
    private Expression b;
    private Evaluator eval;
    
    public LeafExpressionCondition(Evaluator eval, Expression a, Expression b) {
        this.eval = eval;
        this.a = a;
        this.b = b;
    }
    
    public boolean getResult() {
        return eval.getResult(a, b);
    }
}

public class LeafExpressionValue {
    private int value;
    
    public LeafExpressionValue() {
    
    }
}

public class CompositeExpression {
    private List<Expression> subObjects = new ArrayList<>();
    
    private Composite(List<Expression> expressions)
    
    public static Composite deserialize() {
        
    }
}
```
