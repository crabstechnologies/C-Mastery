#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine the winner
int game(char you, char computer){
	if(you == computer){
		return -1;	// Draw
	}

	if((you == 'r' && computer == 's') || (you == 'p' && computer == 'r') || (you == 's' && computer == 'p')){
		return 1; // User wins
	}
	
	return 0; // Computer wins
}

int main(){
	char you, computer;
	int result;
	char options[] = {'r', 'p', 's'};

	srand(time(NULL)); // Initialize random seed
	
	printf("Welcome to Rock-Paper-Scissors!\n");

	while(1){ // Infinite loop until user quits
		printf("\n\nChoose: r (Rock), p (Paper), s (Scissors), or q (Quit)\n");
		printf("\nYour choice: ");
		scanf(" %c", &you); // Space befor %c to ignore whitespace

		if(you == 'q'){ // Quit the game
			printf("Thanks for playing! Goodbye!\n");
			break;
		}
	
		// Validate input
		if(you != 'r' && you != 'p' && you != 's'){
			printf("Invalid choice! Please enter r, p, s, or q.\n");
			continue;
		}
	
		// Randomly select a move for the computer
		computer = options[rand() % 3];
	
		// Determine result
		result = game(you, computer);

		printf("You: %c | Computer: %c\n", you, computer);

		if (result == -1){
			printf("It's draw!\n");
		} else if (result == 1){
			printf("Congratulations! You won!\n");
		} else {
			printf("You lost! Better luck next time!\n");
		}
	}
	
	return 0;
}
