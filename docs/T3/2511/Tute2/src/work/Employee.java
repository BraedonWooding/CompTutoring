package work;

// You can use 'Date' or string too but as a student mentioned LocalDate
// is soooo much nicer to work with :)
import java.time.LocalDate;
import java.util.Objects;

public class Employee {
    private String name;
    private double salary;

    /**
     * Get the employee's full name
     * i.e. "Braedon Wooding"
     */
    public String getFullName() {
        return this.name;
    }

    /**
     * Get the employee's first name
     * as in the first space delimited word
     */
    public String getFirstName() {
        return this.name.split(" ")[0];
    }

    /**
     * Get the employee's last name
     * as in the second space delimited word
     */
    public String getLastName() {
        return this.name.split(" ")[1];
    }

    /**
     * Returns employee's salary in terms of dollars.s
     */
    public double getSalary() {
        return this.salary;
    }

    /**
     * Returns employee's salary in terms of thousands of dollars postfixed
     * with a 'K'
     */
    public String getReadableSalary() {
        return this.salary / 1000 + "K";
    }

    /**
     * Update employee details.
     * @param newName If this is null it won't update the name.
     */
    public void updateEmployeeDetails(String newName, double newSalary) {
        this.salary = newSalary;
        if (newName != null) this.name = newName;
    }

    /**
     * Create a new employee
     * @param name Employee's full name
     * @param salary Employee's salary initially in terms of dollars
     */
    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    @Override()
    public String toString() {
        return this.getFullName() + " " + this.getReadableSalary();
    }

    @Override()
    public boolean equals(Object other) {
        // 1) Check for null
        if (other == null) return false;
        // 2) Quick comparison (pointer comparison)
        if (this == other) return true;
        // 3) See if either the class is the exact same class
        //    or is a subclass (choose one of them)
        // !(other instanceof Employee) is not a viable strategy here
        // as explained in the tute.
        if (this.getClass() != other.getClass()) return false;

        // 4) Cast
        Employee e = (Employee) other;
        // 5) Comparisons
        return this.salary == e.salary && this.name.equals(e.name);
    }

    public static void main(String arg[]) {
        Employee e = new Employee("Sasha", 4000);
        e.toString();
        Object o = e;
        o.toString();

        Manager m = new Manager("Sasha", 4000, LocalDate.now());
    }
}
