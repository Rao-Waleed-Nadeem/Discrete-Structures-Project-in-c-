CS1005 - Discrete Structures: Final Project (Fall 2024)
Project Overview
This project focuses on applying discrete structures concepts to practical programming problems using C++. The total marks for the project are 100, distributed across three questions. Students must use a modular programming approach and adhere to the provided guidelines.

General Guidelines
Peer plagiarism will result in zero marks.
Late submissions are not allowed under any circumstances.
Maximum group members: 2.
Submit well-commented code; marks will be deducted for missing comments.
Outputs must be attached in a Word document.
Question 1: Operations on Sets
Marks: 40

Develop a system to perform the following set operations:

Create sets (must have more than 3 elements and be different from each other).
Union of two sets.
Intersection of two sets.
Print sets.
Compute A – B.
Compute B – A.
Calculate the total number of relations between two sets.
Check for Reflexive Relations.
Check for Symmetric Relations.
Check for Anti-symmetric Relations.
Additional Notes:

The system must allow the user to input a relation and determine whether it is reflexive, symmetric, or anti-symmetric.
Question 2: Logical Equivalence via Truth Tables
Marks: 40

Write a program to verify whether a logical statement is logically equivalent using a truth table.

Requirements:
The program should be generic and handle any logical statement.
The truth table must be displayed stepwise.
Sample Inputs:
~(p → q) ≡ (p ∧ ~q)
[(p ∧ q) → r] ↔ (p → (q → r)) ≡ [(p → q) ∧ (q → r)] → (p → r)
Question 3: Minimum Spanning Tree
Marks: 20

Write a program that computes the Minimum Spanning Tree (MST) for a given graph using both Kruskal's Algorithm and Prim's Algorithm.

Requirements:
Input: An adjacency matrix representing the graph.
Output:
The edges included in the MST for both algorithms.
The total cost of the MST for each algorithm.
Use modular functions for each algorithm.
Example Output:
For each algorithm:

Display the steps for constructing the MST.
Show the edges in the MST and their total weight.
