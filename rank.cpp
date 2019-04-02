/* File: rank.cpp
 * Course: CS216-00x
 * Project: Lab 9 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 *
 */
#include <iostream>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
  kind = NoRank;
  point = -1;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
// did not valid 
Rank::Rank(hRanks r, rPoints p)
{
  kind = r;
  point = p;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse( K)
//   Flush( A)
//   ...
void Rank::print()
{
//  string color;
//  if(kind == ThreeOfAKind)
//  {
//      cout << "Its rank is: " << "ThreeOfAKind" << "(" << point <<")" << endl;
//  }
//  else
//  {
//    if(kind == HighCard)
//      cout << "Its rank is: " << "HighCard" << "( " << point <<")" << endl;
//    if(kind == Pair)
//      cout << "Its rank is: " << "pair" << "( " << point <<")" << endl;
//    if(kind == Straight)
//      cout << "Its rank is: " << "Stright" << "( " << point <<")" << endl;
//    if(kind == Flush)
//      cout << "Its rank is: " << "Flush" << "( " << point <<")" << endl;
//    if(kind == FullHouse)
//      cout << "Its rank is: " << "FullHouse" << "( " << point <<")" << endl;
//    if(kind == FourOfAKind)
//      cout << "Its rank is: " << "FourOfAKind" << "( " << point <<")" << endl;
//    if(kind == StraightFlush)
//      cout << "Its rank is: " << "StrightFlush" << "( " << point <<")" << endl;
//  }
  string num;
  switch (kind) {//missing NoRank
    case HighCard:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "HighCard" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "HighCard" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "HighCard" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "HighCard" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "HighCard" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "HighCard" << "( " << point <<")" << endl;
          break;
      }
      break;
      
    case Pair:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "Pair" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "Pair" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "Pair" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "Pair" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "Pair" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "Pair" << "( " << point <<")" << endl;
          break;
      }
      break;
      
      case ThreeOfAKind:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "ThreeOfAKind" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "ThreeOfAKind" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "ThreeOfAKind" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "ThreeOfAKind" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "ThreeOfAKind" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "ThreeOfAKind" << "( " << point <<")" << endl;
          break;
      }
      break;
      
    case Straight:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "Straight" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "Straight" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "Straight" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "Straight" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "Straight" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "Straight" << "( " << point <<")" << endl;
          break;
      }
      break;
      
    case Flush:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "Flush" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "Flush" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "Flush" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "Flush" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "Flush" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "Flush" << "( " << point <<")" << endl;
          break;
      }
      break;
      
    case FullHouse:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "FullHouse" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "FullHouse" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "FullHouse" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "FullHouse" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "FullHouse" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "FullHouse" << "( " << point <<")" << endl;
          break;
      }
      break;
      
    case FourOfAKind:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "FourOfAKind" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "FourOfAKind" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "FourOfAKind" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "FourOfAKind" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "FourOfAKind" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "FourOfAKind" << "( " << point <<")" << endl;
          break;
      }
      break;
      
    case StraightFlush:
      switch (point) {
        case 10:
          cout << "Its rank is: " << "StraightFlush" << "(" << point <<")" << endl;
          break;
        case 11:
          num = " J";
          cout << "Its rank is: " << "StraightFlush" << "(" << num <<")" << endl;
          break;
        case 12:
          num = " Q";
          cout << "Its rank is: " << "StraightFlush" << "(" << num <<")" << endl;
          break;
        case 13:
          num = " K";
          cout << "Its rank is: " << "StraightFlush" << "(" << num <<")" << endl;
          break;
        case 14:
          num = " A";
          cout << "Its rank is: " << "StraightFlush" << "(" << num <<")" << endl;
          break;
        default:
          cout << "Its rank is: " << "StraightFlush" << "( " << point <<")" << endl;
          break;
      }
      break;
      
    default:
      break;
  }
}

