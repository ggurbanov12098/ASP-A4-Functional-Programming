# Assignmеnt 4 – Functional Programming
CSCI 6221 – Advancеd Softwarе Paradigms (Fall 2024)  
Instructor: *Dr. Jamaladdin Hasanov*  
Duе: December 4th, 11:59PM  

## Table of Contents:

<details>
    <summary>Assignment Instructions</summary>

This assignment is divided into 2 options by complexity:

- Option A is for those who want to solve a simple problem - it will give you up to 80%.
- Option B requires more advanced programming skills - you can score up to 100%.


### Option A:

Choose 2 programming languages: one imperative, another functional. Write a function that reverses the given list (array) without any built-in reverse function (means, you need to use very basic commands of the language. in functional programming, use basic list operations).  

**Example:**  
Input: `[1,2,3,4,5]`  
Output: `[5,4,3,2,1]`   



### Option B:

Again choose 2 programming languages: one imperative, another functional. Solve the following e-Olymp problem using both of the languages: https://www.eolymp.com/en/problems/1964

In a `functional programming language`, you may not score 100% (due to timeout). If you manage to pass 70% of the cases (score >70), then it's ok. Use any functional programming language supported by E-olymp. If you use multi-paradigm programming languages (like Scala or JS), then do not use the imperative features of them (variables, loops and so on).

In `imperative programming language` try to solve it as list processing (array, vector, etc.) - there is a shorter implementation of this problem, but I want to see the array processing approach. With this approach, you may exceed the runtime limit. Do not try to achieve 100% - it can be done only with the formula. I accept solutions that score more than 90% with imperative programming language.


Submission guide: [link to student's repo](https://github.com/ADA-GWU/4-functional-programming-ggurbanov12098)

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/cgmKy0RU)


Your work should be under the folder called "Option A" or "Option B". There is no need to do both (please read it 3 times). Under this folder create 2 folders for the imperative and functional programming languages.

Example of the folder structure:  
```
/ Option A  
   /C++  
   /ML  
```
or  
```
/ Option B  
   /C#  
   /F#  
```
When done, share the link to your repositories in the submission. Again, this should be your own work.  
Good luck!

</details>

<details>
    <summary>Summary of Problem Statement</summary>

    All of you probably remember a children's riddle: A and B were sitting on the tube. A fell, B is lost. What is left on the tube?
    Vasya, Petya, and Dima play a similar game they invented. They start with a sequence of numbers from 1 to n, where each number's value equals its position in the sequence. They take turns making moves:

    - First Move: Strike out all numbers at even positions.
    - Second Move: From the remaining numbers, strike out those at odd positions after re-numbering the sequence.
    - Third Move: From the new sequence, strike out numbers at positions divisible by three.

    Repeat: Continue this cycle—striking out numbers at even positions, odd positions, and positions divisible by three—until only one number remains.

    Objective: Determine the last remaining number after the game concludes.

**Input:** The number of positive integers n (1 ≤ n ≤ 10^8), recorded on the playing field.  
**Output:** Print the last not deleted number as a result of this game.

Examples  
**Input #1:** `10`  
**Output #1:** `3`

</details>

<details>
    <summary>Solution Logic</summary>

    The sequence is re-numbered after each elimination round and the elimination criteria change in a cyclic way every round. Steps:
    1) Remove numbers at even positions.
    2) Remove numbers at odd positions.
    3) Remove numbers at positions divisible by three.
    4) This pattern repeats until a single number is left.
</details>

<details>
<summary>C++ Implementation</summary>

## How It Works

### 1. Initialization:
- Read the input `n` and initialize a vector `nums` containing numbers from 1 to `n`.

### 2. Elimination Loop:
- Use a `while` loop that continues until only one number remains in `nums`.
- Maintain a `step` counter to determine which elimination rule to apply.

### 3. Applying Elimination Rules:
- Step 0 (step % 3 == 0): Remove numbers at even positions.
- Step 1 (step % 3 == 1): Remove numbers at odd positions.
- Step 2 (step % 3 == 2): Remove numbers at positions divisible by three.
- Positions are re-numbered starting from 1 after each elimination round.

### 4. Updating the Sequence:
- Create a new vector `new_nums` to hold numbers that are not eliminated.
- After processing all numbers, update `nums` with `new_nums`.

### 5. Termination:
- Once `nums.size() == 1`, exit the loop and output the last remaining number.

## Compilation and Execution
Compile: `g++ test.cpp`  
Run: `./test`  
Input: `10`  
Output: `3`  
</details>


<details>
<summary>Haskell Implementation</summary>

## How It Works
### 1. Main Function:
- Reads the input `n` from the console.
- Calls `playGame` with the initial sequence `[1..n]` and starting `step` 0.

### 2. playGame Function:
- Base Case: If the list has only one element [x], return x.
- Recursive Case:
    - Determine which positions to delete based on the current step.
    - Elimination Rules:
        - Step 0 (step mod 3 == 0): Remove numbers at even positions.
        - Step 1 (step mod 3 == 1): Remove numbers at odd positions.
        - Step 2 (step mod 3 == 2): Remove numbers at positions divisible by three.
    - Use list comprehension to create newNums by filtering out numbers at positions to be deleted.
    - Recurse with newNums and incremented step.

### 3. Position Tracking:
- Positions are re-numbered starting from 1 after each elimination round.
- Achieved by zipping the nums list with [1..] to pair each number with its current position.


## Execution
*How to install Haskell to Windows: https://youtu.be/7z21m7P6tpI*  
*Where to download Haskell: https://www.haskell.org/ghcup/*  

![Haskell Implementation](/Option%20B/images/haskell.png)
Compile: `ghc ./main.hs`  
Run: `./test.exe`  
Input: `10`  
Output: `3`  

</details>

<details>
    <summary>Performance Notes</summary>

![Perfromance](/Option%20B/images/performance.png)

### C++ (Imperative):  
- Execution Time: 793 ms  
- Memory Usage: 512 MB **`(memory overflow)`**.  
- Achieved 97% due to memory limit. Efficient for smaller inputs but struggles with large n due to array processing overhead.  

### Haskell (Functional):  
- Execution Time: 5000 ms **`(time limit exceeded)`**.  
- Memory Usage: 4.56 MB (efficient memory).  
- Achieved 97%, but recursion and lazy evaluation made it slower for large inputs.

</details>

## References:

Learn You a Haskell: https://learnyouahaskell.com/chapters  
WikiHaskell: https://wiki.haskell.org/  

- ZIP: https://effective-haskell.com/solutions/chapter2/zipping-lists.html  
- IO#1: https://learnyouahaskell.com/input-and-output  
- IO#2: https://www.haskell.org/tutorial/io.html  
- List Comprehension: https://wiki.haskell.org/List_comprehension  
- `CookBooks` from open-source repos at GitHub
