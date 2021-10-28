package calc;

public class AddExpression implements Expression {
    private Expression a, b;

    public AddExpression(Expression a, Expression b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public double evaluate() {
        return a.evaluate() + b.evaluate();
    }
}
