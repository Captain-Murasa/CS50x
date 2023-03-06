# 0. Scratch

## Computational Thinking

计算机是一个**黑箱(black box）**，它接受一些输入，并产生一些输出。

![Black box with input and output](https://cs50.harvard.edu/x/2023/notes/0/cs50Week0Slide38.png)

编程语言的基本构成要素：

- functions

- - arguments, return values

- conditionals

- Boolean expressions

- loops

- variables

- ...

## Scratch 

Address: https://scratch.mit.edu/

Scratch is a **visual** programming language developed by MIT.

Tutorials:

- [Scratch - Imagine, Program, Share](https://scratch.mit.edu/projects/editor/?tutorial=all) 
- [Scratch - Starter Projects](https://scratch.mit.edu/starter-projects)

Examples:

- [Ivy’s Hardest Game](https://scratch.mit.edu/projects/565742837)
- [Oscartime](https://scratch.mit.edu/projects/277537196) 
- [Soccer](https://scratch.mit.edu/projects/37413/), a game
- [Cookie Love Story](https://scratch.mit.edu/projects/26329196/), an animation
- [Gingerbread tales](https://scratch.mit.edu/projects/277536784/), an interactive story
- [Intersection](https://scratch.mit.edu/projects/75390754/), a game
- [Hogwarts](https://scratch.mit.edu/projects/422258685), a game

---

# 1. C

## CS50 IDE

CS50 uses **cloud-based IDE**. You can open VS Code at [code.cs50.io](https://code.cs50.io/).

- Start writing source code by executing `code hello.c`

- Compile your code by executing `make hello`, if source code name is `hello.c` 
- Debug for `debug50 hello`
- Test your code style by executing `style50 hello.c` 
  -  [CS50's style guide for C](https://cs50.readthedocs.io/style/c/) 

- CS50 provides its own library `cs50.h` to make programming easier:
  - new data type: bool、string
  - easier input: `get_string()`、`get_int()`...

> VS Code utilizes a compiler called `clang` or *c language*.
>
> - Use `clang -o hello hello.c` to compile.
> - If want some library in, use command like `clang -o hello hello.c -lcs50`.

## Magic Number

C provides a **preprocessor directive** (also called a **macro**) for creating **symbolic constants**. 

- `#define NAME REPLACEMENT` 

At the time your program is compiled, `#define` goes through your code and **replaces** `NAME` with `REPLACEMENT`. 

- If `#include` is similar to copy/paste, then `#define` is analogous to **find/replace**.

## Format output

![](https://raw.githubusercontent.com/Captain-Murasa/img/master/202303051652183.png)

More about this: https://codeforwin.org/c-programming/list-of-all-format-specifiers-in-c-programming

---

# 2. Arrays

## Compiling

Compiling steps:

1. **Preprocessing**. Copy/paste and find/replace.

   ```c
   ...
   string get_string(string prompt);
   int printf(string format, ...);
   ...
   
   int main(void)
   {
       string name = get_string("What's your name? ");
       printf("hello, %s\n", name);
   }
   ```

2. **Compiling**. Convert source code to **assembly code**.

   ![compiling](https://cs50.harvard.edu/x/2023/notes/2/cs50Week2Slide033.png)

3. **Assembling**. Convert assembly code to **machine code**.

   ![assembling](https://cs50.harvard.edu/x/2023/notes/2/cs50Week2Slide038.png)

4. **Linking**. Code from included libraries are converted also into machine code and combined with source code.

   ![linking](https://cs50.harvard.edu/x/2023/notes/2/cs50Week2Slide049.png)

## Debugging 

1. Use `printf` to debug.
2. Use **debugger** in complier.
3. **Rubber duck debugging**. Speak your code to a rubber duck.

## Arrays

**Arrays** are a way of storing data **back-to-back** in memory such that this data is **easily accessible**.

- A `string` is simply an array of variables of type `char`: **an array of characters**, who ends with a special character called a `NUL character`: `\0`.

  ![hi with terminator](https://cs50.harvard.edu/x/2023/notes/2/cs50Week2Slide116.png)

- Include `string.h` to use some utilities for string. Like `strlen()` can calculate the length of a string.

- `ctype.h` is also useful.
  - `islower()` to detect if each char is lowercase;
  - `toupper()` to make a char lowercase to uppercase.
  - More about this: https://manual.cs50.io/#ctype.h

## Command-Line Arguments

`Command-line arguments` are arguments passed to program at the command line. For example, all statements typed after `clang` are considered command line arguments. 

```c
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc == 2) 
        printf("hello, %s\n", argv[1]);
    else
        printf("hello, world\n");
} 
```

- `argc`, the number of command line arguments.
- `argv`, an array of the characters passed as arguments at the command line.

Use `cowsay ` can play with command line argument.

## Exit Status

- When a program ends, a special **exit code** is provided to the computer. If the program exits without error, it is `0`, else it is `1`.

- Use `echo $?` to see the exit status.

---

# 3. Algorithms

- The $Ω$ symbol is used to denote the **best case** of an algorithm, such as $Ω(log⁡\space n)$.
- The $Θ$ symbol is used to denote where the **upper bound and lower bound are the same**, where the best case and the worst case running times are the same.

## Search

- Linear Search: $O(n)$、$\Omega(1)$
- Binary Search: $O(log\space n)$、$\Omega(1)$ 

## Recursion

Recursion Function: one that as part of its execution invoke itself.

Recursion must have 

- The **base case**, to terminate the recursive process.
- The **recursive case**, where the recursion will actually occur.
- Any of above can be multiple:
  - Multiple base cases: The Fibonacci number sequence
  - Multiple recursive cases: the Collatz conjecture.

## Sort

- Selection Sort：$O(n^2)$、$\Omega(n)$
- Bubble Sort： $O(n^2)$、$\Omega(n)$
- Merge Sort： $O(log \space n)$、$\Omega(log \space n)$

Visualization:  https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html 

Video version: https://www.youtube.com/watch?v=ZZuD6iUe3Pc

