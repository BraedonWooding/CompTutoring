package lists;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class ListExample {
    public static boolean _tmp_2u23j23(String animal) {
        return animal.equals("pig");
    }

    public void processList(List<String> list) {

        // Find the Yak
        int index = list.indexOf("Yak");
        if (index != -1) System.out.print("Found a yak at " + index);

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).equals("Yak"))
                System.out.println("Found a Yak at " + i);
        }

        // we can expand the lambda x -> x.equals("pig")
        // by defining a local static function
        list.removeIf(ListExample::_tmp_2u23j23);
        list.removeAll(Arrays.asList("pig"));
        list.remove("pig"); // just remove first occurence

        // Remove "pig" from the list
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).equals("pig")) {
                list.remove(i);
                i--;
            }
        }

        // Print out all the animals except for those contains o's
        for (String animal : list) {
            if (animal.contains("o")) System.out.println("I'm scared of o's!");
            else                      System.out.println(animal);
        }

        list.stream()
            .filter(x -> x.contains("o") == false)
            .forEach(System.out::println);
        
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).contains("o"))
                System.out.println("I'm scared of o's!");
            else
                System.out.println(list.get(i));
        }

        // If the animal starts with an uppercase letter swap its position with
        // the previous animal, if there is one        
        for (int i = 1; i < list.size(); i++) {
            String animal = list.get(i);
            if (Character.isUpperCase(animal.charAt(0))) {
                Collections.swap(list, i, i - 1);
                // contentious!  I would argue adding this is a bug!
                i++;
            }
        }
    }

    public static void main(String[] args) {
        List<String> list = new ArrayList<String>();

        list.add("fish");
        list.add("duck");
        list.add("Cow");
        list.add("goat");
        list.add("pig");
        list.add("Yak");

        ListExample example = new ListExample();

        example.processList(list);

        System.out.println(list);
    }
}
