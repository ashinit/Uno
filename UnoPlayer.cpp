/*

#include "UnoPlayer.h"
#include "OrderedList.h"
#include "UnoGame.h"
#include "UnoGame.cpp"
#include "UnoCard.h"
#include "UnoCard.cpp"


UnoPlayer::UnoPlayer(int num)
{
	playerNum = num;
}

UnoPlayer::UnoPlayer() {
	std::cout << "Wrong Call";
}
int UnoPlayer::findMatch(OrderedList<UnoCard> hand, UnoCard key)
{
	for (int i = 0; i < hand.getLength(); i++)
	{
		if (hand.retrieve(i).m_colour == key.m_colour)
			return i;
		if (hand.retrieve(i).m_number == key.m_number)
			return i;
	}
	return -1;
}

void UnoPlayer::print() {
	for (int i = 0; i <= hand.getLength; i++)
	{
		cout << hand.retrieve << endl;
	}
}*/
#include"UnoPlayer.h"

unsigned UnoPlayer::playerNum = 0;

UnoPlayer::UnoPlayer()
{
	_name = "Player";
	numCards = 0;
	playerNum++;
}

UnoPlayer::~UnoPlayer()
{
	_hand.~OrderedList();
}

int UnoPlayer::cardMatch(UnoCard pile)
{
	for (unsigned i = 0; i < _hand.getLength(); i++)
	{
		if (_hand.retrieve(i) == pile)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}

void UnoPlayer::addCard(UnoCard card)
{
	_hand.insert(card);
	numCards++;
}

void UnoPlayer::removeCard(int pos)
{
	_hand.remove(pos);
	numCards--;
}

UnoCard UnoPlayer::retrieveCard(int pos)
{
	return _hand.retrieve(pos);
}

unsigned UnoPlayer::getNumofCards()
{
	return numCards;
}

std::string UnoPlayer::getPlayerName()
{
	return _name;
}