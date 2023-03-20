# 2 Introducing C

## Contents

- A Simple Example Explained
- The Structure of a Simple Program
- Tips on Making your Programs Readable
- Multiple Functions
- Introducing Debugging
- Keywords and Reserved Identifiers

## A Example Explained

C programs consist of one or more functions, the basic modules of a C program

The `first.c` Program

```c
#include <stdio.h>  // include another file: stdio.h package 
int main(void) {  // int: returns an integer; void: no argument
    int num;  // declaration statement
    num = 1;  // assignment statement

    printf("My favorite number is %d because it is first. \n", num);  // function call statement
    // %d: where and in what form to print the value of num .

    return 0;  // return statement
}
```

### Program Details

#### `#include` Directives and Header Files

The effect of `#include <stdio.h>` is the same as if you had typed the entire contents of the `stdio.h` file into your file at the point where the `#include` line appears. In effect, it’s a cut-and-paste operation. `include` files provide a convenient way to share information that is common to many programs.

Preprocessing
: The `#include` statement is an example of a C preprocessor directive. In general, C compilers perform some preparatory work on source code before compiling.

`stdio.h`
: is supplied as part of all C compiler packages. It contains information about input and output functions, such as printf(), for the compiler to use. The name stands for standard input/output header.

header
: a collection of information that goes at the top of a file.

For the most part, **header** files contain information used by the compiler to build the final executable program. For example, they may define constants or indicate the names of functions and how they should be used. But the actual code for a function is in a library file of precompiled code, not in a header file. The linker component of the compiler takes care of finding the library code you need. In short, header files help guide the compiler in putting your program together correctly.

> **Note Why Input and Output Are Not Built In**
> Not all programs use this I/O (input/output) package, and part of the C philosophy is to avoid carrying unnecessary weight. This principle of economic use of resources makes C popular for embedded programming—for example, writing code for a chip that controls an automotive fuel system or a Blu-ray player. Incidentally, the #include line is not even a C language statement! The `#` symbol in column 1 identifies the line as one to be handled by the C preprocessor before the compiler takes over.

#### The `main()` Function

You are free to choose names for other functions you use, but `main()` must be there to start things. What about the parentheses? They identify `main()` as a function.

The `int` means that the kind of value `main()` can return is an integer. Return where? To the operating system.

#### Comments

- one line: `/comment/`
- more than one line: `/* comment */`

#### Braces, Bodies, and Blocks

In general, all C functions use braces `{}` to mark the beginning as well as the end of the body of a function. Their presence is mandatory, so don’t leave them out.
Braces can also be used to gather statements within a function into a unit or block.

#### Declarations

The declaration statement is one of C’s most important features. `int num;` declares two things. First, somewhere in the function, you have a variable called `num`. Second, the `int` proclaims num as an integer (a data type). 
The compiler uses this information to arrange for suitable storage space in memory for the num variable. The semicolon at the end of the line identifies the line as a C statement or instruction. The **semicolon** is part of the statement, not just a separator between statements.

C keyword
: Keywords are the words used to express a language, and you can’t use them for other purposes. For instance, you can’t use `int` as the name of a function or a variable.

identifier
: a name you select for a variable, a function, or some other entity.

**Declaration** connects a particular identifier with a particular location in computer memory, and it also establishes the type of information, or data type, to be stored at that location.

> In C, all variables must be declared before they are used.

Traditionally, C has required that variables be declared at the beginning of a block with no other kind of statement allowed to come before any of the declarations:

```c
int main() // traditional rules
{
int doors, dogs;
doors = 5;
dogs = 3;
// other statements
}
```

C99 and C11, following the practice of C++, let you place declarations about anywhere in a block. However, you still must declare a variable before its first use:

```c
int main() // current C rules
{
// some statements
int doors;
doors = 5; // first use of doors
// more statements
int dogs;
dogs = 3; // first use of dogs
// other statements
}
```

For greater compatibility with older systems, this book will stick to the original convention.

##### Name Choice

You should use meaningful names for variables. If the name doesn’t suffice, use comments to explain what the variables represent.

With C99 and C11 you can make the name of an identifier as long as you want, but the compiler need only consider the first 63 characters as significant. For external identifiers only 31 characters need to be recognized.

