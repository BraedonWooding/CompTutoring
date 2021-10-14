package unsw.training;

import java.time.LocalDate;
import java.util.List;
import java.util.stream.Stream;

public class TrainingSystem {
    private List<Trainer> trainers;

    public LocalDate bookTraining(String employee, List<LocalDate> availability) {
        return availability.stream()
            .filter(date -> trainers.stream().anyMatch(trainer -> trainer.tryBook(date, employee)))
            .findFirst().orElse(null);
    }
}
