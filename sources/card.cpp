#include "card.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


// using ::Card;

namespace ariel {
    // int Card::stacksize() {
    //     return 52; // standard deck size
    // }

    // int Card::cardesTaken() {
    //     return 0; // no cards taken yet
    // }

    void Card::initialShuffeledDeck(Deck& deck, std::vector<card>& p1, std::vector<card>& p2){
        card card;
        for( int suit = 0; suit < suitSize ; suit++){
            for( int rank = 0; rank < rankSize ; rank++){
                card.suit = Suit(suit);
                card.rank = Rank(rank);
                deck.cards.push_back(card);
            }
        }
        // Deck shuffled;
        int i=0;
        while (!deck.cards.empty()){
            if(i < 26){
                size_t rand_index = (size_t)rand() % deck.cards.size();
                p1.push_back(deck.cards[rand_index]);
                deck.cards.erase(deck.cards.begin() + (int)rand_index);
                i++;
            }
            else{
                size_t rand_index = (size_t)rand() % deck.cards.size();
                p2.push_back(deck.cards[rand_index]);
                deck.cards.erase(deck.cards.begin() + (int)rand_index);
            }
            
        }
        // deck = shuffled;
    }

    void Card::printDeck(const Deck& deck){
        for(card c: deck.cards){
            printCard(c);
        }
    }

    void Card::printCard(card& card){
        std::cout << "Rank: " << Card::getRankString(card) << "  Suit:" << Card::getSuitString(card) << "/n" << std::endl;
    }

    int Card::compareCards(card c1, card c2){
        int card_a = getRank(c1);
        int card_b = getRank(c2);  
        if (card_a == 14 && card_b == 2){
            return 2;
        }  
        else if (card_b == 14 && card_a == 2){
            return 1;
        }
        else if (card_b > card_a){
            return 2;
        }
        else if (card_a > card_b){
            return 1;
        }
        else if (card_a == card_b){
            return 0;
        }
        return 0;
    }

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
    // void Card::shuffleDeck(Deck& deck){
    //     Deck shuffled;
    //     while (!deck.cards.empty()){
    //         size_t rand_index = rand() % deck.cards.size();
    //         shuffled.cards.push_back(deck.cards[rand_index]);
    //         deck.cards.erase(deck.cards.begin() + rand_index);
    //     }
    //     deck = shuffled;
    // }

    // void dealDeck(Card::Deck& deck, std::vector<Card>& p1, std::vector<Card>& p2){
    //     int i = 0;
    //     while (i < 26){
    //         p1.push_back(deck.cards.pop_back());
    //         i+= 1;
    //     }
    //     p2 = deck;
    // }

    // int main()
    // {
    //     Card c;
    //     Card::Deck myDeck;
    //     std::vector<Card::cardData> p1;
    //     std::vector<Card::cardData> p2;
    //     c.Card::initialShuffeledDeck(myDeck, p1, p2);
    //     return 0;
    // }

// }
}


