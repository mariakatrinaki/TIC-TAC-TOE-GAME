#include "Player.hpp"
#include <iostream>

using namespace std;


Player::Player()
{
		  
	  isWinner=false;
	  x=0;
	  y=0;
	  times =0;
}

Player& Player::getObject() {
    return *this; 
}

// Return a reference to the current object
Player::Player(string name, int age, char ch){
	
	
	this->name =name;
	this->age= age;
	this->ch =ch;
    isWinner= false;
	x=0;
	y=0;
	times =0;
	
	//cout<< "calling simple constructor Player "<<endl;
	
	
	}
	
	
Player :: Player(Player&& obj){
	 
    
    name = std::move(obj.name);
    age = obj.age;
    ch = obj.ch;
    isWinner = obj.isWinner;
    x = obj.x;
    y = obj.y;
	times = obj.times;
	
	//cout<<"Calling moving constructor"<<endl;
	
	
	}	
	
Player::Player(const Player &obj){
	times= obj.times;
	name = obj.name;
    age = obj.age;
    ch= obj.ch;	
	isWinner = obj.isWinner;
    x= obj.x;
    y= obj.y;	
	
	//cout << "Calling copy constructor Player"<<endl;
		
		}




void Player:: print(){
	
	cout<< "Player Name: " << name <<endl;
    cout << "Age: " << age<<endl;
	cout << "Character: " << ch <<endl;
	
	
	}

char Player:: getterCh(){
	
	
	return ch;
	}



void Player :: setX(int n_X){
	
	x= n_X;
	}


void Player :: setY(int n_Y){
	
	y= n_Y;
	}

int Player :: getX(){
	
	
	return x;
	}
	
	
int Player :: getY(){
	
	
	return y;
	}


bool Player :: getWinner(){
	
	return isWinner;
	
	}
	
void Player	:: setWinner(bool n_winner){
	isWinner = n_winner;
	
	}

void Player:: setTimes(int n_times){
	times = n_times;
	
	}

int Player:: getTimes(){
	
	
	return times;
	}



Player::~Player()
{
	//delete times; 
	// cout << "Calling destructor Player"<<endl;
	
}

