CS4420 Operating Systems – Assignment 6

Student: Adam Pinkos
Date: October 14, 2026

Program Description

This program simulates a majority voting system using multiple processes and pipes in C. The program creates one judge process (parent) and multiple voter processes (children). Each voter randomly selects YES or NO and sends their vote to the judge through a pipe.

The judge collects all votes, counts the YES and NO votes, and determines the majority result. This process repeats for the number of rounds entered by the user.

How the Program Works

User Input: The program asks the user to enter the number of voters and the number of voting rounds. There must be at least 3 voters.

Pipe Creation: The parent process creates one pipe for each voter using the pipe() system call. These pipes allow the voters to communicate with the judge.

Process Creation: The parent creates a child process for each voter using fork(). Each child is assigned a unique voter ID, while the judge has an ID of -1.

Voting: During each round, every voter randomly chooses YES (1) or NO (0) using rand(). Each voter sends its vote to the judge using the write() system call.

Majority Calculation: The judge receives votes using read() and counts the YES and NO votes. The option with more votes wins. If both counts are equal, the result is a tie.

Process Termination: After all rounds are completed, the program closes the remaining pipes, and the parent uses wait() to make sure all child processes have finished.

How to Compile and Run

The program was developed in C and can be compiled and executed using GCC in a Linux environment.

Step 1: Open the terminal and navigate to the assignment folder.