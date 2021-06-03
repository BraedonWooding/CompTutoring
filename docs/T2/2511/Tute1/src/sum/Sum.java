package sum;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Sum {
    public static void main(String args[]) throws IOException {
        // simple soln
        {
            Scanner sc = new Scanner(System.in);
            String line = sc.nextLine();
            String[] numbers = line.split(" ");
            int sum = 0;

            for (String string : numbers) {
                sum += Integer.parseInt(string);
            }
            System.out.println("Sum is: " + sum);
            sc.close();
        }

        {
            // more complicated example we delved into
            Scanner sc = new Scanner(System.in);
            File file = new File("ex.txt");
            FileWriter writer = null;

            try {
                writer = new FileWriter(file);
                String line = sc.nextLine();
                String[] numbers = line.split(" ");
                int sum = 0;

                for (String string : numbers) {
                    sum += Integer.parseInt(string);
                }

                writer.append("Sum is: " + sum);
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                sc.close();
                if (writer != null)
                    writer.close();
            }
        }
    }
}