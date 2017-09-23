/*#pragma once
#include<iostream>
#include "UnoCard.h"
#include "UnoCard.cpp"
#include "Bag.h"
#include "OrderedList.h"
#define NUM_OF_PLAYERS 3
#define NUM_OF_CARDS 40
#define NUM_OF_CARDS_PER_PLAYER 7
#include <string>
#include<ostream>
#include"UnoGame.h"
using namespace std;
enum Player{ PLAYER1 = 1, PLAYER2 = 2, PLAYER3 = 3, PLAYER4 = 4 };

class UnoPlayer: 
private:
	int playerNum;
	//friend std::ostream& operator<<(std::ostream& os, const UnoPlayer &c);
	
public:
	UnoPlayer();
	int findMatch(OrderedList<UnoCard> hand, UnoCard key);
	UnoPlayer(int num);
	OrderedList<UnoCard> hand;
	void print();
};*/

#ifndef UnoPlayer_h
#define UnoPlayer_h
#include"OrderedList.h"
#include"UnoCard.h"
#include<string>
#include<iostream>


class UnoPlayer {
private:
	static unsigned playerNum;
	unsigned numCards;
	std::string _name;
	OrderedList <UnoCard> _hand;
public:
	UnoPlayer();
	~UnoPlayer();
	int cardMatch(UnoCard pile);
	void addCard(UnoCard card);
	void removeCard(int pos);
	UnoCard retrieveCard(int pos);
	unsigned getNumofCards();
	std::string getPlayerName();
	friend std::ostream& operator<<(std::ostream& os, UnoPlayer cards);
};



inline std::ostream& operator<<(std::ostream& os, UnoPlayer cards)
{
	os << cards._name << " Cards:\n\t";
	for (unsigned i = 0; i < cards._hand.getLength(); i++)
	{
		os << cards._hand.retrieve(i) << '\t';
	}
	os << '\n';
	return os;
}
#endif