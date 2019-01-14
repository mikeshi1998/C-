// ITP 365 Spring 2018
// HW5 Vector and Poker Hands
// Name: Yuchen Shi
// Email: yuchensh@usc.edu
// Platform: Mac

#include "ITPVector.hpp"
#include "Cards.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cout<<"Select an option...\n1. Test ITPVector\n2. Poker Hands\n>";
    int input;
    std::cin>>input;
    if (input == 1)
    {
        while (true) // Test the ITP vector continuously until the user kills the program
        {
            std::cout<<"***Constructing an ITPVector..."<<std::endl;
            ITPVector<int> testVector; // Create an empty vector
            std::cout<<"Contents: "<<testVector<<std::endl;
            std::cout<<"Capacity: "<<testVector.capacity()<<", Size: "<<testVector.size()<<std::endl;
            std::cout<<"Enter a number of elements to add: ";
            unsigned num;
            std::cin>>num;
            for (unsigned i = 0; i<num; i++)
            {
                testVector.insert_back(i*5);
            }
            std::cout<<"Contents: "<<testVector<<std::endl;
            std::cout<<"Capacity: "<<testVector.capacity()<<", Size: "<<testVector.size()<<std::endl;
            std::cout<<"The back element is: "<<testVector.get_back()<<std::endl;
            std::cout<<"Called remove_back"<<std::endl;
            testVector.remove_back();
            std::cout<<"Contents: "<<testVector<<std::endl;
            std::cout<<"Capacity: "<<testVector.capacity()<<", Size: "<<testVector.size()<<std::endl;
            std::cout<<"***Test Complete!"<<std::endl;
        }
        

    }
    else if (input == 2)
    {
        bool tryAgain = true;
        while (tryAgain)
        {
            ITPVector<Card> deck; // Create an empty vector
            createDeck(deck); // Create a deck from the empty vector and shuffle it
            PokerHand pokerHand(deck); // Draw the last 5 cards from the deck which is shuffled
            std::cout<<"You drew: "<<pokerHand<<std::endl;
            std::cout<<"You have "<<pokerHand.getBestPokerHand()<<std::endl;
            std::cout<<"Try again (y/n):";
            char option;
            std::cin>>option;
            if (option != 'y')
            {
                tryAgain = false;
            }
        }
    }
    
	return 0;
}
