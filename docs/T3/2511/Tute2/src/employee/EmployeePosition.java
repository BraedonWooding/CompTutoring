package employee;

public enum EmployeePosition {
    LECTURER("STD_PAY_LEC"),
    ASSOCIATE_PROFESSOR("STD_PAY_ASSOC_LEC"),
    ;

    private EmployeePosition(String payCode) {
        this.payCode = payCode;
    }

    private String payCode;

    public String getPayCode() {
        return payCode;
    }
}
