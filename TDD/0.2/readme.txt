Project Milestone v 0.2

1) A class structure of tables is implemented.  Table is an abstract base class
   with the member function Play() being pure abstract
2) In the "Evaluate Poker Hands" menu, choosing a game type results in the 
   creation of a table of appropriate type and Play() is called on that table.
3) A class structure of evaluators is implemented.  An object of the appropriate
   evaluator is implemented as a singleton object
4) The "Choose Evaluator" menu manages the construction and destrcution of the
   chosen evaluators.
5) No other functionality is implemented.   