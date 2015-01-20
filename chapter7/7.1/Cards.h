#ifndef CARDS_H_INCLUDED
#define CARDS_H_INCLUDED

#define HEART   ((char)0x03)
#define DIAMOND ((char)0x04)
#define CLUB    ((char)0x05)
#define SPADE   ((char)0x06)

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

enum Suit {Spades, Clubs, Hearts, Diamonds};
enum Face {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card{
  friend class Deck;
  friend ostream& operator<<(ostream&, const Card&);
public:
  Card(Suit s, Face f): suit(s), face(f){}
  Card(const Card &orig): suit(orig.suit), face(orig.face){}
  Suit getSuit() const { return suit; }
  Face getFace() const { return face; }
private:
  Card(){}
  Suit suit;
  Face face;
};

ostream& operator<<(ostream &os, const Card& card){
  switch(card.suit){
    case Spades:
      os<<SPADE;
      break;
    case Clubs:
      os<<CLUB;
      break;
    case Hearts:
      os<<HEART;
      break;
    case Diamonds:
      os<<DIAMOND;
      break;
    default:;
  }
  switch(card.face){
    case Ace:
      os<<'A';
      break;
    case Two: case Three: case Four: case Five: case Six: case Seven: case Eight: case Nine:
      os<<char('1'+card.face);
      break;
    case Ten:
      os<<"10";
      break;
    case Jack:
      os<<'J';
      break;
    case Queen:
      os<<'Q';
      break;
    case King:
      os<<'K';
      break;
    default:;
  }
  return os;
}

class Deck{
friend ostream& operator<<(ostream&, const Deck&);
public:
  static const int Nsuit=4, Nface=13;
  Deck(){
    for(int i=0; i<Nsuit; ++i){
      for(int j=0; j<Nface; ++j){
        cards[i*Nface+j]=Card(Suit(i), Face(j));
      }
    }
  }
  Deck(const Deck& deck){
    for(int i=0; i<Nsuit*Nface; ++i)
      cards[i]=deck.cards[i];
  }
  void Shuffle(){
    int total=Nsuit*Nface;
    srand(time(NULL));
    for(int i=0; i<total; ++i)
      swap(cards[i], cards[rand()%total]);
  }
private:
  Card cards[Nsuit*Nface];
};

ostream& operator<<(ostream &os, const Deck &deck){
  for(int i=0; i<deck.Nsuit*deck.Nface; ++i){
    os<<deck.cards[i]<<"\t";
  }
  return os;
}


#endif // CARDS_H_INCLUDED
