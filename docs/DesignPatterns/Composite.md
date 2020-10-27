# Composite Pattern

Composite pattern is a nice way to handle recursive rules and is used in tons of cases!

We are going to represent a simple boolean language (might sound similar to what you peeps are doing :D).

```json
{
    "Rules": {
        "type": "OR",
        "args": [
            { "type": "EQUALS", "args": [1, 2] },
            {
                "type": "AND",
                "args": [
                    { "type": "LESS_THAN", "args": [5, 9] },
                    { "type": "EQUALS", "args": [0, 0] }
                ]
            }
        ]
    }
}
```

We are going to use 2 patterns to implement this.  The first one is 'composite' to represent the problem, then we'll use visitor to implement the evaluation.  The reason why visitor is nice here is that we can add new types independent of our composite.

We'll start with purely defining it in composite though!

```java

```
