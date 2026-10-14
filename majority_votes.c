
// Adam Pinkos
// CS4420 - Operating Systems
// Assignment 4
// October 14th, 2026



#include <stdio.h>
#include <unistd.h>

int main() {
    
    // intialized voters and rounds 
    int voters; 
    int rounds; 
    

    printf("Enter the number of voters: ");
    scanf("%d", &voters);
    
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);



    // Create pipes for the voters
    int pipes[voters][2];

    for (int i = 0; i < voters; i++) {

        pipe(pipes[i]);

    }

    
 // Adam Pinkos
 // CS4420 - Operating Systems
 // Assignment 4
 // October 14th, 2026



#include <stdio.h>
#include <unistd.h>

int main() {
    
    // intialized voters and rounds 
    int voters; 
    int rounds; 
    

    printf("Enter the number of voters: ");
    scanf("%d", &voters);
    
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);


    
    // Create pipes for the voters
    int pipes[voters][2];

    for (int i = 0; i < voters; i++) {

        pipe(pipes[i]);

    }



    // Create a child process for each voter
    int voter_id = -1;
    int p; // process id storage

    for (int i = 0; i < voters; i++) {
        
        p = fork();
        
        // check if child
        if (p == 0) {
            voter_id = i;
            // printf("i am child %d\n", voter_id);
            break;
        } 
        else {
            // parent process does nothing here for now
        }
    }

    return 0;
}
}
