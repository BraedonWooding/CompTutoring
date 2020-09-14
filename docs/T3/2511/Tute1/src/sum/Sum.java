package sum;

import java.util.Arrays;
import java.util.Scanner;

public class Sum {
    public static void TraditionalWay() {
        Scanner sc = new Scanner(System.in);

        System.out.println("\nEnter some integers separated only by spaces: ");

        int sum = 0;
        String[] nums = sc.nextLine().split(" ");
        for (int i = 0; i < nums.length; i++) {
            sum += Integer.parseInt(nums[i]);
        }

        System.out.println("\nSum = " + sum);
        sc.close();
    }

    public static void NewerWayArray() {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("\nEnter some integers separated only by spaces: ");
            // "1 2 3 4 5"
            int[] nums = Arrays.stream(sc.nextLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x))
                .map(x -> x * 2)
                .toArray();
        }
    }

    public static void NewerWay() {
        // this is called try with resources!
        // it'll automatically close the scanner for you at the end of the '}'
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("\nEnter some integers separated only by spaces: ");

            // I'll talk about this in future tutorials
            // but the idea is that you convert the array of strings
            // into a 'stream' full of items (kinda like a pipe full of water)
            // and for each item as it flows through the stream you are
            // performing an action on that item.
            int sum = Arrays.stream(sc.nextLine().split(" "))
                // For each item convert it to an int
                // The `->` means create a temporary function!
                // we could also place this function elsewhere.

                // Don't worry if you don't understand this I'll talk about it
                // next week but x -> Integer.parseInt is the same as if I wrote
                // public static int ToInt(x) { return Integer.parseInt(x); }
                // and placed that outside of this function (line 21 or something)
                // then just wrote .mapToInt(ToInt);
                // Notice how much less code this is! and we don't just add
                // a bunch of random functions to do simple stuff like this.
                .mapToInt(x -> Integer.parseInt(x))
                // collect all the items and reduce them down into a sum
                // by adding up the previous value with the next kinda like
                // a lfold as you maybe learnt in 2521
                // i.e. 1 2 3 4 5 => (((((0 + 1) + 2) + 3) + 4) + 5)
                // this also is an anonymous function! (a function without a name)
                // sometimes this is called a 'lambda' or a 'closure'
                // (though there are some minor differences I'll probably
                // mention a bit later!)
                .reduce(0, (acc, b) -> acc + b);

            System.out.println("\nSum = " + sum);
        }
    }

    public static void main(String args[]) {
        // Comment the lines out to swap!
        NewerWay();
        // TraditionalWay();
    }
}