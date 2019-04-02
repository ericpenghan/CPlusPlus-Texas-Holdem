//
//  main.cpp
//  PA2
//
//  Created by Eric Han on 3/28/19.
//  Copyright © 2019 Eric Han. All rights reserved.
//
//modify card.cpp, pokerhand.cpp has problem with invalid, rank.h says the alternate one needs to test it
//ask dr.pike if i can change card.h to add a print function on it to print out the thing

#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"
#include <cstdlib>

using namespace std;

// avoid magic numbers
const int SEVEN = 7;
const int FIVE = 5;
const int TWO = 2;

// decide the best five cards out of seven cards
// best means the highest ranking of five-card poker hand defined in the poker game
// pass in a vector of seven cards
// (const call by reference: safe for the arugment and no copy is made for efficiency)
// return the best PokerHand object which represents the best five-card poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards);
void game()
{
  Deck deck;//new deck
  deck.createDeck();
  deck.shuffleDeck();
  vector<Card> Me;//player
  vector<Card> Com;//computer
  vector<Card> table;//table
  vector<Card> addWMe;//player and table
  vector<Card> addWCom;//player and computer
  
  cout << "The cards in your hand are:" << endl;
  for(int i = 0; i < TWO; i++){//generate 2 cards to user
    Me.push_back(deck.deal_a_card());
    cout << "\t";
    Me[i].print();//print one card at a time
    cout << endl;
  }
  cout << endl; // have a extra line
  cout << "The FIVE cards on the deck to share are:\n";
  cout << "\t*************************\n";
  
  for(int i = 0; i < FIVE; i++){//generate 5 cards to table
    table.push_back(deck.deal_a_card());
    cout << "\t*\t";//print spacing
    table[i].print();
    cout << "\t\t*\n";
  }
  cout << "\t*************************\n";
  cout << "The cards in computer's hand are:" << endl;
  for(int i = 0; i < TWO; i++){//generate 2 cards to conputer
    Com.push_back(deck.deal_a_card());
    cout << "\t";
    Com[i].print();//print out the two cards, not right yet
    cout << endl;
  }
  
  for(int i = 0; i < TWO; i++){//push 2 cards from me to the adding vector
    addWMe.push_back(Me[i]);
  }
  for(int i = 0; i < FIVE; i++){//push 5 cards from table to the adding vecotr, complete
    addWMe.push_back(table[i]);
  }
//	cout << "user " << endl;
//  for (int i = 0; i < addWMe.size(); i++){
//		addWMe[i].print();
//	}
  for(int i = 0; i < TWO; i++){//push 2 cards from com to the adding vector
    addWCom.push_back(Com[i]);
  }
  for(int i = 0; i < FIVE; i++){//push 5 cards from table to the adding vecotr, complete
    addWCom.push_back(table[i]);
  }
//	cout << "computer " << endl;
//  for (int i = 0; i < addWCom.size(); i++){
//		addWCom[i].print();
//	}
  
#if 1
  PokerHand user, computer;
  cout << endl;
  cout << "Player 1: You\n";
  user = best_FIVE_out_of_SEVEN(addWMe);//best hand of user
  cout << "Player 2: Computer\n";
  computer = best_FIVE_out_of_SEVEN(addWCom);//best hand of computer
  
  
  if (user.compareHand(computer) == 1)//userwin
  {
    cout << "Congratulations, you win the game!\n";
    cout << endl;
  }
  else if (user.compareHand(computer) == 0)
  {
    cout << "It is a tie game!\n";
    cout << endl;
  }
  
//  if (user.compareHand(computer) == -1)
  else {
    cout << "Sorry, the computer wins the game!\n";
    cout << endl;
  }
  
#else
  
  PokerHand user, computer;
  user = best_FIVE_out_of_SEVEN(addWMe);
  computer = best_FIVE_out_of_SEVEN(addWCom);
  
  cout << "user";
  user.print();// << endl;
  cout <<  "Computer ";
  computer.print();// << endl;
  
#endif
  
  
}

