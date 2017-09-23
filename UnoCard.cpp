#include"UnoCard.h"



UnoCard::UnoCard()
{
	m_number = N1;
	m_colour = RED;
}

UnoCard::UnoCard(Colour color, Number value)
{
	m_colour = color;
	m_number = value;
}

UnoCard::~UnoCard()
{

}
