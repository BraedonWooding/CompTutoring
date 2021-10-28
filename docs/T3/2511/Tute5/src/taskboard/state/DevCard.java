package taskboard.state;

import taskboard.Validation;

public class DevCard extends State {

    public DevCard(String assignee, int totalTimeEstimation, int totalTimeSpent) {
        super(assignee, totalTimeEstimation, totalTimeSpent);
        //TODO Auto-generated constructor stub
    }

    @Override
    public Validation isValid(Object param) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    protected State nextState(Object param) {
        // TODO Auto-generated method stub
        return null;
    }
    
}