int main()
{
  game(); //run the game
  
  //  Deck deck;//new deck
  //  deck.createDeck();
  //  deck.shuffleDeck();
  //  vector<Card> Me;//player
  //  vector<Card> Com;//computer
  //  vector<Card> table;//table
  //  vector<Card> addWMe;//player and table
  //  vector<Card> addWCom;//player and computer
  //
  //  cout << "The cards in your hand are:" << endl;
  //  for(int i = 0; i < TWO; i++){//generate 2 cards to user
  //    Me.push_back(deck.deal_a_card());
  //    cout << "\t";
  //   Me[i].print();//print one card at a time
  //    cout << endl;
  //  }
  //  cout << endl; // have a extra line
  //  cout << "The FIVE cards on the deck to share are:\n";
  //  cout << "\t**************************************\n";
  //
  //  for(int i = 0; i < FIVE; i++){//generate 5 cards to table
  //    table.push_back(deck.deal_a_card());
  //    cout << "\t*\t";//print spacing
  //    table[i].print();
  //    cout << "\t\t*\n";
  //  }
  //  cout << "\t**************************************\n";
  //  cout << "The cards in computer's hand are:" << endl;
  //  for(int i = 0; i < TWO; i++){//generate 2 cards to conputer
  //    Com.push_back(deck.deal_a_card());
  //    cout << "\t";
  //    Com[i].print();//print out the two cards, not right yet
  //    cout << endl;
  //  }
  //
  //  for(int i = 0; i < TWO; i++){//push 2 cards from me to the adding vector
  //    addWMe.push_back(Me[i]);
  //  }
  //  for(int i = 0; i < FIVE; i++){//push 5 cards from table to the adding vecotr, complete
  //    addWMe.push_back(table[i]);
  //  }
  //
  //  for(int i = 0; i < TWO; i++){//push 2 cards from com to the adding vector
  //    addWCom.push_back(Com[i]);
  //  }
  //  for(int i = 0; i < FIVE; i++){//push 5 cards from table to the adding vecotr, complete
  //    addWCom.push_back(table[i]);
  //  }
  //
  //  PokerHand testH[TWO];
  //  cout << endl;
  //  cout << "Player 1: You\n";
  //  testH[0]= best_FIVE_out_of_SEVEN(addWMe);//best hand of user
  //  cout << "Player 2: Computer\n";
  //  testH[1]= best_FIVE_out_of_SEVEN(addWCom);//best hand of computer
  //  PokerHand bestH;
  //
  //
  //  if (testH[0].compareHand(testH[1]) == 1)//userwin
  //  {
  //    cout << "Congratulations, you win the game!\n";
  //    cout << endl;
  //  }
  //  if (testH[0].compareHand(testH[1]) == 0)
  //  {
  //    cout << "Its rank is a tie game!\n";
  //    cout << endl;
  //  }
  //  if (testH[0].compareHand(testH[1]) == -1)
  //  {
  //    cout << "Sorry, the computer wins the game!\n";
  //    cout << endl;
  //  }
  
  string response;
  cout << "Do you want to play poker game again(Press 'q' or 'Q' to quit the program)";
  getline(cin,response);

  while(response != "Q" && response != "q")
  {
    game();//repeat the game
  cout << "Do you want to play poker game again(Press 'q' or 'Q' to quit the program)";
  getline(cin,response);

  }
  cout << "Thank you for using this program!\n";
  
  return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
{
  
  PokerHand bestH;
  PokerHand cardsH;
  
  // check if the parameter is valid
  if (cards.size() != SEVEN)
  {
    cout << "Invalid Cards, we need SEVEN cards!" << endl;
    return cardsH; // return a PokerHand object by default constructor
  }
  
  // Consider all possible ways of dropping two cards
  // from all seven cards
  // i is the index of the first card dropped
  // and j is the index of the second card dropped.
  // There are 21 different ways to pick 5 cards out of 7
  for (int i=0; i < SEVEN; i++)
  {
    for (int j=i+1; j < SEVEN; j++)
    {
      Card pick[FIVE];
      int index = 0;
      
      // Iterate over all seven cards and assign them to the pick[] array
      // exclude cards with index numbers of #i and #j.
      for (int k=0 ; k < SEVEN ; k++)
      {
        if (k == i || k == j)
          continue;
        pick[index] = cards[k];
        index++;
      }
      
      // create a PokerHand with pick[]
      cardsH.setPokerHand(pick, FIVE);
      
      // Check to see if current pick is better than
      // the best you have seen so far
      if (bestH.compareHand(cardsH) < 0)
      {
        bestH = cardsH ;
      }
    }
  }
  
  // Now bestH holds the best poker hand among all 21 poker hands
  cout << "*** Best five-card hand ***" << endl;
  bestH.print();
  cout << endl << endl;
  return bestH;
}




