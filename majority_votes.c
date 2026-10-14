
 // Adam Pinkos
 // CS4420 - Operating Systems
 // Assignment 4
 // October 14th, 2026



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>



int main() {

    // intialized voters and rounds
    int voters;
    int rounds;

    // prompts for users 
    printf("Enter the number of voters: ");
    scanf("%d", &voters);

    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    
    // Create an array to hold one pipe for each voter
    int pipes[voters][2];

    for (int i = 0; i < voters; i++) { // Loop through each voter to create their pipe

        // Creates pipe
        pipe(pipes[i]);

    }



    // Create a child process for each voter
    int voter_id = -1;
    int p; // process id storage


    // Loop through the number of voters to create child processes
    for (int i = 0; i < voters; i++) {

        // new child process
        p = fork();

        // check if child
        if (p == 0) {

            voter_id = i;   // Give the child its voter ID 

            break;
        }

        else {
            // parent process does nothing here for now
        }
    }
    
    
    // Repeat voting for each round
    for (int round = 1; round <= rounds; round++) {

         // 1 is a judge
        if (voter_id == -1) {

            // variables for yes or no 
            int yes_count = 0; // changed from yes to be more descriptive
            int no_count = 0;  // added a separate no count instead of math
            int vote_val;



            printf("\n------ Round %d -------\n", round);
            fflush(stdout);

            // Loop through each voter to collect their vote
            for (int i = 0; i < voters; i++) {


                // Read the vote
                read(pipes[i][0], &vote_val, sizeof(vote_val));


                // checking each vote manually
                if (vote_val == 1) {

                    yes_count++; // yes count 
                }

                else {

                    no_count++; // no count
                }
            }


            // determines the majority
            if (yes_count > no_count) {
                printf("--- Round %d: The voting result is a YES.\n", round); // YES wins
            }
            else if (no_count > yes_count) { 
                printf("--- Round %d: The voting result is a NO.\n", round); // NO wins
            }
            else {
                printf("--- Round %d: The voting result is a TIE.\n", round); // TIE
            }

            fflush(stdout);
        }

        else {

            // Voter randomly chooses yes or no
            int my_vote = rand() % 2;

            // Check if yes 
            if (my_vote == 1) {
                
                // Display the YES vote and voter ID
                printf("Round %d: Voter %d votes: YES\n", round, voter_id);
            }

            else {

                // Display the NO vote and voter ID
                printf("Round %d: Voter %d votes: NO\n", round, voter_id);

            }

            fflush(stdout);

            // Send the vote to the judge through the voter's pipe
            write(pipes[voter_id][1], &my_vote, sizeof(my_vote));
        }
    }


    // Close remaining pipes
    if (voter_id == -1) {

        for (int i = 0; i < voters; i++) {

            close(pipes[i][0]);
        }

        // Close the reading end of each pipe
        for (int i = 0; i < voters; i++) {

            // Wait for a child process to finish
            wait(NULL);
        }

    }

    else {

        // Each voter closes the writing end of its pipe
        close(pipes[voter_id][1]);
    }

    return 0;
}
