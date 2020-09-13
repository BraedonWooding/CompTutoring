package unsw.training;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;

public class TrainingSystem {

    public List<Trainer> trainers;

    public LocalDate bookTraining(String employee, List<LocalDate> availability) throws Exception {
        for (Trainer trainer : trainers) {
            LocalDate date;
            try {
                date = trainer.tryBook(availability, employee);
                return date;
            } catch (Exception ex) {
                continue;
            }
        }
        throw new Exception("Could not find a trainer");
        // return trainers.stream()
        //     .map(x -> x.tryBook(availability, employee))
        //     .filter(x -> x.isPresent())
        //     .map(x -> x.get())
        //     .findFirst();
    }
}
