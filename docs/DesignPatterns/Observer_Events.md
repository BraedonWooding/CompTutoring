# Observers vs Events

TLDR: Observer pattern is just a restricted event and is 'rarely' what you really want (exception is UI <-> backend linking of text / visuals)

Often in our programming we want to be able to react to things! (WOW!)

Event based design is in some ways a 'programming paradigm' but in reality it's quite a small subset of one (outside of languages like Erlang) in a similar way to data oriented design (though that's actually commonly a misconception data oriented design especially when you get into transactional views get's quite cool!) so we'll count it as a pattern :).

Anywho, events are pretty straightforward conceptually and most languages (C#) for example support them by default.  Java does not.  So we'll do all the work for them :).

Let's begin by just defining a simple event that will trigger every time we send an email!

```java
public interface IDispatchListener {
    /**
     * We'll 'break' OOP a little here for security reasons
     * passing the entire Send object or even just trying to take
     * a subclass of it to send to 'hide' the recipient is a really
     * really bad idea.  Especially if this is a non secure library, it would suck if someone managed to register this event behind the scenes and got every email address we sent to :).
     **/
    public void onSuccessfulDispatch(SendType type, String contents);
    
    // you could add multiple events here
    // adding 'default' before them lets you specify a default implementation
    // the important thing about a default implementation is that
    // it let's you have 'optional' events.
    public default void onFailedDispatch(SendType type, String contents) {
    }
}

public class Dispatcher {
    private List<IDispatchListener> listeners = new ArrayList<>();
    
    public void registerOnDispatch(IDispatchListener listener) {
        this.listeners.add(listener);
    }
    
    public void deregisterOnDispatch(IDispatchListener listener) {
        this.listeners.remove(listener);
    }
    
    private void triggerOnSuccessfulDispatch(Send send) {
        this.listeners.forEach(x -> x.onSuccessfulDispatch(send.getType(), send.getContents()));
    }
    
    // and same for unsuccessful!
    
    public void dispatch(Send send) {
        // ... process send and all that stuff
        // ...
        // this could even occur like 10 yrs in the future
        // like you could wait till you can reconcile
        // that the send was successful
        triggerOnSuccessfulDispatch(send);
    }
}
```

Now this was a lot of code to do a single event!  What does it look like on the callers side?  Well they have 3 options;

## Option 1) Implement the interface

```java
public class SendAgent implements IDispatchListener {
    private Dispatcher dispatcher;

    public void onSuccessfulDispatch(SendType type, String contents) {
        // whatever...
    }

    // maybe we don't want failure so we can just not have it
    
    public SendAgent() {
        dispatcher = new Dispatcher();
        dispatcher.registerOnDispatch(this);
    }
}
```

Why would we want to do this?  Well sometimes events may occur at sometime in the future (or aren't always based on our action) this is like a 'callback' of sorts.

## Option 2) Anonymous Class

Sometimes though we want to perform some action with a context or we are trying to register an event that isn't necessarily related to us in this case anonymous class makes sense.

```java
dispatcher.registerOnDispatch(new IDispatchListener() {
    public void onSuccessfulDispatch(SendType type, String contents) {
        // whatever...
    }

    public void onFailedDispatch(SendType type, String contents) {
        // whatever...
    }
});
```

## Option 3) Lambda

This will ONLY work if there is only one function to implement

> I'm not even sure if it'll compile here... even with the default method it may though :)

This is very useful for your typical observers!

```java
dispatcher.registerOnDispatch((sendType, contents) -> {
    // do whatever...
});
```

## Side Note 'functional' part of Java

Java has honestly pretty terrible functional support (streams is 'good' but not even near as good as other language's equivalent systems).

But it does have a 'few' sample functions already [here](https://docs.oracle.com/javase/8/docs/api/java/util/function/package-summary.html) so if you need just a simple function feel free to use above (just make sure the function 'point' is somewhat readable).

## Observers

Observers are just a simplification of this to just a single event rather than multiple and furthermore that event triggers on every 'set' and holds the previous and new value.

It would look something like below;

```java
package unsw.whatever;

import java.util.ArrayList;
import java.util.List;

import java.util.function.BiConsumer;

/**
 * Represents an object that is observable
 * i.e. an object that you can listen to and will be notified of any mutations.
 * 
 * @author Braedon Wooding
 */
public final class Observable<T> {
    private T obj;

    private List<BiConsumer<T, T>> listeners = new ArrayList<>();

    /**
     * Construct a new observable.
     * 
     * @param obj The initial state.
     */
    public Observable(T obj) {
        this.obj = obj;
    }

    /**
     * Observe this object for all updates.
     * 
     * @param listener A function to call every time the event fires.
     */
    public void observe(ObservableListener<T> listener) {
        listeners.add(listener);
    }

    /**
     * Clears all observers/listeners from this object.
     */
    public void clearObservers() {
        listeners.clear();
    }

    /**
     * Update this objects state and notify all observers.
     * 
     * @param obj The new state.
     */
    public void update(T obj) {
        T old = this.obj;
        this.obj = obj;
        for (BiConsumer<T, T> listener : listeners) {
            listener.apply(old, obj);
        }
    }

    /**
     * Unwrap the object's state.
     * 
     * @return The current state
     */
    public T getObj() {
        return obj;
    }
}
```

Then you could use it like this;

```java
public static void main(String[] args) {
    Observable<Integer> _int = new Observable<>(Integer.valueOf(2));
    _int.observer((oldValue, newValue) -> {
        System.out.println("Old value is " + oldValue + " and new value is " + newValue);
    });
    _int.update(10);
    _int.update(-10);
}
```
