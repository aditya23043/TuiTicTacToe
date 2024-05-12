#include <iostream>
#include <ctime>

// Function Declarations
void drawBoard( char *spaces );
void playerMove( char *spaces, char player );
void computerMove( char *spaces, char computer );
bool checkWin( char *spaces, char player, char computer, bool &gameStatus );
int main(){

  char spaces[9] = {' ', ' ', ' ',
									 ' ', ' ', ' ',
									 ' ', ' ', ' '};
	char player = 'X';
	char computer = 'O';
	bool gameStatus = true;

	drawBoard( spaces );
	while ( gameStatus ){
		playerMove( spaces, player );
		drawBoard( spaces );
		if (checkWin( spaces, player, computer, gameStatus )){
			gameStatus = false;
			break;
		};
		computerMove( spaces, computer );
		drawBoard( spaces );
		if (checkWin( spaces, player, computer, gameStatus )){
			gameStatus = false;
			break;
		};
	}

	return 0;
}
void drawBoard( char *spaces ){
	std::cout << "\n" << "     " << "|" << "     " << "|" << "     " << "\n";
	std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  "; 
	std::cout << "\n" << "     " << "|" << "     " << "|" << "     " << "\n";
	std::cout << "-----" << "|" << "-----" << "|" << "-----";
	std::cout << "\n" << "     " << "|" << "     " << "|" << "     " << "\n";
	std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  "; 
	std::cout << "\n" << "     " << "|" << "     " << "|" << "     " << "\n";
	std::cout << "-----" << "|" << "-----" << "|" << "-----";
	std::cout << "\n" << "     " << "|" << "     " << "|" << "     " << "\n";
	std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  "; 
	std::cout << "\n" << "     " << "|" << "     " << "|" << "     \n" << std::endl;
}
void playerMove( char *spaces, char player ){
	int number;

	while ( true ){
		std::cout << "Enter the grid where you want to place your marker: (1-9) ";
		std::cin >> number;
		number--;
		if ( number < 0 || number > 8 ){
			std::cout << "Enter a number in range 1-9. Try Again!" << std::endl;
		}
		else if ( spaces[number] == ' ' ){
			spaces[number] = player;
			break;
		}
		else{
			std::cout << "Grid already filled! Try Again!" << std::endl;
		}
	}
}
void computerMove( char *spaces, char computer ){
	std::cout << "Computer's Turn..." << std::endl;
	while ( true ){
		srand(time(0));
		int num = rand()%9;
		if ( spaces[0]!=' ' && spaces[1]!=' ' && spaces[2]!=' ' && spaces[3]!=' ' && spaces[4]!=' ' && spaces[5]!=' ' && spaces[6]!=' ' && spaces[7]!=' ' && spaces[8]!=' ' ){
			break;
		}
		else if ( spaces[num] == ' ' ){
			spaces[num] = computer;
			break;
		}
	}
}
bool checkWin( char *spaces, char player, char computer, bool &gameStatus ){

	// Rows
	if ( spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2] ){
		std::cout << ( spaces[0] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}
	else if ( spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5] ){
		std::cout << ( spaces[3] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}
	else if ( spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8] ){
		std::cout << ( spaces[6] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}

	// Columns
	else if ( spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6] ){
		std::cout << ( spaces[0] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}
	else if ( spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7] ){
		std::cout << ( spaces[1] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}
	else if ( spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8] ){
		std::cout << ( spaces[2] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}

	// Diagonals
	else if ( spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8] ){
		std::cout << ( spaces[0] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}
	else if ( spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6] ){
		std::cout << ( spaces[2] == player ? "You WIN!" : "You LOSE!" ) << std::endl;
	}

	// Checking for a tie
	else if ( spaces[0]!=' ' && spaces[1]!=' ' && spaces[2]!=' ' && spaces[3]!=' ' && spaces[4]!=' ' && spaces[5]!=' ' && spaces[6]!=' ' && spaces[7]!=' ' && spaces[8]!=' ' ){
		std::cout << "TIE!" << std::endl;
	}
	else{
		return false;
	}
	return true;
}
