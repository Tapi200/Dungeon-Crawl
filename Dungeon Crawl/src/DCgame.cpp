/*
 * DCgame.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: Tapiwa
 */

#include "DCgame.h"
#include <iostream>
using namespace std;
#include <time.h>

namespace dcgame {

DCgame::DCgame() { // TODO Auto-generated constructor stub

}
//rows = 7;
//cols = 10;

void DCgame::playgame() {
	counter = 0;
	n = 15;

	clearboard();
	intialiseUser();
	placeTraps();
	randomiseEnemies();
	updateEnemies();
	Draw();
	moveUser();

	bool isDone = false;

	while (isDone == false) {
		Draw();
		moveUser();

		if (x_new < 0 || x_new > 6 || y_new < 0 || y_new > 9) {
			cout << "You moved off the board. Game Over!" << endl;
			break;
		}

		if (checkWin() == true) {
			isDone = true;
			if (counter == 10) {
				cout << "10 moves reached! You Win" << endl;
				break;

			} else {
				cout << "X touched! You Win" << endl;
				break;
			}
		}
		//checkWin();
		if (checkLoss() == true) {
			isDone = true;
			cout << "You either hit an Enemy or a trap! You Lose" << endl;
			break;
		}
	}
}

char gameboard[7][10] = { };

void DCgame::clearboard() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 10; j++) {
			gameboard[i][j] = '0';
		}
	}
}

void DCgame::intialiseUser() {
	char user = 'G';
	int x, y; //the x and y coordinates for the initial user position

	x = 2;
	y = 2;

	gameboard[x][y] = user;
	x_new = x; //defining the current user position
	y_new = y; //defining the current user position
}

void DCgame::placeTraps() {
	x_trap1 = 4, y_trap1 = 4;
	x_trap2 = 2, y_trap2 = 6;
	x_trap3 = 5, y_trap3 = 6;
	x_trap4 = 6, y_trap4 = 8;
	x_target = 6, y_target = 9;

	gameboard[x_trap1][y_trap1] = 'T';
	gameboard[x_trap2][y_trap2] = 'T';
	gameboard[x_trap3][y_trap3] = 'T';
	gameboard[x_trap4][y_trap4] = 'T';
	gameboard[x_target][y_target] = 'X';
}

void DCgame::randomiseEnemies() {
//update traps, update user position
	srand((unsigned) time(0));
	x_enemy1 = rand() % 7;
	x_enemy2 = rand() % 7;
	x_enemy3 = rand() % 7;
	x_enemy4 = rand() % 7;
	x_enemy5 = rand() % 7;

	y_enemy1 = rand() % 10;
	y_enemy2 = rand() % 10;
	y_enemy3 = rand() % 10;
	y_enemy4 = rand() % 10;
	y_enemy5 = rand() % 10;
}

void DCgame::updateEnemies() {

	char enemy = 'E';
	gameboard[x_enemy1][y_enemy1] = enemy;
	gameboard[x_enemy2][y_enemy2] = enemy;
	gameboard[x_enemy3][y_enemy3] = enemy;
	gameboard[x_enemy4][y_enemy4] = enemy;
	gameboard[x_enemy5][y_enemy5] = enemy;
}

void DCgame::Draw() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 10; j++) {
			cout << gameboard[i][j] << " ";
		}
		cout << endl;
	}
}

void DCgame::moveUser() {
	char user = 'G';
	char move;

	bool isDone = false;

	while (isDone == false) {

		gameboard[x_new][y_new] = '0';

		cout << "select next move (w,s,a,d) for (up, down, left or right)" << endl;

		cin >> move;

		switch (move) {

		case 'w':
			gameboard[x_new - 1][y_new] = user;
			isDone = true;
			x_new = x_new - 1;
			break;

		case 's':
			gameboard[x_new + 1][y_new] = user;
			isDone = true;
			x_new = x_new + 1;
			break;

		case 'a':
			gameboard[x_new][y_new - 1] = user;
			isDone = true;
			y_new = y_new - 1;
			break;

		case 'd':
			gameboard[x_new][y_new + 1] = user;
			isDone = true;
			y_new = y_new + 1;
			break;
		}
	}

	counter += 1;
}

bool DCgame::checkWin() {

	if (counter == n) { //to check win (using a counter) that user moved n times before hitting a trap.
		return true;
	}

	if (gameboard[x_new][y_new] == gameboard[x_target][y_target]) {
		return true;
	}
	return false;
}

bool DCgame::checkLoss() {
	//check user does not hit trap
	if (gameboard[x_new][y_new] == gameboard[x_trap1][y_trap1]
			|| gameboard[x_new][y_new] == gameboard[x_trap2][y_trap2]
			|| gameboard[x_new][y_new] == gameboard[x_trap3][y_trap3]
			|| gameboard[x_new][y_new] == gameboard[x_trap4][y_trap4]
			|| gameboard[x_new][y_new] == gameboard[x_enemy1][y_enemy1]
			|| gameboard[x_new][y_new] == gameboard[x_enemy2][y_enemy2]
			|| gameboard[x_new][y_new] == gameboard[x_enemy3][y_enemy3]
			|| gameboard[x_new][y_new] == gameboard[x_enemy4][y_enemy4]
			|| gameboard[x_new][y_new] == gameboard[x_enemy5][y_enemy5]) {

		return true;
	}
	return false;
}

} /* namespace dcgame */
