
// Adam Pinkos
// CS4420 - Operating Systems
// Assignment 4
// October 14th, 2026



#include <stdio.h>

int main() {
    int v; // number of voters
    int r; // rounds
    
    printf("Enter the number of voters: ");
    scanf("%d", &v);
    
    printf("Enter the number of rounds: ");
    scanf("%d", &r);
    
    printf("\n");
    printf("voters are: ");
    printf("%d", v);
    printf("\n");
    printf("rounds are: ");
    printf("%d", r);
    
    // just to keep the black box open
    getchar();
    getchar();

    return 0;
}