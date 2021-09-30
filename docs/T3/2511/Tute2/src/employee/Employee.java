package employee;

import java.time.LocalDate;

public class Employee {
    /**
     * All names joined by a space
     * i.e. Braedon Warren Wooding
     */
    private String name;

    /**
     * Salary measured in dollars.
     */
    private long salary;

    /**
     * Unique id, consists of a uuidv4 standard.
     */
    private String id;

    /**
     * DateFormat is UTC
     */
    private LocalDate hireDate, leaveDate;

    private EmployeePosition position;

    public Employee(String name, long salary, String id, LocalDate hireDate, EmployeePosition position) {
        this.name = name;
        this.salary = salary;
        this.id = id;
        this.hireDate = hireDate;
        this.setPosition(position);
    }

    public EmployeePosition getPosition() {
        return position;
    }

    public void setPosition(EmployeePosition position) {
        this.position = position;
    }

    public LocalDate getHireDate() {
        return hireDate;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return this.getClass().getName() +
            " [hireDate=" + hireDate + ", id=" + id +
            ", leaveDate=" + leaveDate + ", name=" + name +
            ", position=" + position + ", salary=" + salary +
            "]";
    }
}
