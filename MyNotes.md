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

`%p`,  view the address of a location in memory. 

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

Implement `atoi` in `stdlib.h`:  [techiedelight.com/implement-atoi-function-c-iterative-recursive](https://www.techiedelight.com/implement-atoi-function-c-iterative-recursive/)  

## Sort

- Selection Sort：$O(n^2)$、$\Omega(n)$
- Bubble Sort： $O(n^2)$、$\Omega(n)$
- Merge Sort： $O(log \space n)$、$\Omega(log \space n)$

Visualization:  https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html 

Video version: https://www.youtube.com/watch?v=ZZuD6iUe3Pc

---

# 4. Memory

The `C` language has two powerful operators that relate to memory:

- `&` Provides the address of something stored in memory. 
- `*` Instructs the compiler to go to a location in memory. (**Dereference** operator)

## Pointers

A **pointer** is a variable that contains the **address**.

A string's name is a pointer:

![two strings stored separately in memory with separate pointers pointing at them](https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide116.png)

 **Dynamically allocated memory** at runtime:

- `malloc` , to allocate a block of a specific size of memory from **heap**.  
- `free`,  *free up* the block of memory which previously allocated lest **memory leak**.

> When allocate wrong, `malloc` returns `NULL`, which is a synonym for $0$, but it's specifically an address.

**Overflow**:

- **heap overflow**: touching areas of memory you are not supposed to.
- **stack overflow**: too many functions are called.
- both of above called **buffer overflows**.

**Garbage Value**:

It's possible that the memory allocated previously utilized by the computer. So maybe there is **junk** or **garbage values**, when getting a block of memory but **not initializing** it.

## Valgrind

*Valgrind* is a tool that can check to see if you `free` all the memory you allocated.

- Usage: `valgrind ./xxx`, xxx is the executable file.

## Call Stack

When calling a function, the system sets aside space in memory from **stack** for that function. These memory called **stack frames** or **function frames**.

## File Pointers

Common file I/O functions:

![](https://raw.githubusercontent.com/Captain-Murasa/img/master/202303071928702.png)

```c
// 1. fopen()
FILE* ptr = fopen ( <filename> , <operation> );
FILE* ptr1 = fopen ( “file1.txt” , “r” );
FILE* ptr2 = fopen ( “file2.txt” , “w” );
FILE* ptr3 = fopen ( “file3.txt” , “a” );

// 2. fclose()
fclose ( <file pointer> );
fclose ( ptr1 );

// 3. fgetc()
// Reads and returns the next character from the file pointed to.
// File pointer must be 'r'
char ch = fgetc ( <file pointer> );
char ch1 = fgetc ( ptr1 );

// print all characters in file(like linux command 'cat')
char ch;
while ((ch = fgetc(ptr)) != EOF)
    printf("%c", ch);

// 4. fputc()
// Writes or appends character to the pointed-to file.
// File pointer must be 'w' or 'a'
fputc ( <character >, <file pointer> );
fputc ( ‘A ’, ptr2 );

// copy one file to another(like linux command 'cp')
char ch;
while ((ch = fgetc(ptr)) != EOF)
    fputc(ch, 'ptr2');

// 5. fread()
// Reads <qty> units of <size> from the file pointed to 
// and stores them in a buffer (usually an array) pointed to by <buffer>.
// File pointer must be 'r'
fread (<buffer>, <size>, <qty>, <file pointer>);

int arr[10];
fread (arr, sizeof (int), 10, ptr);

// 6. fwrite()
// Writes <qty> units of <size> to the file pointed to 
// by reading them from a buffer (usually an array) pointed to by <buffer>.
// File pointer must be 'w' or 'a'
fwrite (<buffer>, <size>, <qty>, <file pointer>);

int arr[10];
fwrite (arr, sizeof (int), 10, ptr);
```

Other functions:

![](https://raw.githubusercontent.com/Captain-Murasa/img/master/202303071946095.png)

Example:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open CSV file
    FILE *file = fopen("phonebook.csv", "a");

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s, %s\n", name, number);

    // Close file
    fclose(file);
}
```

## stdint.h

`stdint.h` includes lots of types precisely defined with size and sign.

- `uint8_t`
- `int16_t`
- ...

---

# 5. Data Structure

- **Data structures** essentially are forms of organization in memory.

- **Abstract data structures** are those that we can conceptually imagine.

## Stacks and Queues

- **Queues** are one form of abstract data structure, they are FIFO.

  - Actions: enqueue, dequeue

  - can be implemented both *array* and *linked list* .

  - ```c
    typedef struct _queue 
    {
        VALUE array[CAPACITY]; 
        int front; 
        int size;
    } queue;
    ```

  - ```c
    typedef struct _queue
    {
        VALUE val;
        struct _queue *prev; 
        struct _queue *next; 
    } queue;
    ```

- **Stacks** is another, they are LIFO.

  - Actions: push, pop

  - can be implemented both *array* and *linked list* .

  - ```c
    typedef struct _stack
    {
        VALUE array[CAPACITY];
        int top;
    } stack;
    ```

  - ```c
    typedef struct _stack
    {
        VALUE val;
        struct _stack *next;
    } stack;
    ```

## Resizing Arrays

- `realloc(*ptr, size)` can be used to *reallocate* the memory. 

```c
int *list = malloc(3 * sizeof(int));
if (list == NULL)
    return 1;

list[0] = 1;
list[1] = 2;
list[2] = 3;

// Resize list to be of size 4
int *tmp = realloc(list, 4 * sizeof(int));
if (tmp == NULL) {
    free(list);
    return 1;
}
list = tmp;

// Add number to list
list[3] = 4;

free(list);
```

## Linked Lists

A **linked list** allows you to include values that are located at varying areas of memory and *dynamically* grow and shrink the list as you desire.

![Three boxes with in separate areas of memory with smaller boxes with a final box where the one box points to another and another until the end of the boxes](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide043.png)

These boxes are called **nodes**. A **node** contains both an **item** and a pointer called **next**.

```c
typedef struct node
{
    int number;
    struct node *next;
}
node;
```

Prepend numbers to the front of list:

```c
// Implements a sorted list of numbers using a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++) {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return 1;
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
            list = n;

        // If number belongs at beginning of list
        else if (n->number < list->number) {
            n->next = list;
            list = n;
        }

        // If number belongs later in list
        else {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
                // If at end of list
                if (ptr->next == NULL) {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number) {
                    n->next = ptr->next;
                    ptr->next = n;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%i\n", ptr->number);

    // Free memory
    node *ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```

## Trees

Implements a  binary search tree:

```c
// Implements a list of numbers as a binary search tree
#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

void free_tree(node *root);
void print_tree(node *root);
int search(node *tree, int number);

int main(void)
{
    // Tree of size 0
    node *tree = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return 1;

    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL) {
        free_tree(tree);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL) {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    // Print tree
    print_tree(tree);

    // Free tree
    free_tree(tree);
    return 0;
}

void free_tree(node *root)
{
    if (root == NULL)
        return;
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node *root)
{
    if (root == NULL)
        return;

    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

int search(node *tree, int number)
{
    if (tree == NULL)
        return 0;
    else if (number < tree->number)
        return search(tree->left, number);
    else if (number > tree->number)
        return search(tree->right, number);
    else if (number == tree->number)
        return 1;
    return 0;
}
```

A tree like the above offers **dynamism** that an array does not offer. It can *grow* and *shrink* as we wish.

## Dictionaries

Each **Dictionary** has a **key** and a **value**,  and can offer a $O(1)$ access.

## Hashing and Hash Tables

- **Hashing** is the idea of taking a value and being able to output a value that becomes a *shortcut* to it later.
- A **hash function** is an algorithm that reduces a larger value to something small and predictable.
- A **hash table** is an *array* of *pointers* to *node*s(like `node *table[26]`).

![a verticle column of 26 boxes one for each letter of the alphabet with various names from the harry potter unverise emergint to the right albus is with a and harry is with h](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide169.png)

- When two have the same **hash code**, we say they are **collision**. To solve this problem:
  -  **Linear probing**, but subjected to *clustering*.
  - **Chaining**.

## Tries

- **Tries** , short for "retrieval", whose nodes are arrays. 
- Tries are always searchable in constant time($O(1)$).
- One downside to *Tries* is that they tend to take up a large amount of memory.

![hagrid being spelled with one letter at a time where one letter is associated with one list H from one list A from another and so on and harry being spelled similarly where hagrid and harry share a two common letters H and A](https://cs50.harvard.edu/x/2023/notes/5/cs50Week5Slide209.png)

```c
typedef struct node
{
   	char *number;
    structure node *children[26];
} node;
```

Visualization: https://www.cs.usfca.edu/~galles/visualization/Trie.html 

---

# 6.Python

## Hello

```python
print("hello, world")

answer = input("What's your name? ")
# print("hello, " + answer)
print(f"hello, {answer}")
```

## Types

- Data types in Python do not need to be explicitly declared. 

- In Python, commonly used types include:

  ```python
  bool
  float
  int
  str
  ```

  - Notice that `long` and `double` are missing. Python will handle what data type should be used for larger and smaller numbers.

- Some other data types in Python include:

  ```python
  range      sequence of numbers
  list       sequence of mutable values
  tuple      sequence of immutable values
  dict       collection of key-value pairs
  set        collection of unique values
  ```

## Variables

Python variables have two big differences from C:

- No type specifier. 
- Declared by initialization only.
- C: `int counter = 1;`    Python: `counter = 1` 
- Python favors `counter += 1` to increment by one, losing the ability found in C to type `counter++`.

## Speller

```python
# Words in dictionary
words = set()


def check(word):
    """Return true if word is in dictionary else false"""
    if word.lower() in words:
        return True
    else:
        return False


def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    file.close()
    return True

def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words)


def unload():
    """Unloads dictionary from memory, returning true if successful else false
       unload() only needs to return True because Python handles memory management on its own.
    """
    return True
```

- Learn more about functions in the [Python documentation](https://docs.python.org/3/library/functions.html) 

## Conditionals

```python
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

- `letters_only = True if input().isalpha () else False` 

## Loops

```python
# while loop
i = 0
while i < 3:
    print("meow")
    i += 1

# for loop
for i in range(3):
    print("meow")
```

- Python does not have a `do while` loop.
- The `in` preposition is essentially doing a linear search under the hood.

## Other changes

- `&&`、`||`、`!` are replaced by `and`、`or`、`not` 

- Express multiple keywords:

  ```python
  if s.lower() in ["y", "yes"]:
      print("Agreed.")
  elif s.lower() in ["n", "no"]:
      print("Not agreed.")
  ```

- Python arrays (more appropriately known as **lists** ) are not fixed in size; they can grow or shrink as needed.

  - `nums = []`  `nums = [1,2,3,4]`  `nums = [x for x in range(50)]`
  - `nums.append(5)`  `nums.insert(4, 5)`  `nums += [5]` 

- **Tuples** are ordered, immutable sets of data.

- `str` 

  - Uppercase string all at once: `str.upper()` 

- swap: `a, b = b, a` 

## OOP

- It’s possible to have certain types of values not only have properties or attributes inside of them but have *functions* as well. In Python, these values are known as **objects**

- When a function belongs to a specific **object**, it is known as a **method**.

- ```python
  class Student():
      def __init__(self, name, id):
          self.name = name
          self.id = id
      
      def changeID(self, id):
          self.id = id
          
      def print(self):
          pirnt(f"{self.name} - {self.id}")
  ```

- The [Python documentation](https://docs.python.org/) 

## `sys`

```python
import sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)
```

## CSV

```python
# Saves names and numbers to a CSV file using a DictWriter

import csv

# Get name and number
name = input("Name: ")
number = input("Number: ")

# Open CSV file
with open("phonebook.csv", "a") as file:

    # Print to file
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
```

- Learn more about the CSV files in Python in the [Python documentation](https://docs.python.org/3/library/csv.html)

## Third-party library

Using a **third-party library**, Python can do text-to-speech.

- ```python
  # Says hello to someone
  
  import pyttsx3
  
  engine = pyttsx3.init()
  name = input("What's your name? ")
  engine.say(f"hello, {name}")
  engine.runAndWait()
  ```

Also, a qrcode:

- ```python
  import os
  import qrcode
  
  img = qrcode.make("https://youtu.be/xvFZjo5PgG0")
  
  img.save("qr.png", "PNG")
  
  os.system("open qr.png")
  ```

- 