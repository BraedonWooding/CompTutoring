package example;

public class Rectangle extends Shape {
    private int width;
    private int height;

    public Rectangle(String color, int width, int height) {
        super(color);
        this.width = width;
        this.height = height;

        System.out.println("Inside rectangle constructor");
    }
    
    public void changeWidth(int width) {
        this.width = width;
    }

    public void changeHeight(int height) {
        this.height = height;
    }
    
    public static Rectangle GetRedRectangle(int width, int height) {
        return new Rectangle("red", width, height);
    }

    @Override
    public int GetArea() {
        return width * height;
    }
    
    public static void main(String[] args) {
        Rectangle r = Rectangle.GetRedRectangle(10, 20);
        System.out.println(r.GetArea());
    }
}
