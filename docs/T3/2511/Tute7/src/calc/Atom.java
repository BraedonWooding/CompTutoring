package calc;

public class Atom implements Expression {
    private double value;

    public Atom(double value) {
        this.value = value;
    }

    @Override
    public double evaluate() {
        return value;
    }
}
