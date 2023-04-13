#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include <string>
#include <vector>

namespace ariel{
    class Player{
    public:
        Player(std::string);
        Player();
        std::string getName();   //return the player name
        int stacksize();
        int cardesTaken();
        void setName(std::string);
        Card::card getCard();
        const std::vector<Card::card>& getPlayerDeck() const{
            return playerDeck;
        }
        void setPlayerDeck( std::vector<Card::card> &vector){
            playerDeck = vector;
        }
        const std::vector<Card::card>& getTakenCards() const{
            return takenCards;
        }
        void setTakenCards(const Card::card &card){
            takenCards.push_back(card);
        }

    private:
        std::string _name;
        // The card deck of the player
        std::vector<Card::card> playerDeck;
        // Deck of card the player won in the game
        std::vector<Card::card> takenCards;
    };

}

#endif