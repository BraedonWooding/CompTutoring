package unsw.training;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;

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

    public List<Seminar> getSeminars() {
        return seminars;
    }

    public LocalDate tryBook(List<LocalDate> availability, String employee) throws Exception {
        for (Seminar seminar : this.getSeminars()) {
            for (LocalDate available : availability) {
                if (seminar.tryAddAttendee(available, employee)) {
                    return available;
                }
            }
        }
        throw new Exception("No seminar available");
    }
}
