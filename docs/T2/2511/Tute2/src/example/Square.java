package example;

import java.util.List;

public class Square extends Shape {
    private int length;

    public Square(String color, int length) {
        super(color);
        this.length = length;
        System.out.println("Inside of Square constructor");
    }

    @Override
    public int GetArea() {
       return length * length;
    }
}
