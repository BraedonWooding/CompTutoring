package unsw.training;

import java.time.LocalDate;
import java.util.List;

/**
 * An in person all day seminar with a
 * maximum of 10 attendees.
 * @author Robert Clifton-Everest
 *
 */
public class Seminar {
    private LocalDate start;

    private List<String> attendees;

    public boolean tryBook(LocalDate forDate, String employee) {
        if (start.equals(forDate) && attendees.size() < 10) {
            attendees.add(employee);
            return true;
        }
        return false;
    }
}
