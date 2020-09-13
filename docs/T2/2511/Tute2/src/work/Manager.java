package work;

import java.time.LocalDate;

public class Manager extends Employee {
    private LocalDate hireDate;

    public LocalDate getHireDate() {
        return this.hireDate;
    }

    public Manager(String name, double salary, LocalDate hireDate) {
        super(name, salary);
        this.hireDate = hireDate;
    }

    @Override()
    public String toString() {
        return super.toString() + " " + this.getHireDate();
    }

    @Override()
    public boolean equals(Object other) {
        // 1) Check for null
        if (other == null) return false;
        // 2) Quick comparison (pointer comparison)
        if (this == other) return true;
        // 3) See if either the class is the exact same class
        //    or is a subclass (choose one of them)
        if (this.getClass() != other.getClass()) return false;

        // 4) Cast
        Manager m = (Manager) other;
        // 5) Comparisons
        return this.hireDate.equals(m.hireDate) && super.equals(other);
    }
}