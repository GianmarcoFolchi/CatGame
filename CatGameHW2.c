#include <stdlib.h>
#include <stdio.h>

int main(){ 
    int limit, guess, prevGuess, max, min, winner = 0; 
    char input[30];  
    
    scanf("%d", &limit); //read the limit
    getchar();
    guess = limit/2; //set the values 
    max = limit; 
    min = 0; 
    printf("GUESS = %d \n", guess); 
    fflush(stdout);
    scanf("%c ", input); 

    if(input[0] == 'Y') {
        printf("Game Over"); 
    } else {
        //find new guess and store old guess
        prevGuess = guess; 
        guess = guess/2;
        printf("GUESS = %d \n", guess); 
        fflush(stdout);

    }
    //No. Colder.
    //No. Warmer

        gets(input);

    while (winner != 1) {

        gets(input);
        if (input[0] == 'Y') { //won
            break; 
        }
        if (input[4] == 'N') { //find the value if input = no change 
            guess = (guess + prevGuess)/2; 
            printf("GUESS = %d\n", guess);
            fflush(stdout);

            break;
        }
        if (input[4] == 'C') { //logic to cut the possible numbers down based on the input
            if (guess < prevGuess) {
                min = guess + ((prevGuess - guess)/2);
            } else {
                max = guess + ((prevGuess - guess)/2);
            }
        } else if (input[4] == 'W') {
            if (guess < prevGuess) {
                max = guess + ((prevGuess - guess)/2);
            } else {
                min = guess + ((prevGuess - guess)/2);        
            }
        }

        prevGuess = guess; 
        guess = (max + min)/2;

        if (guess == prevGuess) { //logic in case the program is guessing the same number more than once
            if ((min + 1) == max) {
                guess += 1; 
            } else {
                guess -= 1; 
            }
        }

        printf("GUESS = %d\n", guess);
        fflush(stdout);
    }
}



