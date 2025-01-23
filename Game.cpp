#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <memory>
using namespace std ;

Game::Game()
{
	
  	
 array =new char* [3];
  for(int i=0 ; i<3; i++){
	  array[i] = new char [3];
	 }
	  
	  for(int i=0; i<3; i++){
	  for (int j = 0; j <3; j++) {
			
			 array[i][j] = '_';	
		
	 }
	  }
	  
	  
	  countO= 0;
	  countX =0;
	  
	  
	  //cout << "Simple constructor Game ..."<<endl;
 
}
Game::Game(const Game &obj)
{
	
  //cout << "Coppy constructor Game ..."<<endl;	
 array =new char* [3];
  for(int i=0 ; i<3; i++){
	  array[i] = new char [3];
	   
	 }
	  for(int i=0; i<3; i++){
	  for (int j = 0; j <3; j++) {
			
			 array[i][j] = '_';	
		
	 }
	  }
	  
	  countO= 0;
	  countX=0;
 
}



 char* Game::getter()  {
	
	return *array;
	}


void Game:: play( Player& player){
	//if(array[player.getX()][player.getY()]=='_'){
		
if(player.getY()==1 && array[player.getX()][0]=='_'){
		
		   player.setY(0);
		   array[player.getX()][player.getY()] = player.getterCh();
		
		
		}
else if(player.getY()==2 && array[player.getX()][1]=='_')	
		{
			//cout<<"hey";
			player.setY(1);
			array[player.getX()][player.getY()]= player.getterCh();
			
			}
else if(player.getY()==3 && array[player.getX()][2]=='_' )	
		{
			player.setY(2);
			array[player.getX()][player.getY()] = player.getterCh();
			
			}


	//player.setTimes(count);
	checkWinner( player);
	print();
	
	
}

void Game::checkWinner(Player& player){
	
	int counterVerticalO= 0;
	int counterHorizontalO=0;
	int counterVerticalX= 0;
	int counterHorizontalX=0;
	if ( player.getterCh()=='O' || player.getterCh()=='X'){
	     
		 for (int i = 0; i <3; i++) {
			 
        for (int j = 0; j <3; j++) {
			if( array[i][j]== 'O'){
				
				if(i!=j){ 
					
					counterVerticalO++;
					countO=j;
					 } 
				else if(i == j){
					   counterVerticalO++;
					   
					   }
				else if (countO == j && counterVerticalO <= 2){
						counterHorizontalO ++;

					}  	   
				  
				}
			else if( array[i][j]== 'X'){
				
				if(i!=j){ 
					
					counterVerticalX++;
					countX=j;
					 } 
				else if(i == j){
					   counterVerticalX++;
					   
					   }
				else if (countX == j && counterVerticalX <= 2){
						counterHorizontalX ++;

					}  	   
				  
				}	
		
			}
			
			if((counterVerticalO==3 || counterHorizontalO ==3) || (counterVerticalX==3 || counterHorizontalX ==3)){
				player.setWinner(true); 
				cout<< "Winner is "<<endl;
				player.print();
		//		cout << "Address "<<player.getterCh() 
        // << addressof(player) << endl;
					 break;
				}
		
	
	 }
		
		
		   

	 }

	}

	
void Game::checkPlayer(vector<Player>& players){
	int player1Times = 0;
	int player2Times = 0;
	
	
	if(!players.empty()){
		
		
		while(players.at(0).getWinner() == false && players.at(1).getWinner() == false){
		
		
		  if( player1Times == 0){
			promtPlayer(players.at(0));
			  
			  player1Times ++;
			  }else if(player1Times> player2Times){// 1 | 0
				  promtPlayer(players.at(1));
			  
			  player2Times ++;
				  
				  
				  }else if( player1Times == player2Times){ // 2| 1
					  promtPlayer(players.at(0));
			  
			              player1Times ++;
					  
					  }
			  
			  }
		
			
			
		}
		}
	
	
	
	

	
	
	
void Game:: promtPlayer(Player &player){
	int x, y;
	// cout << "Address "<<player.getterCh()<<"  : " 
    //     << addressof(player) << endl;
	cout<<"Player with character: "<<player.getterCh() <<" choose a position horizontal (numbers: 0-2): "<<endl;
	cin >> x;
	while(!cin || cin.peek() != '\n' ||(x>2 ||x<0) ){
		 cin.clear();    
      
      // Ignore the invalid input in the buffer
        cin.ignore(1000, '\n'); 
        cout << "Invalid input. Please try again: ";
        cin >> x;
		 
		 }
	cout<<"Player with character "<<player.getterCh() << " choose a position vertical (numbers: 1-3): "<<endl;
	cin >> y;
	while(!cin || cin.peek() != '\n' ||(y>3 || y<=0)){
		 cin.clear();    
      
      // Ignore the invalid input in the buffer
        cin.ignore(1000, '\n'); 
        cout << "Invalid input. Please try again: ";
        cin >> y;
		 
		 }
	
	 player.setX(x);
	 player.setY(y);
	 play(player);
	
	
	
	}
	

	



void Game:: print(){
	
	 
	
	  
	 for (int i = 0; i <3; i++) {
		 
		 
        for (int j = 0; j <3; j++) {
			
			 
			cout<<array[i][j];
	
			}
		    cout<<endl;
        	 
		
	 }
	    
}
	
Game::~Game()
{
	for(int i=0; i<3; i++){
		delete [] array[i];
		
		}
		
	 delete [] array;
	
	 
	// cout << "Calling destructor .. Game" <<endl;

	
}	