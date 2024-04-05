#include <iostream> 
#include <cstdlib> 
#include <ctime>
using namespace std;
int diceRoll(); 
int humanTurn(int); 
int computerTurn(int);  

int main() 
{         
	int human_total_score = 0, computer_total_score = 0;                  
	srand(time(NULL)); /* To get various game results, set a different seed for rand() each time. */                      
	
	/* Continue playing until someone scores 100 or more */     
	do         
	{                 
		human_total_score = human_total_score + humanTurn(human_total_score); /* to the running total, add the score from a new turn.  */               
		cout << "Your total score so far is " << human_total_score << "." << endl;                 
		
		if(human_total_score >= 100)                 
		{                         
			cout << "You win!";                         
			return 0;                 
		}                 
		
		computer_total_score = computer_total_score + computerTurn(computer_total_score); /* to the running total, add the score from a new turn. */                
		cout << "Computer total score so far is " << computer_total_score << "." << endl;  

		if(computer_total_score >= 100)                 
		{                         
			cout << "Computer wins!";                         
			return 0;                 
		}         
	}while(human_total_score < 100 && computer_total_score < 100);
}  
/* simulate rolling of dice */
int diceRoll() 
{         
	return (rand() % 6) + 1; /* A call to rand() returns 0-5, + 1 to give a range of 1-6 */
}  

int humanTurn(int human_total_score) 
{         
	int turn_score = 0, score = 0;         
	char rollOrHold;                  
	/* If you choose to keep playing, the game will keep going until you either roll again or a 1 is thrown. */         
	do         
	{                 
		score = diceRoll(); /* roll the dice */                                
		if(score == 1) /* If the dice rolls 1, the total score for that round is 0.*/                
		{                         
			cout << "You rolled a 1.  End of turn." << endl;                         
			return 0;                 
		}                                  
		turn_score = turn_score + score; /* running total for this turn only */                                                 
		cout << "You rolled a " << score << ".  Score so far this turn is " << turn_score << "." << endl;          
		
		/* If you input an illegal character, we'll keep looping and asking you to try again. */                
		do                
		{                         
			cout << "Roll again (r) or Hold (h)? ";                         
			cin >> rollOrHold;                 
		}while(rollOrHold != 'r' && rollOrHold != 'R' && rollOrHold != 'h' && rollOrHold != 'H');         
	
	}while(rollOrHold == 'r' || rollOrHold == 'R');                 
	
	if(rollOrHold == 'h' || rollOrHold == 'H') 
		return turn_score; /* finsh turn and return total score if player chooses to Hold */

	return turn_score;
}  
			
int computerTurn(int computer_total_score) 
{         
	int turn_score = 0, score = 0;                  
	/* The computer is going to keep playing until the score for this turn is less than 20. */       
	do         
	{                 
		score = diceRoll(); /* roll the dice */                                  
		if(score == 1) /* If the dice rolls 1, the total score for that round is 0. */              
		{                         
			cout << "Computer rolled a 1.  End of turn." << endl;                         
			return 0;                 
		}                                  
		turn_score = turn_score + score; /* running total for this turn only */                                                 
		cout << "Computer rolled a " << score << ".  Score so far this turn is " << turn_score << "." << endl;         
	}while(turn_score < 20);          
	/* finsh turn and return total score if the Computer scored 20+ */        
	if(turn_score >= 20)        
	{                 
		cout << "Computer holds." << endl;                 
		return turn_score;         
	}
	return turn_score;
}
