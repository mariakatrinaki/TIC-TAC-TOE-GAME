#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Messages.hpp"

using namespace std;

	
	








int main()
{
	
	Game game;
	
	game.print();
	vector<Player> players = menu();
	game.checkPlayer(players);
	
    	
    return 0;
}
	