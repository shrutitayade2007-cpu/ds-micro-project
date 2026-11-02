# Stack-Based Book or Item Reversal System

A Data Structures project that implements a **stack using an array** to store books/items, demonstrates the core stack operations, and uses the stack to **reverse the entered sequence of items**.

## Problem Statement

Implement a stack using an array to store items and demonstrate push, pop, peek, and display operations. Use the stack to reverse the entered sequence of items.

## Features

| Operation | Description |
|-----------|-------------|
| **Push**    | Adds a book/item on top of the stack (checks for overflow) |
| **Pop**     | Removes the top item (checks for underflow) |
| **Peek**    | Shows the top item without removing it |
| **Display** | Prints all items from top to bottom |
| **Reverse** | Pops every item to print the sequence in reverse order of entry |

## How It Works

- The stack is a fixed-size array (`MAX_ITEMS = 100`) of `string` objects inside a `Stack` class, with an integer `top` that tracks the last inserted item (`-1` means empty).
- Stack follows **LIFO** (Last In, First Out): the last item pushed is the first one popped.
- **Reversal logic:** if items are entered as `A, B, C`, popping them one by one gives `C, B, A`. The program pops from a *copy* of the stack, so your original stack stays unchanged.

## Time Complexity

| Operation | Complexity |
|-----------|-----------|
| Push      | O(1) |
| Pop       | O(1) |
| Peek      | O(1) |
| Display   | O(n) |
| Reverse   | O(n) |

## Files

- `stack_reversal.cpp`: source code (C++)
- `README.md`: project documentation

## How to Compile and Run

```bash
g++ stack_reversal.cpp -o stack_reversal
./stack_reversal
```

On Windows:

```bash
g++ stack_reversal.cpp -o stack_reversal.exe
stack_reversal.exe
```

## Sample Run

```
1. Push   2. Pop   3. Peek   4. Display   5. Reverse   6. Exit

Enter your choice: 1
Enter book/item name: Data Structures
"Data Structures" pushed onto the stack.

Enter your choice: 1
Enter book/item name: Algorithms
"Algorithms" pushed onto the stack.

Enter your choice: 1
Enter book/item name: Operating Systems
"Operating Systems" pushed onto the stack.

Enter your choice: 5

Original order (entered):
  1. Data Structures
  2. Algorithms
  3. Operating Systems

Reversed order (using stack):
  1. Operating Systems
  2. Algorithms
  3. Data Structures
```

## Possible Improvements

- Dynamic array resizing instead of a fixed size
- Save/load the book list from a file
- A GUI or web front end

## Author

*Your Name* | *Roll No.* | *Course / Section*
