#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int __DUELNUM__ = 10000; /* 10,000 duels.*/

void Aaron_shoots(bool aaron, bool& bob, bool& charlie); /* Randomly choose between 0,1, or 2. If ==1, missed shot. */
void Bob_shoots(bool& aaron, bool bob, bool& charlie); /* Randomly choose between 0 or 1. If ==0, missed shot. */
void Charlie_shoots(bool& aaron, bool& bob, bool charlie); /* Charlie is Deadshot.*/

int main()
{
	bool isAaronAlive, isBobAlive, isCharlieAlive;
	int Aaron_wins=0, Bob_wins=0, Charlie_wins=0;

	srand(time(NULL));

	/*
		All duels controled just in a for loop. program will look
		All 10000 duels individually
	*/
	for (int i = 0; i < __DUELNUM__; ++i)
	{
		/* before every duels set the conditions alive */
		isAaronAlive = true;  
		isBobAlive = true;
		isCharlieAlive = true;

		do
		{
			Aaron_shoots(isAaronAlive, isBobAlive, isCharlieAlive);
			Bob_shoots(isAaronAlive, isBobAlive, isCharlieAlive);
			Charlie_shoots(isAaronAlive, isBobAlive, isCharlieAlive);

		} while (((isAaronAlive == true) && (isBobAlive == true)) ||
				((isAaronAlive == true) && (isCharlieAlive == true)) || 
				((isBobAlive == true) && (isCharlieAlive == true)));

		/* Condition holding win numbers */
		if(isAaronAlive) 
			Aaron_wins++;
		if(isBobAlive) 
			Bob_wins++;
		if(isCharlieAlive) 
			Charlie_wins++;
	}
	
	cout << "Aaron won " << Aaron_wins << "/10000 duels or " << (double(Aaron_wins) / __DUELNUM__)*100
	<< "%" << endl;
	cout << "Bob won " << Bob_wins << "/10000 duels or " << (double(Bob_wins) / __DUELNUM__)*100
	<< "%" << endl;
	cout << "Charlie won " << Charlie_wins << "/10000 duels or " << (double(Charlie_wins) / __DUELNUM__)*100
	<< "%" << endl;

	return 0;
}

void Bob_shoots(bool& aaron, bool bob, bool& charlie)
{
	int shot;

	if (!bob)
	 	return;

	shot = rand() % 2;

	if (shot == 0)
	{
		if (charlie)
			charlie = false;
		else if (aaron)
			aaron = false;
	}

	return;
}

void Aaron_shoots(bool aaron, bool& bob, bool& charlie)
{
	int shot;

	if (!aaron)
	 	return;

	shot = rand() % 3;

	if (shot == 0)
	{
		if (charlie)
			charlie = false;
		else if (bob)
			bob = false;
	}

	return;
}

void Charlie_shoots(bool& aaron, bool& bob, bool charlie)
{
	int shot;

	if (!charlie)
	 	return;

	if (bob)
		bob = false;
	else if (aaron)
		aaron = false;
	return;
}