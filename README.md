CS4420 Operating Systems - Assignment 6

Adam Pinkos
October 14, 2026

Description

This program uses pipes and child processes to simulate majority voting. The user enters the number of voters and rounds. Each voter randomly chooses YES or NO and sends their vote to the judge using a pipe.

The judge collects the votes and determines the majority for each round.