package taskboard.state;

import taskboard.Validation;

public class EstimationCard extends State {
    public EstimationCard(String assignee, int totalTimeEstimation, int totalTimeSpent) {
        super(assignee, totalTimeEstimation, totalTimeSpent);
    }

    @Override
    public Validation isValid(Object param) {
        return Validation.Validate(timeLeft() > 0, "Needs an estimation")
          .and(Validation.Validate(param instanceof String, "Needs an assignee"));
    }

    public void estimate(int hrs) {
        this.setEstimation(hrs);
    }

    @Override
    protected State nextState(Object param) {
        return new DevCard(this.getAssignee(), getEstimation(), getTimeSpent());
    }
}
