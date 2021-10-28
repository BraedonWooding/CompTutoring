package calc;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

public class TestExpression {
    @Test
    public void Test1() {
        Expression e = new AddExpression(new AddExpression(new Atom(1), new Atom(2)), new Atom(4));
        assertEquals(7, e.evaluate());
    }

    @Test
    public void Test2() {
        Expression e = new BinaryExpression(BinaryOperators.ADD, new BinaryExpression(BinaryOperators.ADD, new Atom(1), new Atom(2)), new Atom(4));
        assertEquals(7, e.evaluate());
    }
}
