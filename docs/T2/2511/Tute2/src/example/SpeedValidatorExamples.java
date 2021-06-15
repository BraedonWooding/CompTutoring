package example;

public class SpeedValidatorExamples {
    public static class SpeedValidatorAnd implements SpeedValidator {
        private SpeedValidator a;
        private SpeedValidator b;

        public SpeedValidatorAnd(SpeedValidator a, SpeedValidator b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean isSpeedValid(int speed) {
            return a.isSpeedValid(speed) && b.isSpeedValid(speed);
        }
    }

    public static class SpeedValidatorDivisible implements SpeedValidator {
        private int divisible;

        public SpeedValidatorDivisible(int divisible) {
            this.divisible = divisible;
        }

        @Override
        public boolean isSpeedValid(int speed) {
            return speed % divisible == 0;
        }
    }

    public static class SpeedValidatorRange implements SpeedValidator {
        private int upper;
        private int lower;

        public SpeedValidatorRange(int lower, int upper) {
            this.upper = upper;
            this.lower = lower;
        }

        @Override
        public boolean isSpeedValid(int speed) {
            return speed >= lower && speed <= upper;
        }
    }

    public static SpeedValidator And(SpeedValidator a, SpeedValidator b) {
        return (s) -> a.isSpeedValid(s) && b.isSpeedValid(s);
    }

    public static SpeedValidator Range(int lower, int upper) {
        return (s) -> s >= lower && s <= upper;
    }

    public static void main(String[] args) {
        SpeedValidator validator = new SpeedValidatorAnd(new SpeedValidatorRange(0, 8000), new SpeedValidatorDivisible(6));
        System.out.println(validator.isSpeedValid(600));

        SpeedValidator validator2 = new SpeedValidator() {
            @Override
            public boolean isSpeedValid(int speed) {
                return speed % 6 == 0;
            }
        };

        SpeedValidator validator3 = And((int s) -> s % 6 == 0, (s) -> s >= 0 && s <= 6000);
    }
}
