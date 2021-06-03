package example;

/**
 * Prints "Hello World" to the console.
 */
public class HelloWorld {
    public void A(String[] args) {
        String arg = args[2];
    }

    public static void main(String[] args) {
        System.out.println("Hello World!");

        for (int i = 0; i < 10; i++) {
            System.out.println(i);
        }

        String[] myArgs = new String[]{ "A", "B" };
        new HelloWorld().A(myArgs);
    }
}