The characters at your disposal are lowercase letters, uppercase **letters**, **digits**, and the **underscore** (_). The first character must be a letter or an underscore.

Operating systems and the C library often use identifiers with one or two initial underscore characters, such as in `_kcab`, so it is better to **avoid** that usage yourself.

C names are **case sensitive**, meaning an uppercase letter is considered distinct from the corresponding lowercase letter. Therefore, `stars` is different from `Stars` and `STARS`.

##### Four Good Reasons to Declare Variables

- Putting all the variables in one place makes it easier for a reader to grasp what the program is about.
- Thinking about which variables to declare encourages you to do some planning before plunging into writing a program.
- Declaring variables helps prevent one of programming’s more subtle and hard-to-find bugs—that of the misspelled variable name.
- Your C program will not compile if you don’t declare your variables. If the preceding reasons fail to move you, you should give this one serious thought.

#### Assignment

=
: assignment operator

#### Return Statement

If you leave out the return statement for `main()`, the program will return 0 when it reaches the closing `}`. So you can omit the return statement at the end of `main()`. However, you can’t omit it from other functions, so it’s more consistent to use it in `main()`, too.

***

## The Structure of a Simple Program

Header
: contains the function name along with information about the type of information passed to the function and returned by the function.

Body
: enclosed by braces (`{}`) and consists of a series of statements, each terminated by a semicolon (`;`).

***

## Tips on Making your Programs Readable

- Choose meaningful variable names
- Use comments
- Using blank lines to separate one conceptual section of a function from another.
  - a blank line separating the declaration section from the action section
- One line per statement
  - C has a free-form format. You can place several statements on one line or spread one statement over several. it's legitimate, but ugly

***

## Multiple Functions

```c
//* two_function.c -- a program using two functions in one file */
#include <stdio.h>
void butler(void);  /* ANSI/ISO C function prototype */
int main(void) 
{
    printf("I will summon the butler function");
    butler();  // function call
    printf("Yes, Bring me some tea and writeable DVDs.\n");

    return 0;
}

void butler(void)  /* function definition */
{
    printf("You rang, sir?\n");
} 
/* output:
    I will summon the butler function.
    You rang, sir?
    Yes. Bring me some tea and writeable DVDs. 
*/
```

> void butler(void): For older compilers, omit the second void.

Prototype
: declares to the compiler that you are using a particular function, so it’s called a **function declaration**. It also specifies properties of the function.

function definition
: the source code for the function itself.

All C programs begin execution with `main()`, no matter where `main()` is located in the program files.
However, the usual C practice is to list `main()` first because it normally provides the basic framework for a program.
The location of everything in `main()` determines when they are executed.

## Introducing Debugging

Syntax Errors
: Use valid symbols in the wrong places.

> A true syntax error in one location might cause the compiler to mistakenly think it has found other errors.
> In fact, if you can’t make sense of all the reported errors, rather than trying to correct all the reported errors at once, you should correct just the first one or two and then recompile; some of the other errors may go away.

Semantic Errors
: when you follow the language rules correctly but to an incorrect end.

Program State
: the set of values of all the variables at a given point in program execution.

- Executing the program step-by-step yourself
- Sprinkle extra printf() statements throughout to monitor the values of selected variables at key points in the program.
- debugger: a program that enables you to run another program step-by-step and examine the value of that program’s variables.

***

## Keywords and Reserved Identifiers

Keywords
: the vocabulary of C. Because they are special to C, you can’t use them as identifiers, for example, or as variable names.

Reserved identifiers
: They don’t cause syntax errors because they are valid names. However, the language already uses them or reserves the right to use them, so it could cause problems if you use these identifiers to mean something else.
: include those beginning with an underscore character and the names of the standard library functions, such as `printf()`.

### ISO C Keywords

| | | | |
| - | - | - | - |
| auto | extern | short | while |
| break | float | **signed** | **_Alignas** |
| case | for | sizeof | **_Alignof** |
| char | goto | static | **_Bool** |
| **const** | if | struct | **_Complex** |
| continue | inline | switch | **_Generic** |
| default | int | typedof | **_Imaginary** |
| do | long | union | **_Noreturn** |
| double | register | unsigned | **_Static_assert** |
| else | restrict | void | **#_Thread_local** |
| **enum** | return | **volatile** | |
