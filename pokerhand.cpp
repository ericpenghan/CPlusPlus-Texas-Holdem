/* File: pokerhand.cpp
 * Course: CS216-00x
 * Project: Lab 9 (as part of Project 2)
 * Purpose: the implementation of member functions for the PokerHand class.
 */
#include "pokerhand.h"
#include "SortedLinkedList.h"
#include "card.h"




// Default constructor.
// We allow a blank PokerHand to be created.
// However, the default constructor should make sure
// that hand_rank is (Rank::NoRank, 0).
PokerHand::PokerHand()
{
  hand_rank = Rank(Rank::NoRank,0);
}

// It should store the FIVE cards
// given as parameters in the cards[] array.
// It should also immediately evaluate the hand, determine
// its rank: ranking kind and the card value
void PokerHand::setPokerHand(Card in_hand[], int size)//done
{
  for(int i = 0; i < size; i++)
  {
    cards[i] = in_hand[i];// stores in hands card into 5 cards
  }
  isStraightFlush();//to see it is is StrightFlush,unf
  isFourOfAKind();//determine,unf
  isFullHouse();//determine,unf
  isFlush();//dertermine,unf
  isSequence();//dertermine if is straight
  isThreeOfAKind();//determine
  isPair();//dertermine
  isHighCard();//dertermine
}

// Compare this hand versus otherHand according
// to the rules of poker. 
// Returns a negative number (< 0) 
// if this hand loses to // the otherHand.
// Returns a positive number (> 0) 
// if this hand beats the otherHand.
// Returns zero if it's a tie.
//
// An invalid hand loses to any hand. If both hands
// are invalid, the result is undefined (could be
// negative, zero or positive).
int PokerHand::compareHand(const PokerHand &otherHand)
{

  if(hand_rank.kind < otherHand.hand_rank.kind)
  {
    return -1;
  }
  else if(hand_rank.kind > otherHand.hand_rank.kind)
  {
    return 1;
  }
  else
  {
  	if(hand_rank.point < otherHand.hand_rank.point)
  	{
   		return -1;
  	}
  	else if(hand_rank.point > otherHand.hand_rank.point)
  	{
    	return 1;
  	}
    else{
		return 0;
	}
  }
  //don't know how to do invalid
}

// Prints out the five cards and its rank to standard output.
// It should look like:
// Five cards:
// one card per line
// then followed by "Its rank is: rank"
void PokerHand::print()
{
  sort();//sort cards first
  cout << endl;
  for(int i = 0; i < 5; i++)
  {
    cards[i].print();
  }
  cout << endl;
  hand_rank.print();
}

// Return the rank of this hand.
Rank PokerHand::getRank() const
{
  return hand_rank;
}


// The following "isXXXX()" functions shoudl all:
// 1. Assume that the hand is already sorted;
// 2. If true, store the rank in hand_rank;
// 3. use the rank if hand_rank is available.

// Returns true if the hand is a StraightFlush
//              and set the hand_rank (StraightFlush, highest point of the sequence FIVE)
// otherwise returns false
bool PokerHand::isStraightFlush()//Done
{
  sort();// sort it frist
  if(isAllOneSuit() == true && isSequence() == true)
  {
    hand_rank.kind = Rank::StraightFlush;
    hand_rank.point = cards[0].point;
    return true;
  }
  else
  {
    return false;
  }
  
}

// Returns true if the hand is a Four of a Kind
//              and set the hand_rank (FourOfAKind, highest point of the same FOUR)
// otherwise returns false
bool PokerHand::isFourOfAKind()//done
{
  sort();

#if 0 
  int count = 0;
  int value1 = 0;
  for(int i = 0; i < 5; i++)
  {
	count = 0;//reset
    if(cards[i].point == cards[i+1].point)
    {
      count++;//increment
      value1 = cards[i].point;//get the highest of same four 
    }
  }
  if(count == 3)
  {
    hand_rank.kind = Rank::FourOfAKind;
     hand_rank.point = value1;//set to the priate vaiable
   // hand_rank.point = cards[0].point;
	count = 0; //reset 
    return true;
  }
  else
  {
    return false;
  }
#else

	if ((cards[0].point == cards[3].point) || (cards[1].point == cards[4].point)){
	hand_rank.kind = Rank::FourOfAKind;
	hand_rank.point = cards[2].point;
	return true;
}
	else{
		return false;
	}
#endif
}

// Returns true if the hand is a Full House
//              and set the hand_rank (FullHouse, highest point of the same THREE)
// otherwise returns false
bool PokerHand::isFullHouse()//done
{
  sort();
  if(cards[0].point == cards[1].point && cards[0].point == cards[2].point && cards[3].point == cards[4].point)
  {
    hand_rank.kind = Rank::FullHouse;
    hand_rank.point = cards[0].point;//hightest of the same three
    return true;
  }
  if(cards[0].point == cards[1].point && cards[2].point == cards[3].point && cards[3].point == cards[4].point)
  {
    hand_rank.kind = Rank::FullHouse;
    hand_rank.point = cards[3].point;//highest point of the same three
    return true;
  }
  else
  {
    return false;
  }
}

