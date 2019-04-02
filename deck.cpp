#include "deck.h"
#include "stdlib.h"
// create a standard 52-card deck
void Deck::createDeck()//maybe not sure
{

      for (int s= Card::Spade; s <= SUITS; s++)
    {
        for (Card::cPoints val = CARD_START; val < RANKS+CARD_START; val++)
        {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit, val);
            deck.push_back(newcard);
        }
    }                                                                        
 }
void Deck::shuffleDeck()
{
  srand(time(0));
  Card temp;  // for swapping
  for (int i = deck.size()-1; i>= 1; i--)
  {
    int j = rand() % (i+1);
    temp = deck[j];
    deck[j] = deck[i];
    deck[i] = temp;
  }
  
}

// return a card from the tail of the deck
Card Deck::deal_a_card()
{
	Card tem = deck.back();
	deck.pop_back();
 	return tem;
}

