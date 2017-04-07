/*
 * DCgame.h
 *
 *  Created on: Mar 16, 2017
 *      Author: Tapiwa
 */

#ifndef DCGAME_H_
#define DCGAME_H_

namespace dcgame {

class DCgame{

public:
	DCgame();
	void playgame();
	int x_new, y_new; //user coordinates
	int x_trap1,x_trap2,x_trap3, x_trap4,x_target; //trap x-coordinates
	int y_trap1,y_trap2,y_trap3, y_trap4,y_target; //trap y-coordinates

	int x_enemy1,x_enemy2,x_enemy3, x_enemy4,x_enemy5; //enemy x-coordinates
	int y_enemy1,y_enemy2,y_enemy3, y_enemy4,y_enemy5; //enemy y-coordinates

	int counter;
	int n;
	int rows, cols;

private:
	char gameboard[7][10];
	char user;
	bool endGame;

	void clearboard();
	void intialiseUser();
	void placeTraps();
	void initialiseEnemies();
	void randomiseEnemies();
	void updateEnemies();

	void Draw();
	void moveUser();
	void trap();
	bool checkWin();
	bool checkLoss();

};

} /* namespace dcgame */

#endif /* DCGAME_H_ */
