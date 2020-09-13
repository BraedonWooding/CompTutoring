package unsw.training;

import java.time.LocalDate;
import java.util.List;

/**
 * An in person all day seminar with a maximum of 10 attendees.
 * @author Robert Clifton-Everest   
 *
 */
public class Seminar {
    private LocalDate start;

    private List<String> attendees;

    public LocalDate getStart() {
        return start;
    }

    private List<String> getAttendees() {
        return attendees;
    }

    public boolean tryAddAttendee(LocalDate available, String employee) {
        if (this.getStart().equals(available) &&
            this.getAttendees().size() < 10) {
            this.getAttendees().add(employee);
            return true;
        } else {
            return false;
        }
    }
}
