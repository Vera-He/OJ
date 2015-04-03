//File: BlackJack.cpp  
//Play the game 'BlackJack' with computer

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
char inputAndCheck();
void giveCard( int playcards[52], int handcards[20], int count[2], int amount = 1 );
void printCards( int handcards[20], int cards_num );
int calculate( int number );

int main(){
	
	int  playcards[52], handcards[20], player[2], computer[2], i; 
	  //**[0] represents the addtion, **[1] represents the amount of cards
	bool flag = 0;
	srand( time ( NULL ));
	
	while ( true ){
		
		cout << "\nDo you want to play game (y/n£©£¿";
		if ( inputAndCheck() == 'n')  break;
		for ( i = 0; i < 52; ++i ) playcards[i] = 0;
		player[0] = computer[0] = player[1] = computer[1] = flag = 0;
		
		//player stage
		cout << "\nStage of Player:\n" << "Player got cards: ";
		giveCard( playcards, handcards, player, 2 );
		
		while ( true ){
			
			cout << "\nDo you want another card (y/n£©£¿";
		    if ( inputAndCheck() == 'n')  break;
			
			cout << "One more card: ";
            giveCard( playcards, handcards, player );
	        
			if ( player[0] > 42 ) { 
			    cout << " \nPlayer lost !\n";
			    flag = 1;
			    break;
			}				
		} 
		if ( flag )   continue;
	
	    // computer stage
	    cout << "\nStage of Computer:\n" << "Computer got cards: ";
	    giveCard( playcards, handcards, computer, 2 );
			
		while ( computer[0] < player[0] || computer[0] == player[0] && computer[1] < player[1] ){
		  	
			  cout << " \nOne more card: ";
			  giveCard( playcards, handcards, computer );
		    
		      if ( computer[0] > 42 ) { 
			      cout << " \nPlayer won !\n";
			      flag = 1;
			      break;
		      }	
	    }
	    if ( !flag ) cout << " \nPlayer lost !\n";
    }
}

//traslate implicit numbers to explicit playing cards then show them to users
void printCards( int handcards[20], int cards_num ){
	
	int i;
	
    for ( i = 0; i < cards_num; ++i ){	   
	    switch( handcards[i] / 13 ){
		    case 0: cout << "  Hearts "; break;
		    case 1: cout << "  Spade "; break;
		    case 2: cout << "  Club "; break;
		    case 3:	cout << "  Diamond "; break;
	    }
	    switch( handcards[i] % 13 ){
	    	case 0: cout << 'A'; break;
		    case 10: cout << 'J'; break; 
		    case 11: cout << 'Q'; break; 
		    case 12: cout << 'K'; break; 
		    default: cout << handcards[i] % 13+1; 
	    }
	}
}

//generate a random card and add it to handcards, change the amount of cards and addition
void giveCard( int playcards[52], int handcards[20], int count[2], int amount ){
	 
	int card, i;
    
	for ( i = 0; i < amount; ++i ){ 
	    do{ 
	        card = rand() % 52;
	    }   while ( playcards[card] == 1);
	    playcards[card] = 1;
	    handcards[count[1]] = card;
	    count[0] += calculate( card % 13 );
	    ++count[1];
    }
    printCards( handcards, count[1] );
    cout<<endl<<count[0]<<endl; 
}

//calculate the actual value of the card
int calculate( int number){
	if ( number > 9 ) return 1;
	else return ( number + 1 ) * 2;	    
}

//let users input their answers and check them
char inputAndCheck(){
	
	char judge;
	
	while ( true ){
	    cin >> judge;
	    try {
	        if ( judge != 'y' && judge != 'n' )  throw 1;
	        cin.sync();  
		    return judge; 
	    } 
	    catch( int ){
	    	cin.sync();  
		    cout << " Your input is invalid, please try again:";
	    }
    }
}
