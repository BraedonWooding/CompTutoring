package calc;

public class MultExpression implements Expression {
    private Expression a, b;

    public MultExpression(Expression a, Expression b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public double evaluate() {
        return a.evaluate() * b.evaluate();
    }
}
