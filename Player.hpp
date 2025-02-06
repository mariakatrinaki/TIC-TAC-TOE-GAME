#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

using namespace std; 

class Player
{
	
	string name;
	int age;
	char ch;
	int times;
	
	bool isWinner;
	int x;
	int y;
	
public:

   
	Player();
	Player(string name, int age, char ch);
	Player(const Player &obj);
	char getterCh();
	Player& getObject();
	Player(Player&& obj);
	void setWinner(bool n_winner);
	void setX(int n_X);
	void setY(int n_Y);
	int getTimes();
	void setTimes(int n_times);
    bool getWinner();
	
	int getX();
	int getY();
	
 
	~Player();
	void print();
	

};

#endif // PLAYER_HPP
