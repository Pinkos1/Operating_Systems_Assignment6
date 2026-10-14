### **CS4420 Operating Systems - Assignment 6**  

**Adam Pinkos**      
**October 14, 2026**  

#### **Description** 
This program uses pipes and child processes to simulate majority voting. The user enters the number of voters and rounds. Each voter randomly chooses YES or NO and sends their vote to the judge using a pipe. The judge collects the votes and determines the majority for each round.  


### How to Run  
#### Compile the Program
```bash
gcc majority_votes.c -o majority_votes
```

#### Run the Program
```bash
./majority_votes
```
Enter the number of voters (at least 3) and the number of rounds.  
### How It Works
1. The parent process creates a pipe for each voter.   
2. The parent uses fork() to create the voter processes.    
3. Each voter sends a random YES or NO vote using write().    
4. The judge uses read() to collect votes and determine the majority.    
5. After all rounds, the program closes the pipes and waits for the child processes to finish.    