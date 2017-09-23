#pragma once
#include <iostream>
#include <string>

class UnoCard
{
public:
	// User defined Colour and Denomination
	enum Colour { RED = 1, BLUE, GREEN, YELLOW };
	enum Number { N1 = 1, N2, N3, N4, N5 };
	UnoCard(); // constructor with some default values
	~UnoCard(); // destructor
	UnoCard(Colour c, Number d);
	friend bool operator==(const UnoCard card1, const UnoCard card2);
	friend std::ostream& operator<<(std::ostream& out, const UnoCard card);
	friend bool operator>(const UnoCard card1, const UnoCard card2);
	friend bool operator<(const UnoCard card1, const UnoCard card2);

private:
	 // private storage of denomination
	Colour m_colour;
	Number m_number;
};

