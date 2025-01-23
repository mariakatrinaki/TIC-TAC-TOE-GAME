#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>

using namespace std ;




void invalidInput(){
	
	cin.clear();    
      
      // Ignore the invalid input in the buffer
        cin.ignore(1000, '\n'); 
        cout << "Invalid input. Please try again: ";
	
	
	}
	
bool validName(string name)
{
    if(name.length() == 0)
        return false; // `name` cannot be empty

    for(int i = 0; i < name.length(); i++){
		
        if(name[i] >= '0' && name[i] <= '9'){ 
			
            return false; // There is a number in `name`
	}}
    return true; // `name` is valid
}
	

 vector<Player> players(){
	 
	 vector<Player> players;
	 players.reserve(2);
	 
	 string name;
	int age;
	char ch;
	
	
	do{
		
	cout << "Enter Name: " << endl;
	 cin>> name;
	 
	

    while (!validName(name) )
    {
	   	
       invalidInput();
	    cin>> name;
    }
	
	cout<< "Enter age: " <<endl;
	 cin >> age;

	
	while(!cin || cin.peek() != '\n' ||(age<=10 || age>100) ){
		 
		
        invalidInput();
        cin >> age;
		 
		 }
		 
	cout << "Choose character for the game O or X"<<endl;
    cin >> ch;
    
	if(players.empty() ){
	
     while(!cin || (ch!='O' && ch!='X') ){
			 invalidInput();
               cin >> ch;
			 
		 }
	}else{ 
		
		while(!cin || (ch!='O' && ch!='X') || players.at(0).getterCh() == ch ){
		if(players.at(0).getterCh() == ch){
			cout << "Character " << ch << " is already taken from another player.Please enter again: "<<endl;
			 cin>> ch;
			
			}else{	
				
            invalidInput();
            cin >> ch;
			
			} 
		 }
		
	}
	
	Player player (name,age,ch);
	
	players.emplace_back(player);
	
	} while (players.size()<2);
	
	if(!players.empty()){
		for(int i=0; i<players.size(); i++){
		players.at(i).print();
		
		}
	
	
	}
      	
	return players;
	
	}


vector<Player> menu(){
	char ch;
	vector<Player> vectorPlayers;
	
	cout << "Welcome to TIC TAC TOE game"<<endl;
	cout << "Do you want to play Y / N (Y=yes or N=no)"<<endl;
	cin >> ch;
	
	 while(!cin || (ch!='Y' &&  ch!='N')){
		 
        invalidInput();
        cin >> ch;
		 
		 }
	 switch (ch){
	   case 'Y':
	    vectorPlayers = players();
       break;  
	   
	   case 'N':
	     cout<< "Good bye !!"<<endl;
	    break;
	 }
	 
	 return vectorPlayers;
	 }
	 


	 

	




