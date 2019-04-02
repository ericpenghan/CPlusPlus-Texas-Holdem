#include "card.h"


// Type definition for the suits of a playing card.
// Invalid means the Card object has not been initialized.
// Note: outside Card member functions, refer this type using Card::cSuits,
// Card::Spades, Card::Hearts, ...
//
typedef enum {Invalid, Spade, Club, Heart, Diamond} cSuits;//not sure what to do

// Type definition for the point value of a playing card.
// A point value of 0 means the Card object has not been initialized.
// J = 11, Q = 12, K = 13, A = 14.
// A point value of 1 is not used.
// Note: outside Card member functions, refer this type using Card::cPoints
//
typedef unsigned int cPoints;//not sure

// Default constructor.
// We allow uninitialized Cards to be created.
// This allows arrays of Cards.
// Uninitialized cards should have Invalid for its suit
// and 0 for its points.
Card::Card()
{
  suit = Invalid;//invalid
  point = -1;//invalid
}

// Alternate constructor
// Create a Card with specified suit and points.
Card:: Card(cSuits s, cPoints p)
{
  suit = s;
  point = p;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other)
{
  if (this->point < other.point)
  {
    return -1;
  }
  if (this->point > other.point)
  {
    return 1;
  }
  else  //this->point == other.point
  {
    return 0;
  }
}

// Display a description of the Card object to standard output.
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again
void Card::print()//not sure if it's right
{
  string Num;
  switch (point) {
    case 11://should be good 
      Num = " J";
      switch (suit) {
        case Diamond:
          cout << DIAMOND << Num << DIAMOND << " ";
          break;
        case Heart:
          cout << HEART << Num << HEART << " ";
          break;
        case Club:
          cout << CLUB << Num << CLUB << " ";
          break;
       // case Spade:
          default:
          cout << SPADE << Num << SPADE << " ";
          break;
      }
      break;
      
    case 10://should be good 
      switch (suit) {
        case Diamond:
          cout << DIAMOND << point << DIAMOND << " ";
          break;
        case Heart:
          cout << HEART << point << HEART << " ";
          break;
        case Club:
          cout << CLUB << point << CLUB << " ";
          break;
          // case Spade:
        default:
          cout << SPADE << point << SPADE << " ";
          break;
      }
      break;
      
    case 12://should be good 
      Num = " Q";
      switch (suit) {
         
        case Diamond:
          cout << DIAMOND << Num << DIAMOND << " ";
          break;
        case Heart:
          cout << HEART << Num << HEART << " ";
          break;
        case Club:
          cout << CLUB << Num << CLUB << " ";
          break;
          // case Spade:
        default:
          cout << SPADE << Num << SPADE << " ";
          break;
      }
      break;
      
    case 13://should be good 
      Num = " K";
      switch (suit) {
          
        case Diamond:
          cout << DIAMOND << Num << DIAMOND << " ";
          break;
        case Heart:
          cout << HEART << Num << HEART << " ";
          break;
        case Club:
          cout << CLUB << Num << CLUB << " ";
          break;
          // case Spade:
        default:
          cout << SPADE << Num << SPADE << " ";
          break;
      }
      break;
      
    case 14://should be good 
      Num = " A";
      switch (suit) {
          
        case Diamond:
          cout << DIAMOND << Num << DIAMOND << " ";
          break;
        case Heart:
          cout << HEART << Num << HEART << " ";
          break;
        case Club:
          cout << CLUB << Num << CLUB << " ";
          break;
          // case Spade:
        default:
          cout << SPADE << Num << SPADE << " ";
          break;
      }
      break;
      
     
      
    default://should be good
      Num = " ";
      switch (suit) {
        case Diamond:
          cout << DIAMOND << Num << point << DIAMOND << " ";
          break;
        case Heart:
          cout << HEART << Num << point << HEART << " ";
          break;
        case Club:
          cout << CLUB << Num << point << CLUB << " ";
          break;
          case Spade:
       // default:
          cout << SPADE << Num << point << SPADE << " ";
          break;
      }
      break;
  }
 
//  cout << "Display four suits in one row: " << endl;
//  cout << SPADE << "\t" << CLUB << "\t" << HEART << "\t" << DIAMOND << endl;

  
}

