# Factory Pattern

Factory pattern is an organic growing pattern, you begin with the simplest form and you expand it up and up as your needs get more complicated.

You'll use it quite a bit I presume for saving/loading.

The rough idea is that we want to put our big 'switch' statement as far away from our logic as possible and in some cases remove it entirely.

We start with a simple start this is called a 'factory method'

```java
// NOTE: this can sit in the main JSON input class (booking system)
Jump deserialize(JSONObject json) {
    var id = json.getString("id");
    switch (json.getString("type")) {
        case FunJump.TYPE: 
            return new FunJump(id, lookupMultiple(json.getJSONArray("skydivers")));
        case TandemJump.TYPE:
            return new TandemJump(id, lookup(json.getString("passenger")));
        case TrainingJump.TYPE:
            return new TrainingJump(id, (StudentSkydiver)lookup(json.getString("trainee")));
        default: return null;
    }
}
```

A few things to note;

- `FunJump.TYPE` is just a constant string to represent the type for FunJump this eliminates magic strings from our program (reducing coupling)
- LookupMultiple here is going to convert the array of names -> array of skydivers and Lookup is the same concept for a single name.

<details>
<summary>Side Note (implementation for lookups)</summary>

```java
// You would place these in the function (or you could have them take in arguments)

// .is just checks the names
// skydivers is a list of all skydivers
// more performant would be a dictionary/hashtable but eh who cares
// it's a simple example :)
Function<String, ASkydiver> lookup =
    (name) -> skydivers.stream().filter(s -> s != null && s.is(name)).findFirst().get();

// array taken in is a JSON Array so we have to cast each one
// personally I find 'collect' a bad idea in 99% of cases
// this is an okay exception though I probably would just use a
// heterogeneous array and write in place (most languages don't have
// performant ways of doing this though D:)
Function<JSONArray, List<LicensedSkydiver>> lookupMultiple = (array) ->
{
    return array.toList().stream()
        .map((name) -> (LicensedSkydiver)lookup.apply((String)name))
        .collect(Collectors.toList());
};
```

</details>

So effectively we still have a switch case but we've nicely placed it somewhere it's still not perfect and doesn't scale well.

What's the next step?  Push logic into classes pull concepts out!

We are going to push the JSON deserialisation into the classes!

```java
Jump deserialize(JSONObject json) {
    switch (json.getString("type")) {
        case FunJump.TYPE: return FunJump.deserialize(json);
        case TandemJump.TYPE: return TandemJump.deserialize(json);
        case TrainingJump.TYPE: return TrainingJump.deserialize(json);
        default: return null;
    }
}
```

We can still have the lookup functions and all that jazz but we'll have to pass a reference to them into the functions (or we could define an interface holding them and then make self implement such interface and pass self) I'm not gonna focus on that really because it's not too important.

What's next?  Well for your project this is 'fine' but if you want to go further!  We can use magic called reflection!  Reflection is really beyond the scope of this course but effectively it is us looking at properties of the objects at runtime i.e. grabbing the types of constructors, creating objects matching certain dynamic types and so on!

```java
Jump deserialize(JSONObject json) {
    var typeId = json.getString("type");
    // convert 'fun' -> 'Fun'
    var className = typeId.substring(0, 1).toUpperCase() + typeId.substring(1) + "Jump";
    try {
        Class<?> jumpClass = Class.forName("unsw.whatever." + className);
        Method method = jumpClass.getMethod("deserialize", JSONObject.class);
        return (Jump) jumpCtor.invoke(null, json);
    } catch (Exception e) {
        // class didn't exist or something handle it!
        // or...
        throw e; // yeet the problem to someone else (don't do this)
    }
```

Let's break it down!

- `Class<?>` is a class (yeh it's weird there is technically even `Class<Class<...>>` I believe... and so on) that refers to another class's runtime data.  In this case the `?` just states we give 0 care about what the class actually is!  In this case we could only use Object methods/overrides.  In other words `?` is kinda like `Object` but it allows you to do things like `List<?> list = new ArrayList<Integer>()` where as you can't do the same for Object (it's manual type erasure).
- Method is similar we are just grabbing a method (static or non-static) at runtime and then calling it!  We have to supply a name and series of args (to uniquely identify the overload)
    - `.invoke` just means call the method and we give null as the object it's performing the call on since it's a static function!

> Insert speel about abstract factory pattern being rarely what you want (in video) and how to 'level' up the abstract factory pattern!
