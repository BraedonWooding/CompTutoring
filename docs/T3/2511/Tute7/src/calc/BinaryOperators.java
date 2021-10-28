package calc;

import java.util.function.BiFunction;

public enum BinaryOperators {
    ADD(Double::sum),
    MULT((x, y) -> x * y),
    DIV((x, y) -> x / y),
    ;

    private BiFunction<Double, Double, Double> func;
    private BinaryOperators(BiFunction<Double, Double, Double> func) {
        this.func = func;
    }

    public double eval(double a, double b) {
        return func.apply(a, b);
    }
}
