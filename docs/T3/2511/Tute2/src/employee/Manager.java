package employee;

import java.time.LocalDate;

public class Manager extends Employee {
    public Manager(String name, long salary, String id, LocalDate hireDate, EmployeePosition position) {
        super(name, salary, id, hireDate, position);
    }
    
    @Override
    public String getName() {
        return "Manager " + super.getName();
    }

    @Override
    public void setPosition(EmployeePosition pos) {
        
    }

    @Override
    public String toString() {
        return super.toString();
    }

}
