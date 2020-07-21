# CS 3251: Intermediate Software Design
## Programming Assignment 7

## Overview

Over the past several weeks we have gotten quite familiar with the tree traversal application.  Currently, it can parse and execute simple math expressions using just the +, -, *, and / operations.

For this assignment you must extend the application to support the common power (^), modulus (%) and factorial (!) operations.  Clearly two are binary and the other unary (and left-associative).  Also, make sure your application supports the proper order of operations for these operators.

Second, you must implement the "get" command begun in class.  This command is only used in verbose mode.  It can be executed at any time the application is running in verbose mode.  It will print out the current value for the requested variable.  The get command should appear in the "menu" of available commands only after at least one variable has been set.  If get is called on an invalid variable (i.e. one that hasn't been given a value) print out an appropriate error message.

Third, you must implement the "list" command.  This command is only used in verbose mode.  It can be executed at any time the application is running in verbose mode.  It will print out all declared variables and their current value.  The list command should appear in the "menu" of available commands only after at least one variable has been set.  List executed when there are no variables prints out nothing.

Fourth, add a "history" command that prints out the last 5 commands entered in verbose mode (fewer if the the user hasn't entered 5 since the program began running - never more than 5).  This command is only for verbose mode, and it should appear in the verbose menu only after one or more commands have already been executed.  See below for an example (I have omitted the verbose menu for clarity):
```
    > format in-order
    > expr 5 + 5
    > print pre-order
        + 5 5
    > eval post-order
        10
    > history
        1) format in-order
        2) expr 5 + 5
        3) print pre-order
        4) eval post-order
```

Lastly, a couple of usability issues frustrates me:

A)  Some invalid expressions can cause the program to fail.  For example, on my computer the following will cause a crash:

  * 3 +
  * 3 * 5 /
  * / 4
  
    I suspect it is any time an operation doesn't have all of its needed operands.  Fix this so that it at least doesn't crash.  You do not need to worry about returning a correct answer since there isn't one. 

B)  In verbose mode I have to perfectly type commands (in lower case) or the program quits.  Make it so that capitalization of the commands does not matter and that an un recognized command just results in an appropriate error message.  Case should continue to matter for defining and using variables in verbose mode.


#### Sample Test Cases - Not Exhaustive!!!

Test Cases:

_operator !_
1) 5! = 120
2) 1! = 1
3) 1+5! = 121
4) -5! = -120
5) 5! + 1 = 121
6) 2 * 4! + 1 = 49
7) 0! = 1

_operator ^_
1) 2 ^ 5 = 32
2) 2 ^ 1 ^ 2 = 4
3) 1 + 2 ^ 3 = 9
4) -2 ^ 4 = -16
5) 2 ^ 3! = 64
6) 3! ^ 2 = 36
7) 3 ^ 2 + 1 = 10
8) 4 ^ 3 * 2 = 128

_operator %_
1) 5 % 3 = 2
2) 5 * 2 % 3 = 1
3) 5 ^ 3 % 7 = 6
4) 4! % 7 = 3
5) 4 + 1 % 5 = 5

_get command_
1) set a = 10
2) get a
```
    a: 10
```
3) get b
```
    Error: unknown variable "b"
```

_list command_
1) set a = 10
2) set b = 92
3) list
```
    a: 10  
    b: 92  
```

_Expressions That Cause Failure on My Machine_  
1) 3 +
2) 5 * 9 -
3) / 4
 

## Grading Criteria

This assignment will be graded differently than other assignments.  Do read the following carefully:

* Your submission must still compile successfully on Travis for both GCC and Clang and must pass the linter test.  But, there are no automated functional tests - i.e. no GoogleTests.  Your code will be compiled and run by the graders on their personal machines.

* Deductions will be based on the proportion of the manual tests that your application passes.  You will not be given the comprehensive list of tests (that is for your grader).  But, they will cover many of the same areas as the example tests listed above. 

* The graders will verify that the new operators are usable in both the verbose and succinct modes (see sample test cases).  And that the get, list and history commands are available in verbose mode.

* You must create appropriate new classes in both the "front-end" and "back-end" (i.e. new classes inheriting from ```Symbol```, ```Component_Node``` and ```Visitor```).  The new operations must be supported throughout the application, from the interpreter parsing the expression, to the generation of symbols, to all of the visitors.  Your solution must follow the patterns already established within the application.  You must use and extend the existing class structure to handle the new features.

* Do not change the two Travis files, but beyond that you are free to modify any and all files (include CMakeLists.txt) in order to implement the required functionality.

## Beyond 100

You can earn even more points on this assignment.  These extra points are strictly on this assignment, and you MUST have completed all of the primary portion of the assignment before you can earn any bonus points.  Only by earning 100% on the base part of the assignment can you get bonus points.  There will be no partial credit for the Beyond 100 work - either you get it right or you do not.
 
 ```Do or do not - there is no try``` - Yoda

Here we go:

* 20pts - add a "stats" command to print out the number of each operation used in the current expression.  This command can only be executed in verbose mode after a valid expression has been entered.  Only print statistics for operations that have been used.  Statistics must be calculated using a new Visitor-derived class.  So, for the expression ```10 * 9 % (3 + 4) * 6```, the stats command will output:  
 ```
     *: 2  
     %: 1  
     +: 1
 ```

* 30pts - provide better debugging information for when a bad expression is entered.  Currently, the application has really bad behavior when invalid expressions are entered.  Make this better:
    * Print an error message and point to where the invalid character is (--------^)
    * Don't halt the program.  Go back to the appropriate prompt (just ">" for succinct mode and list of valid choices for verbose mode) 
    * Test Cases (not exhaustive):
        
        \> 5 + 7 *
        
        ----------^ Error: Expecting right operand to *  
        
        \> / 4
        
        --^ Error: Expecting left operand to /

* 50pts - I have always wanted to be able to enter expressions in something other than in-order notation.  Enhance the front-end so that it supports both pre-order and post-order expression notation.  This should only be available in verbose mode.  Some points to consider:
   * The verbose mode menu must reflect that this is possible.
   * If you also are trying for the better debugger (see above), this enhancement must work in conjunction this that one.
   * All valid expressions (including parens) must be properly parsed.
   * This work likely requires a heavy refactoring of the Interpreter class so that there are multiple subclasses.  Take some time to think clearly about how you want to structure this. 
        

## Reminders

* Ensure that your name, vunetid, email address, and the honor code appear in the header comments of all files that you have altered.  This work must be strictly your own.

* All students are required to abide by the CS 3251 coding standard, [available on the course web page](https://vuse-cs3251.github.io/style-guidelines/) and provided to you on the first day of class. Points will be deducted for not following the coding standard.

* For full credit, your program must compile with a recent version of `clang` or `gcc` and run successfully with the CI platform.
  * The CI build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `linter` or `clang-format` in the CI build output log has an exit code of 1.

* Your program(s) should always have an exit code of 0.  A non-zero exit code (generally indicative of a segmentation fault or some other system error) is reason to worry and must be corrected for full points.
  
* When submitting the assignment, all files that are provided to you, plus your solution files have been submitted. All files necessary to compile and run your program must reside in the GitHub.com repository. 
