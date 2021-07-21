package calculator;

/**
* @author Nick Patrikeos
**/
public class Calculator {

    private Expression expression;

    public Calculator(Expression expression) {
        this.expression = expression;
    }

    public void fizzbuzz() {
        for (int i = 0; i < 100; i++) {
            if (i % 15 == 0) {
                System.out.println("FizzBuzz");
            } else if (i % 3 == 0) {
                System.out.println("Fizz");
            } else if (i % 5 == 0) {
                System.out.println("Buzz");
            } else  {
                System.out.println(i);
            }
        }
    }

    /**
     * @return computed expression
     */
    public double calculate() {
        return expression.compute();
    }

}
