package example;

/**
 * Prints "Hello World" to the console.
 */
public class HelloWorld {
    public static String getWelcomeMsg() {
        return "Hello World";
    }

    public static void outputWelcomeMsg(String s) {
        System.out.println(s);
    }

    public static void entry() {
        // ...
        String str = getWelcomeMsg();
        outputWelcomeMsg(str);
    }
}
