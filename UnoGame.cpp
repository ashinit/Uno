#include"UnoGame.h"
#include<iostream>

UnoGame::UnoGame()
{
	for (unsigned i = 0; i < 4; i++)
	{
		for (unsigned j = 0; j < 5; j++)
		{
			UnoCard c(static_cast<UnoCard::Colour>(i), static_cast<UnoCard::Number>(j));
			bag.add(c);
		}
	}

	/*while (!bag.isEmpty())
	{
		faceDown.enqueue(bag.getOne());
	}*/
	for (int i = 0; i < 40; i++) {
		faceDown.enqueue(bag.getOne());
	}

	player = new UnoPlayer[3];

	for (unsigned j = 0; j < 3; j++)
	{
		for (unsigned i = 1; i <= 7; i++)
		{
			player[j].addCard(faceDown.dequeue());
		}
	}
	faceUp.push(faceDown.dequeue());
}

UnoGame::~UnoGame()
{
	delete[] player;
	faceDown.~Queue();
	faceUp.~Stack();
	bag.~Bag();
}

void UnoGame::play()
{
	std::cout << "Welcome to UNO\n\nGame Start...\nFace Up Pile: " << faceUp.peek() << "\n_____________________________________\n\n";
	bool gameFinished = false;
	do
	{
		if (!faceDown.isEmpty())
		{
			for (unsigned i = 0; i < 3; i++)
			{
				UnoPlayer currPlayer = player[i];
				std::cout << "It is Player " << i + 1 << "'s turn:\n";
				int cardMatch = currPlayer.cardMatch(faceUp.peek());
				if (cardMatch == -1)
				{
					std::cout << "Player " << i + 1 << " did not find a match.They drew a card\n_____________________________________\n";
					currPlayer.addCard(faceDown.dequeue());
				}
				else
				{
					faceUp.push(currPlayer.retrieveCard(cardMatch));
					std::cout << "Player " << i + 1 << " found a match! TheyPlayed " << faceUp.peek() << "\n_____________________________________\n";
					currPlayer.removeCard(cardMatch);
				}
				if (currPlayer.getNumofCards() == 1)
				{
					std::cout << "\tPlayer " << i + 1 << " yells UNO!\n_____________________________________\n";
				}
				else if (currPlayer.getNumofCards() == 0)
				{
					std::cout << "************Player " << i + 1 << " Won! What a lame assignment(JK)************\n";
					gameFinished = true;
				}
			}
		}
		else
		{
			UnoCard temp = faceUp.pop();
			while (!faceUp.isEmpty())
			{
				faceDown.enqueue(faceUp.pop());
			}
			faceUp.push(temp);
			std::cout << "The deck has been repopulated\n_____________________________________\n";
		}
	} while (gameFinished);
	return;
}




