package calculator;

import java.util.function.Function;

public class UnaryExpression implements Expression {
    private Expression a;
    private Function<Expression, Double> operator;

    public UnaryExpression(Expression a,
                           Function<Expression, Double> operator) {
        this.a = a;
        this.operator = operator;
    }

    @Override
    public double compute() {
        return operator.apply(a);
    }
}