// Returns true if the hand is a Flush
//              and set the hand_rank (Flush, highest point of the FIVE)
// otherwise returns false
bool PokerHand::isFlush()//done
{
  sort();//sort it first
  if(isAllOneSuit() == true)
  {
    hand_rank.kind = Rank::Flush;
    hand_rank.point = cards[0].point;//return the highest point of the five
    return true;
  }
  else
  {
    return false;
  }
}

// Returns true if the hand is a Straight
//              and set the hand_rank (Straight, highest point of the sequence FIVE)
// otherwise returns false
bool PokerHand::isStraight()//done
{
  sort();//sort it frist
  if(isSequence()== true)
  {
    hand_rank.kind = Rank::Straight;
    hand_rank.point = cards[0].point;//return the highest point of the five
    return true;
  }
  else
  {
    return false;
  }
}

// Returns true if the hand is a Three of a Kind
//              and set the hand_rank (ThreeOfAKind, highest point of the same THREE)
// otherwise returns false
bool PokerHand::isThreeOfAKind()//done
{
  sort();
#if 0 
  int count = 0;
  int val = 0;
  for(int i = 0; i < 5; i++)
  {
    if(cards[i].point == cards[i+1].point)
    {
	  count = 0; //set to 0 
      count++;//increment
      val = cards[i].point;//set to the highest of the same three
    }
  }
  if(count == 2)
  {
    hand_rank.kind = Rank::ThreeOfAKind;
     hand_rank.point = val;
    //hand_rank.point = cards[0].point;
    return true;
  }
  else
  {
    return false;
  }
#else

if ((cards[2].point == cards[4].point) && (cards[0].point != cards[1].point)){
	hand_rank.kind = Rank :: ThreeOfAKind;
	hand_rank.point = cards[2].point;
	return true;
}
else if ((cards[1].point == cards[3].point) && (cards[0].point != cards[4].point)) {
	hand_rank.kind = Rank :: ThreeOfAKind;
	hand_rank.point = cards[2].point;
	return true;
}

else if ((cards[0].point == cards[2].point) && (cards[4].point != cards[3].point)){
	hand_rank.kind = Rank :: ThreeOfAKind;
	hand_rank.point = cards[2].point;
	return true;
}

else{
	return false;
}

#endif
}

// Returns true if the hand is a Pair (we consider one pair or two pairs is a Pair)
//              and set the hand_rank (Pair, highest point of any pair)
// otherwise returns false
bool PokerHand::isPair()//done
{
  sort();
  int count = 0;
  int val1 =0;
  int val2 = 0;
  for(int i = 0; i < 5; i++)
  {
    if(cards[i].point == cards[i+1].point)
    {
      count++;//increment
      val1 = cards[i].point;
    }
    else
    {
      if(cards[i+1].point == cards[i+2].point)
      {
       // count = 0;//reset count
       // count ++;//increment
        val2 = cards[i+1].point;
      }
    }
  }
  if(count == 1)
  {
    hand_rank.kind = Rank::Pair;
    if (val1 >= val2)
      hand_rank.point = val1;//return the highest point of the pair
    else
    {
      hand_rank.point = val2;
    }
    
    return true;
  }
  else
  {
    return false;
  }
}

// Returns true if the hand is a High Card
//              and set the hand_rank (High Card, highest point of the FIVE)
// otherwise returns false
bool PokerHand::isHighCard()//done
{
  if(isStraightFlush() == false && isFourOfAKind() == false && isFullHouse() == false && isFlush() == false && isStraight() == false && isThreeOfAKind() == false && isPair() == false)
  {
    hand_rank.kind = Rank::HighCard;
    hand_rank.point = cards[0].point;
    return true;
  }
  else
  {
    return false;
  }
}

/******helper functions**********/

// to help sort the FIVE cards in decreasing order by card points
//right
void PokerHand::sort()
{
    SortedLinkedList sortCards;
    for (int i =0; i < FIVE; i++)
        sortCards.insert(cards[i]);

    vector<Card> sorted_cards = sortCards.access();
    for (int i = 0; i < FIVE; i++)
        cards[i] = sorted_cards[i];
}

// to help decide if FIVE cards are all of one suit
// return true if they are
// otherwise return false
bool PokerHand::isAllOneSuit()
{
  if( cards[0].suit == cards[1].suit && cards[0].suit == cards[2].suit && cards[0].suit == cards[3].suit && cards[4].suit)// not sure if it's right
  {
    return true;
  }
  else
  {
    return false;
  }
}
// to help decide if FIVE cards are in a continuous sequence
// return true if they are 
// otherwise return false
bool PokerHand::isSequence()
{
  if(cards[0].point == cards[1].point+1 && cards[1].point == cards[2].point+1 && cards[2].point == cards[3].point+1 && cards[3].point == cards[4].point+1 )// if in decreasing orders, wrong but don't know why
  {
    return true;
  }
  else
  {
    return false;
  }
}

