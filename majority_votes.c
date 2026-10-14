
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




        // Repeat voting for each round
    for (int round = 1; round <= rounds; round++) {

        if (voter_id == -1) {

            // Judge collects the votes
            int yes_count = 0; // changed from yes to be more descriptive
            int no_count = 0;  // added a separate no count instead of math
            int vote_val;

  printf("\n------ Round %d -------\n", round);
            fflush(stdout);

            for (int i = 0; i < voters; i++) {

                read(pipes[i][0], &vote_val, sizeof(vote_val));

                // checking each vote manually
                if (vote_val == 1) {
                    yes_count++;
                }
                else {
                    no_count++;
                }
            }

            
            // determines the majority
            if (yes_count > no_count) {
                printf("--- Round %d: The voting result is a YES.\n", round);
            }
            else if (no_count > yes_count) {
                printf("--- Round %d: The voting result is a NO.\n", round);
            }
            else {
                printf("--- Round %d: The voting result is a TIE.\n", round);
            }

                 fflush(stdout);

        }