# push_swap

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting

## Overview

Push Swap is a sorting algorithm project that works with two stacks, named 'a' and 'b'. The goal is to sort all the numbers in stack 'a' in ascending order using a specific set of operations

### Available Operations

- `sa` (swap a): Swap the first 2 elements at the top of stack a
- `sb` (swap b): Swap the first 2 elements at the top of stack b
- `ss`: Execute sa and sb at the same time
- `pa` (push a): Take the first element at the top of b and put it at the top of a
- `pb` (push b): Take the first element at the top of a and put it at the top of b
- `ra` (rotate a): Shift up all elements of stack a by 1
- `rb` (rotate b): Shift up all elements of stack b by 1
- `rr`: Execute ra and rb at the same time
- `rra` (reverse rotate a): Shift down all elements of stack a by 1
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1
- `rrr`: Execute rra and rrb at the same time

## Usage

1. Clone the repository
```sh
git clone https://github.com/andrexandre/push_swap.git ; cd push_swap
```

2. Compile the program
```sh
make
```

3. Run the program with a list of integers
```sh
./push_swap 4 67 3 87 23
```
> it's also possible to use quotes `"4 67 3 87 23"`

4. The program will output the list of operations that sorts the stack with the minimum number of operations

## Algorithm

The program uses an optimized sorting algorithm which:
- Handles small sets (2-3 elements) directly with predefined operations
- For larger sets, uses a strategy that involves selecting optimal moves to push elements between stacks
- Minimizes the total number of operations by calculating costs for each move
- Uses a combination of operations (like rr and rrr) where they're more efficient than individual operations

## Error Handling

The program will display "Error" followed by a newline and exit in these cases:
- Arguments aren't integers
- Arguments are outside the integer range
- There are duplicate numbers

> [!NOTE]
> This project is part of the 42 School curriculum
