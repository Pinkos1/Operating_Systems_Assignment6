
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

    return 0;
}
