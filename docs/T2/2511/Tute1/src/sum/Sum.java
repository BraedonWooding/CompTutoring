package sum;

import java.io.IOException;
import java.util.Scanner;

public class Sum {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] items = line.split(" ");
        for (String item : items) {
            System.out.println(item);
        }
        sc.close();
    }
}