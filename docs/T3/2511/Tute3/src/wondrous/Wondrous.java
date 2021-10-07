package wondrous;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Wondrous {
    public List<Integer> wondrous(int start) {
        if (start < 1) {
            throw new IllegalArgumentException("start has to be greater than 1");
        }

        int current = start;
        List<Integer> sequence = new ArrayList<Integer>();

        // stop early, since a starting term of 1
        // always produces an empty list
        if (start == 1) return sequence;

        while (current != 1) {
            sequence.add(current);
            if (current % 2 == 0) {
                current /= 2;
            } else {
                current = (current * 3) + 1;
            }
        }

        sequence.add(1);

        return sequence;
    }

}