package unsw.training;

import java.time.LocalDate;
import java.util.List;

/**
 * A trainer that runs in person seminars.
 *
 * @author Robert Clifton-Everest
 *
 */
public class Trainer {

    private String name;
    private String room;

    private List<Seminar> seminars;

    public boolean tryBook(LocalDate forDate, String employee) {
        return seminars.stream().anyMatch(s -> s.tryBook(forDate, employee));
    }
}
