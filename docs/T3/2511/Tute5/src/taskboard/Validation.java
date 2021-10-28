package taskboard;

public class Validation {
    private String errorText;

    private Validation(String errorText) {
        this.errorText = errorText;
    }

    public boolean isOk() {
        return errorText == null;
    }

    public String errorMessage() {
        return errorText;
    }

    public static Validation Ok() {
        return new Validation(null);
    }

    public static Validation Err(String errorText) {
        return new Validation(errorText);
    }

    public static Validation Validate(boolean condition, String ifError) {
        return condition ? Ok() : Err(ifError);
    }

    public Validation and(Validation other) {
        if (other.isOk()) {
            return this;
        } else if (this.isOk()) {
            return other;
        } else {
            return Err(this.errorText + "\n" + other.errorText);
        }
    }
}

/*

    Enrolment enrolment;

    try {
        enrolment = new Enrolment(student);
    } catch (EnrolmentException exception) {
        ...
    }

    Enrolment.tryEnrol(student).ifPresent((e) -> {

    })

    Children resources to a parent resource
    Result<T, TErr>

    HttpRequest request = loadUrl(...)
    if (request.isSuccess) {
        byte[] body = request.readBodyAsBytes();
        if (body != null) {
            Image img = Image.load(body);
            if (img != null) {
                return img;
            }
        }
    }

    loadUrl("kittens.org/kitten")               // Optional<HttpRequest<...>>
        .map(HttpRequest::readBodyAsBytes)      // Optional<byte[]>
        .map(Image::load)                       // Optional<Image>
*/
