package sum;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Sum {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        String line = sc.next();
        // generics <T>
        // Array<T> <=> T[]

        // regex is useful
        String[] values = line.split(" ");
        int total = 0;

        /* == C styled ==
        for (int i = 0; i < values.length; i++) {
            total += Integer.parseInt(values[i]);
        }
        */

        // == Java Styled ==
        for (String value : values) {
            total += Integer.parseInt(value);
        }

        // == (Extension) Streams ==
        // [ 1 2 3 ] => 1 -> 2 -> 3
        // 
        total = Arrays.stream(values)
            .mapToInt(Integer::parseInt)
            .sum();

        System.out.println(total);
    }
}