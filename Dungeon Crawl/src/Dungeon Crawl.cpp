//============================================================================
/*Dungeon Crawl
 Requires:
 variables, data types, and numerical operators
 basic input/output
 logic (if statements, switch statements)
 loops (for, while, do-while)
 arrays

 Make a program that outputs a simple grid based gameboard to the screen using either numbers or characters.
 i.e.
 . . . . . . . . . .
 . G . . . . . . . .
 . . . . . . T . . .
 . . . . . . . . . .
 . . . . T . . . . .
 . . . . . . T . . .
 . . . . . . . . . X


 or
 0 0 0 0 0 0 0 0 0 0
 0 5 0 0 6 0 0 0 0 0
 0 0 0 0 0 0 7 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 7 0 0 0 0 0 0
 0 0 0 0 0 0 7 0 0 0
 0 0 0 0 0 0 0 0 0 4


 Allow the user (marked by G in the example) to move either up, down, left, or right each turn. If the player steps on a trap then they lose. If the make it to the treasure 'X' then they win.

 Add enemies that move randomly in any direction once per turn. (enemies just like traps cause the player to lose if touched)

 HINT: Don't let the player move off the gameboard! You program will crash if they move off the top or bottom of the board!
 (the same holds true for enemies)
 Last edited on Jul 27, 2009 at 3:05am
 Jul 26, 2009 at 11:46pm
 Bazzy (6281)
 */
//============================================================================
#include <iostream>
#include "DCgame.h"
using namespace std;

int main() {

	char input;
	char input2;
	char input3;
	bool endGame = false;

	dcgame::DCgame game;

	while (endGame == false) {

		game.playgame();

		cout << "Play Again! Select (YES/NO)" << endl;
		cin >> input;
		if (input == 'N' || input == 'n') {
			endGame = true;
			break;
		}

		if (input == 'Y' || input == 'y') {
			endGame = false;
		}

		else {

			bool validResponse = false;

			while (validResponse == false) {

				cout << "Please letter Y or N" << endl;
				cin >> input2;

				if (input2 == 'N' || input2 == 'n') {
					validResponse = true;
					endGame = true;
					break;
				}

				if (input2 == 'Y' || input2 == 'y') {
					endGame = false;
					validResponse = true;
					endGame = false;
					break;
				}

			}

		}
	}

	//system("PAUSE");
	return 0;
}
