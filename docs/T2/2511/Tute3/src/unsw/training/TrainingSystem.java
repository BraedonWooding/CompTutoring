package unsw.training;

import java.time.LocalDate;
import java.util.List;

public class TrainingSystem {
    private List<Seminar> seminars;

    public LocalDate bookTraining(String employee, List<LocalDate> availability) {
        for (LocalDate available : availability) {
            for (Seminar seminar : seminars) {
                if (seminar.canBook(employee, available)) {
                    return available;
                }
            }
        }
        return null;
    }
}
