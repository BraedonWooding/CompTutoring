package calc;

public class BinaryExpression implements Expression {
    private BinaryOperators op;
    private Expression a, b;

    public BinaryExpression(BinaryOperators op, Expression a, Expression b) {
        this.op = op;
        this.a = a;
        this.b = b;
    }

    @Override
    public double evaluate() {
        return op.eval(a.evaluate(), b.evaluate());
    }
}
