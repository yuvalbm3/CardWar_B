#include "card.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;



namespace ariel {

    // this function intial the deck, shuffel it and divid it to the 2 player
    void Card::initialShuffeledDeck(Deck& deck, std::vector<card>& p1, std::vector<card>& p2){
        //intial the deck
        std::vector<Card::card> temp; 
        card card;
        for( int rank = 0; rank < rankSize ; rank++){
            for( int suit = 0; suit < suitSize ; suit++){
                card.rank = Rank(rank);
                card.suit = Suit(suit);
                deck.cards.push_back(card);
            }
        }
        //shuffel the deck
        int i=0;
        while (!deck.cards.empty()){
            // if(i < 26){
            //     size_t rand_index = (size_t)rand() % deck.cards.size();
            //     p1.push_back(deck.cards[rand_index]);
            //     deck.cards.erase(deck.cards.begin() + (int)rand_index);
            //     i++;
            // }
            // else{
            //     size_t rand_index = (size_t)rand() % deck.cards.size();
            //     p2.push_back(deck.cards[rand_index]);
            //     deck.cards.erase(deck.cards.begin() + (int)rand_index);
            // }
            if(i < 26){
                p1.push_back(deck.cards.back());
                deck.cards.pop_back();
                i++;
            }
            else{
                temp.push_back(deck.cards.back());
                deck.cards.pop_back();
                i++;
            }
        }
        while(!temp.empty()){
            p2.push_back(temp.back());
            temp.pop_back();
        }
    }

    //print all the cards in the deck
    void Card::printDeck(const Deck& deck){
        for(card c: deck.cards){
            printCard(c);
        }
    }

    //print spesific card
    void Card::printCard(card& card){
        std::cout << "Rank: " << Card::getRankString(card) << "  Suit:" << Card::getSuitString(card) << "/n" << std::endl;
    }

    //compare 2 cards, and return which player won the match
    int Card::compareCards(card c1, card c2){
        int card_a = getRank(c1);
        int card_b = getRank(c2);
        //Ace weaker than 2 according to instructions  
        if (card_a == 14 && card_b == 2){
            return 2;
        }  
        //Ace weaker than 2 according to instructions  
        else if (card_b == 14 && card_a == 2){
            return 1;
        }
        //if card b rank is bigger, player 2 win
        else if (card_b > card_a){
            return 2;
        }
        //if card a rank is bigger, player 1 win
        else if (card_a > card_b){
            return 1;
        }
        //draw
        else if (card_a == card_b){
            return 0;
        }
        return 0;
    }

    //get rank of cards in integers
    int Card::getRank(const Card::card& card){
        switch (card.rank)
        {
        case Rank::TWO:
            return 2;
        case Rank::THREE:
            return 3;
        case Rank::FOUR:
            return 4;
        case Rank::FIVE:
            return 5;
        case Rank::SIX:
            return 6;
        case Rank::SEVEN:
            return 7;
        case Rank::EIGHT:
            return 8;
        case Rank::NINE:
            return 9;
        case Rank::TEN:
            return 10;
        case Rank::JACK:
            return 11;
        case Rank::QUEEN:
            return 12;
        case Rank::KING:
            return 13;
        case Rank::ACE:
            return 14;
        }
    }

    //get rank of cards in String for printing
    std::string Card::getRankString(const Card::card& card){
        switch (card.rank)
        {
        case Rank::TWO:
            return "2";
        case Rank::THREE:
            return "3";
        case Rank::FOUR:
            return "4";
        case Rank::FIVE:
            return "5";
        case Rank::SIX:
            return "6";
        case Rank::SEVEN:
            return "7";
        case Rank::EIGHT:
            return "8";
        case Rank::NINE:
            return "9";
        case Rank::TEN:
            return "10";
        case Rank::JACK:
            return "JACK";
        case Rank::QUEEN:
            return "QUEEN";
        case Rank::KING:
            return "KING";
        case Rank::ACE:
            return "ACE";
        }
    }

    //get suit of cards in String for printing
    std::string Card::getSuitString(const Card::card& card){
        switch (card.suit)
        {
        case Suit::CLUBS:
            return "CLUBS";
        case Suit::DIAMONDS:
            return "DIAMONDS";
        case Suit::HEARTS:
            return "HEARTS";
        case Suit::SPADES:
            return "SPADES";
        }
    }

}


