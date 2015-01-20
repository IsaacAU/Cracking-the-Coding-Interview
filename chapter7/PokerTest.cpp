#include<iostream>
#include "Cards.h"

using namespace std;

int main(){
    Deck deck;
    cout<<"Initial Poker:"<<endl;
    cout<<deck<<endl<<endl;
    deck.Shuffle();
    cout<<"Shuffle:"<<endl;
    cout<<deck<<endl<<endl;
}
