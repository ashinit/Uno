#include<iostream>
#include"Bag.h"
#include"Linkedlist.h"
#include"Stack.h"
#include"Queue.h"
#include"StandardFunctors.h"
#include "time.h"
#include "UnoGame.h"
int main()
{
	//create game
	UnoGame game;
	game.play();
	game.~UnoGame();
}



/*#include"OrderedList.h"
//#include"UnoPlayer.h"
using namespace std;

int main()
{
	cout << "Welcome to Uno!" << endl;
	cout << "START" << endl;
	srand((unsigned int)time(NULL));

	UnoGame game;
	
	//create players
	UnoPlayer player1(1);
	UnoPlayer player2(2);
	UnoPlayer player3(3);

	//create a hand for each player using deck
	OrderedList<UnoCard> player1Hand = game.getAHand(player1);
	OrderedList<UnoCard> player2Hand = game.getAHand(player2);
	OrderedList<UnoCard> player3Hand = game.getAHand(player3);

	game.genFaceUpPile();
	cout << "Top card is: " << game.faceUp.peek();
	cout << "Player1's hand is:"; player1.print();
	cout << "Player2's hand is:"; player2.print();
	cout << "Player3's hand is:"; player3.print();
	
	//PLAYER 1
	cout << "It's Player1's turn!" << endl;
	int x = player1.findMatch(player1Hand, game.faceUp.peek()); //searches for match in hand

	if (x != -1) { //if match is found, remvoe from hand and add to faceuppile
		player1Hand.remove(x);
		game.genFaceUpPile.add(x);
	}

	int end = player1Hand.getLength;
	switch (end)
	{
	case(1):
		cout << "Player1 yells UNO!" << endl;
	case(0):
		cout << "Player1 is the Winner!" << endl;
		cout << "GAME OVER!" << endl;
		break;
			
	}
	/*if (player1Hand.getLength == 1){ //checks to see if player has only one card in hand
		cout << "Player1 yells UNO!" << endl;
	}
	if (player1Hand.isEmpty() == 0){ //checks to if player's hand is empty
		cout << "Player1 is the Winner!" << endl;
		cout << "GAME OVER!" << endl;
	}*/

	/*
	//PLAYER 2
	cout << "It's Player2's turn!" << endl;
	int x = player2.findMatch(player2Hand, game.faceUp.peek()); //searches for match in hand

	if (x != -1) { //if match is found, remvoe from hand and add to faceuppile
		player2Hand.remove(x);
		game.genFaceUpPile.add(x);
	}
	if (player2Hand.getLength == 1) { //checks to see if player has only one card in hand
		cout << "Player1 yells UNO!" << endl;
	}
	if (player2Hand.isEmpty() == 0) { //checks to if player's hand is empty
		cout << "Player1 is the Winner!" << endl;
		cout << "GAME OVER!" << endl;
	}


	//PLAYER 3
	cout << "It's Player3's turn!" << endl;
	int x = player3.findMatch(player1Hand, game.faceUp.peek()); //searches for match in hand

	if (x != -1) { //if match is found, remvoe from hand and add to faceuppile
		player1Hand.remove(x);
		game.genFaceUpPile.add(x);
	}
	if (player1Hand.getLength == 1) { //checks to see if player has only one card in hand
		cout << "Player3 yells UNO!" << endl;
	}
	if (player1Hand.isEmpty() == 0) { //checks to if player's hand is empty
		cout << "Player3 is the Winner!" << endl;
		cout << "GAME OVER!" << endl;
	}
	game.checkDeck();
}*/
