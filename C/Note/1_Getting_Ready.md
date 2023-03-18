# C

## Contents

- 1. Intro

***

## 1. Intro

### Basic info

**History:**

- Created in 1972
- Came from B language

**Virtues:**

- Powerful control structures (associated with an assembly language)
- Fast
- Compact code - small programs
- Portable to other computers (with little or no modification)
  - change a few entries in a header file

Function

- Operating system (Linux)
- languages: Compilers/interpreters(Python)
- Computer games
- PC applications
- Embedded systems: microprocessors in automobiles, cameras,...
- physics, robot, engineering, special effects for movies.

**Programmer Oriented：**

- Gives you access to hardware
- Enables you to manipulate individual bits in memory
- flexibility (less strict): both advantage and a danger
  - **the price of liberty is eternal vigilance**

>many software houses began turning to the **C++** language for large programming projects. C++ grafts object-oriented programming tools to the C language. ( Object-oriented programming is a philosophy that attempts to mold the language to fit a problem instead of molding the problem to fit the language.) C++ is nearly a superset of C, meaning that any C program is, or nearly is, a valid C++ program, too. By learning C, you also learn much of C++.

### How Computers Work

#### Components

- **CPU** (Central Processing Unit) 
  - most of the computing work (e.g., process programs)
- **RAM** (Random Access Memory)
  - a workspace to hold programs and files
- **SSD** (Solid State device) or **HD** (Hard Disk)
  - permanent memory storage device
- **peripherals** (keyboard, mouse, touchscreen, and monitor)
  - provide for communication between the computer and you

#### What Computers Do

CPU fetches an instruction from memory and executes it. It fetches the next instruction from memory and executes it, and so on. (A gigahertz CPU can do this about a billion times a second).
The CPU has its own small workspace, consisting of several **registers**, each of which can hold a number. One register holds the memory address of the next instruction, and the CPU uses this information to fetch the next instruction. After it fetches an instruction, the CPU stores the instruction in another register and updates the first register to the address of the next instruction. 
The CPU has a limited repertoire of instructions (known as the **instruction set**). many of them ask the computer to move a number from one location to another—for example, from a memory location to a register.

First, everything stored in a computer is stored as a number. 
Second, computer programs ultimately have to be expressed in a numeric instruction code, or what is called **machine language**.

If you want a computer to do something, you have to feed a particular list of instructions (a program) telling it exactly what to do and how to do it. You have to create the program in a language that the computer understands directly (machine language).

**e.g., adding two numbers**:

1. Copy the number in memory location 2000 to register 1.
2. Copy the number in memory location 2004 to register 2.
3. Add the contents of register 2 to the contents of register 1, leaving the answer in register 1.
4. Copy the contents of register 1 to memory location 2008.

#### High-level Computer languages and Compilers

Compiler
:  a program that translates the high-level language program into the detailed set of machine language instructions the computer requires.

In general, each computer design has its own unique machine language; so a program written in the machine language for, say, an Intel Core i7 CPU means nothing to an ARM Cortex-A57 CPU. But you can match a compiler to a particular machine language.

#### Language Standards

**Guiding Principles**: Keep the spirit of C

- Trust the programmer.
- Don’t prevent the programmer from doing what needs to be done.
- Keep the language small and simple.
- Provide only one way to do an operation.
- Make it fast, even if it is not guaranteed to be portable.

- C99 (1994)
- C11 (2007)

#### Using C: Seven Steps

Note that this is an idealization. In practice, particularly for larger projects, you would go back and forth, using what you learned at a later step to refine an earlier step.
For instance, when you are writing code, you might find that your plan was impractical. You may see a better way of doing things or, after you see how a program runs, you might feel motivated to change the design.

1. **Define the program objectives**
   1. thinking in general terms, not in terms of some specific
computer language.
   2. The larger and more complex the job is, the more planning it
requires. 
2. **Design the program**
   1. How the program will go about it?
   2. What should the user interface be like? How should the program be organized?
   3. Who will the target user be?
   4. How much time do you have to complete the program?
   5. How to represent the data in the program?
   6. which methods to use to process the data?
3. **Write the code**
4. **Compile**
5. **Run the program**
6. **Test and debug the program**
   1. Debugging: finding and fixing program errors.
7. **Maintain and modify the program**

#### Programming Mechanics

When you write a program in the C language, you store what you write in a text file called a **source code** file. Most C systems, including the ones we mentioned, require that the name of the file end in .c. The part of the name before the period is called the basename, and the part after the period is called the extension.

##### Object Code Files, Executable Files, and Libraries

43/1067