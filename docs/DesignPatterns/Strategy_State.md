# Strategy vs State

> Do I need state here?  Almost 80% of the time NO! It'll make the code worse!

State patterns are fantastic when you have clear transitional logic and furthermore your actual states themselves change behaviour.

Implementing a SwitchOn state and a SwitchOff state is almost never what you want at it's core it's just a boolean.

A general rule I quite like is this; if you have < 5 possible states state pattern is probably not what you want (unless those 5 possible states have very complicated transitional logic).

A good example of a state pattern would be a state machine, if you ever get the time look at an implementation of one and you'll realise just *how* complicated they are.  State pattern is a heavy duty pattern useful for heavy duty cases of complication not for a simple case!

You really really don't need it for the project so I'm just going to talk about strategy pattern (which is useful!).

This is purely going to be in the video initially... I'm sorry but I'll try to chuck up notes tonight on this part but honestly I didn't have much time for prep :(
