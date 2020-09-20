package work;

// This version is more what we would expect for your lab

public class EmployeeLab {
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
    public EmployeeLab(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    @Override()
    public String toString() {
        return this.getFullName() + " " + this.getReadableSalary();
    }
}
