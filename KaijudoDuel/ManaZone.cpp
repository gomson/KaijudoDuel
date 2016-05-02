#include "ManaZone.h"

ManaZone::ManaZone()
{
}

ManaZone::~ManaZone()
{
}

void ManaZone::renderCards(int myPlayer)
{
	for (int i = 0; i < cards.size(); i++)
	{
		cards.at(i)->render(myPlayer);
	}
}

//void ManaZone::handleEvent(sf::Event event)
//{
//	for (int i = 0; i < cards.size(); i++)
//	{
//		cards.at(i)->handleEvent(event);
//	}
//}

void ManaZone::addCard(Card* c)
{
	//c->move(x + CARDZONEOFFSET + CARDORIGINOFFSET + cards.size() * CARDSEPERATION, y + CARDZONEOFFSET + CARDORIGINOFFSET);
	c->setPosition(glm::vec3(mPos.x + CONST_CARDSEPERATION*cards.size(), mPos.y, mPos.z + (mPos.z + mHeight) / 2));
	c->unflip();
	c->untap();
	cards.push_back(c);
}

void ManaZone::removeCard(Card* c)
{
	int x = 0;
	for (std::vector<Card*>::iterator i = cards.begin(); i != cards.end(); i++)
	{
		if (*i == c)
		{
			cards.erase(i);
			break;
		}
		x++;
	}
	for (int i = x; i < cards.size(); i++)
	{
		//cards.at(i)->setPosition(cards.at(i)->x - CARDSEPERATION, cards.at(i)->y);
	}
}

int ManaZone::getUntappedMana()
{
	int c = 0;
	for (std::vector<Card*>::iterator i = cards.begin(); i != cards.end(); i++)
	{
		if ((*i)->isTapped==false)
		{
			c++;
		}
	}
	return c;
}

void ManaZone::tapMana(int count)
{
	int c = 0;
	for (std::vector<Card*>::iterator i = cards.begin(); i != cards.end(); i++)
	{
		if ((*i)->isTapped == false)
		{
			(*i)->tap();
			c++;
			if (c >= count) break;
		}
	}
}

