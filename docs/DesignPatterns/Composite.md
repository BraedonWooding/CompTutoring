# Composite Pattern

Composite pattern is a nice way to handle recursive rules and is used in tons of cases!

We are going to represent a simple boolean language (might sound similar to what you peeps are doing :D).

```json
{
    "Rules": {
        "type": "OR",
        "args": [
            { "type": "EQUALS", "args": [true, false] },
            {
                "type": "AND",
                "args": [
                    { "type": "NOT_EQUALS", "args": [true, false] },
                    { "type": "EQUALS", "args": [true, true] }
                ]
            }
        ]
    }
}
```

Your composite nodes will be 'and' / 'or' or 'equals' / 'not equals' and your 'leaf' nodes will be 'true'/'false'.

In the case of your assignment you'll do AND/OR as composite (probably) with the leaf nodes being what?  think about what objects are the smallest and don't compose of anything?  Maybe the victory conditions?  Maybe something else?  Have a think!
