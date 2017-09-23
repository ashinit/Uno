/*
#pragma once
#define NUM_OF_PLAYERS 3
#define NUM_OF_CARDS 40
#define NUM_OF_CARDS_PER_PLAYER 7
#include "UnoPlayer.h"
#include "Stack.h"
#include "Queue.h"
#include "time.h"
#include "UnoCard.h"


class UnoGame {
private:
	//UnoPlayer* player;
	Bag<UnoCard> bag;
	Queue<UnoCard> deck;
	Stack<UnoCard> faceUp;
public:

	UnoGame();
	~UnoGame();
	void play();
//	UnoGame();

	

	
	OrderedList<UnoCard> getAHand(UnoPlayer playr);
	void genFaceUpPile();
	bool checkDeck();
};

UnoGame::~UnoGame()
{
//	delete[] player;
	deck.~Queue();
	faceUp.~Stack();
	bag.~Bag();
}
UnoGame::UnoGame()
{

	// make a bag add all the cards to it
	Bag<UnoCard> bag(40);
	Colour c[] = { RED,GREEN,BLUE,YELLOW };
	Number n[] = { N1,N2,N3,N4,N5 };
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j <= 5; j++)
			{
				bag.add(UnoCard(c[i], n[j]));
			}
		}
	}

	for (int i = 0; i < NUM_OF_CARDS; i++) {
		deck.enqueue(bag.getOne());
	}
}


OrderedList<UnoCard> UnoGame::getAHand(UnoPlayer playr)
{
	for (int k = 0; k < NUM_OF_CARDS_PER_PLAYER; k++)
	{
		playr.hand.insert(deck.dequeue());
	}
}

void UnoGame::genFaceUpPile()
{
	if (deck.isEmpty() == 1) { checkDeck(); }

	else
	{
		faceUp.push(deck.dequeue());
	}
}

bool UnoGame::checkDeck()
{
	if (deck.isEmpty() == 0)
	{
		for (int i = 0; i < faceUp.size(); i++) {
			deck.enqueue(faceUp.pop());
		}
	}
}

void UnoGame::play()
{

	//create players
	UnoPlayer player1(1);
	UnoPlayer player2(2);
	UnoPlayer player3(3);


	cout << "Welcome to Uno!" << endl;
	cout << "START" << endl;


	//create a hand for each player using deck
	OrderedList<UnoCard> player1Hand = getAHand(player1);
	OrderedList<UnoCard> player2Hand = getAHand(player2);
	OrderedList<UnoCard> player3Hand = getAHand(player3);

	genFaceUpPile();

	if (!deck.isEmpty())
	{
		cout << "Top card is: " << faceUp.peek();
		cout << "Player1's hand is:"; player1.print();
		cout << "Player2's hand is:"; player2.print();
		cout << "Player3's hand is:"; player3.print();

		//PLAYER 1
		cout << "It's Player1's turn!" << endl;
		int x = player1.findMatch(player1Hand, faceUp.peek()); //searches for match in hand
		if (x != -1) { //if match is found, remvoe from hand and add to faceuppile
			cout << "Player 1 Found a Match!"<<endl;
			player1Hand.remove(x);
			faceUp.push(player1Hand.retrieve(x));
		}
		else {
			cout << "No match found, player draws from deck" << endl;
			player1Hand.insert(deck.dequeue());
		}

		//int end = player1Hand.getLength();
		switch (player1Hand.getLength())
		{
		case(1) :
			cout << "Player1 yells UNO!" << endl;
		case(0) :
			cout << "Player1 is the Winner!" << endl;
			cout << "GAME OVER!" << endl;
			break;

		}

		//PLAYER 2
		cout << "It's Player2's turn!" << endl;
		x = player2.findMatch(player2Hand, faceUp.peek()); //searches for match in hand
		if (x != -1) { //if match is found, remvoe from hand and add to faceuppile
			player2Hand.remove(x);
			faceUp.push(player2Hand.retrieve(x));
		}
		else {
			player2Hand.insert(deck.dequeue());
		}

		//int end = player2Hand.getLength();
		switch (player2Hand.getLength())
		{
		case(1) :
			cout << "Player2 yells UNO!" << endl;
		case(0) :
			cout << "Player2 is the Winner!" << endl;
			cout << "GAME OVER!" << endl;
			break;

		}

		//PLAYER 3
		cout << "It's Player3's turn!" << endl;
		x = player3.findMatch(player3Hand, faceUp.peek()); //searches for match in hand
		if (x != -1) { //if match is found, remvoe from hand and add to faceuppile
			player3Hand.remove(x);
			faceUp.push(player3Hand.retrieve(x));
		}
		else {
			player3Hand.insert(deck.dequeue());
		}
		//int end = player3Hand.getLength();
		switch (player3Hand.getLength())
		{
		case(1) :
			cout << "Player3 yells UNO!" << endl;
		case(0) :
			cout << "Player3 is the Winner!" << endl;
			cout << "GAME OVER!" << endl;
			break;

		}
	}
	else
	{
		UnoCard temp = faceUp.pop();
		while (faceUp.isEmpty() == 0)
		{
			deck.enqueue(faceUp.pop());
		}
		faceUp.push(temp);
		std::cout << "The deck has been repopulated" << endl;
	}
}
*/


//#ifndef UnoGame_h
#define UnoGame_h

#include"UnoPlayer.h"
#include"LinkedList.h"
#include"Queue.h"
#include"Stack.h"
#include"Bag.h"
#include<iostream>

class UnoGame {
private:
	UnoPlayer* player;//Someone can can make more players dynamically using arrays in the constructor
					  //this is they way I have adopted
	Stack <UnoCard> faceUp;
	Queue <UnoCard> faceDown;
	Bag <UnoCard> bag;
public:
	UnoGame();
	~UnoGame();
	void play();
};

