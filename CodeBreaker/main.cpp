#include <iostream>
#include <iomanip>
#include <ctime>
#include "Project1.h"

using namespace std;



// CONSTANT DEFINITIONS

const int CODE_SPAN = 6;
const int CODE_LENGTH = 4;
const int MAX_GUESSES = 12;



// MAIN FUNCTION DEFINITION

int main(int argc, char** argv) {

	/* Seed pseudorandom number generator */

	srand( time(NULL) );

	/* Local Variables */

	string secret_code, player_code;                    /* Secret Code and Player's Guesses */
	string secret_code_copy, player_code_copy;          /* Temporary copies of secret_code and player_code (for code checking) */

	char repeat_game;                                   /* For player's input at the end of the game */

	int correct_digits, misplaced_digits, num_guesses;  /* Counters for correct/misplaced digits and player's guesses */

	bool game_over = false, guessed_code = false;       /* Flags for "game over" and "player guessed code" */

	/* Print welcome message and instructions */

	print_instructions();

	/* MAIN LOOP */

	while ( !game_over ) {

		/* START OF A NEW GAME */

		/* Print Header */

		cout << '\n' << setw(40) << "YOUR GUESSES:" << setw(15) << "CORRECT:" << setw(15) << "MISPLACED:" << '\n';
		cout << string(70, '=') << '\n';

		/* Generate secret code; reset guess counter */

		secret_code = generate_code();
		secret_code_copy = secret_code;
		num_guesses = 0;

		/* COMMENT THE FOLLOWING LINE TO HIDE SECRET CODE AFTER DEBUGGING COMPLETE */

		//cout << "Secret Code: " << secret_code << '\n';

		while ( (!guessed_code) && (num_guesses < MAX_GUESSES) ) {

			/* START OF NEW ROUND OR TURN */

			/* Reset correct/misplaced digit counters */

			correct_digits = 0;
			misplaced_digits = 0;
			
			
			
			/* Get and validate the player's guess using "get_player_code()"; increment guess counter */

			player_code = get_player_code();
			player_code_copy = player_code;
			secret_code_copy = secret_code;
			++num_guesses;
			
			for ( int i = 0; i < CODE_LENGTH; ++i){
				
				if (player_code_copy.at(i) == secret_code_copy.at(i) ){
					
					correct_digits += 1;
					player_code_copy.at(i) = 'X';
					secret_code_copy.at(i) = 'Y';
					
					
					}
			}
			
			
			for ( int i = 0; i < CODE_LENGTH; ++i){
				
				
				for ( int j = 0; j < CODE_LENGTH; ++j){
					
					
					
					
					 if (player_code_copy.at(i) == secret_code_copy.at(j) ){
						
						misplaced_digits += 1;
						player_code_copy.at(i) = 'X';
						secret_code_copy.at(j) = 'Y';
						
						
					}
				}
				
			}


			
			
			
			/* Print player's guess and number of correct/misplaced digits */
			
			cout << setw(40) << player_code << setw(15) << correct_digits << setw(15) << misplaced_digits << '\n';
			
			if( correct_digits == CODE_LENGTH){
				
				guessed_code = true;
				
			}

		} // End while( !guessed_code && num_guesses < MAX_GUESSES )
		
		/* Did the player win the game?  If not, print the secret code */
		
		if (guessed_code){
			
			cout << "Congratulations, you've guessed the code!" << '\n';
			cout << "It took you " << num_guesses << " guess(es) to get it right!" << '\n';
			
		}
		
		
		
		
		if ( !guessed_code ) {

				/* If they are, print a message and the guess counter, and flip the "guessed code" flag to end current round */

				cout << "Sorry, you've run out of guesses!\n";
				cout << "The secret code was: " << secret_code << "!\n\n";

		}

		/* After the end of the previous round, ask if the player would like to play a new round */

		cout << "Would you like to play again (Y/N)? ";
		cin >> repeat_game;
		repeat_game = toupper(repeat_game);

		/* If player says "no", flip the "game over" flag to end the game */

		if ( repeat_game == 'N' ) {

			game_over = true;

		}

		/* Otherwise, flip the "guessed code" flag again to start a new round */

		else {

			guessed_code = false;

		}

	} // End while( !game_over )

	/* Print exit message */

	cout << "Thanks for playing!\n\n";

	return 0;

} // End main()
