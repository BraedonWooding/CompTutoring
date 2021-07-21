package calculator;

import java.util.function.BiFunction;

public class BinaryOpExpression implements Expression {
    public static enum Operator {
        Addition((a, b) -> a + b),
        Subtraction((a, b) -> a - b),
        Division((a, b) -> a / b),
        Multiplication((a, b) -> a * b),
        ;

        private BiFunction<Double, Double, Double> func;

        private Operator(BiFunction<Double, Double, Double> func) {
            this.func = func;
        }

        public double action(double a, double b) {
            return this.func.apply(a, b);
        }
    }

    private Expression a;
    private Expression b;
    private Operator op;

    public BinaryOpExpression(Expression a, Operator op, Expression b) {
        this.a = a;
        this.b = b;
        this.op = op;
    }

    public static BinaryOpExpression AddExpr(Expression a, Expression b) {
        return new BinaryOpExpression(a, Operator.Addition, b);
    }

    @Override
    public double compute() {
        return op.action(a.compute(), b.compute());
    }
}
