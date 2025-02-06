#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"

class Game
{
	char **array;
	int countO;
	int countX;
	void verticalLines();
	void spaces();
	void horizontalLines(int j);
	
	
public:
    Game();
    Game(const Game &obj);
	~Game();
	char* getter() ;
	void checkPlayer(vector<Player>& players);
	void print();
	void promtPlayer(Player &player);
    void play(Player &player);
	void checkWinner(Player &player);
	
   	
	

};

#endif // GAME_HPP
