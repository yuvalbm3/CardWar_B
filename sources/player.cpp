#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

#include "card.hpp"
#include "player.hpp"


std::string _name;

namespace ariel{
    //constructor
    Player::Player(string nam){
        _name = nam;
    }

    //empty constructor
    Player::Player(){
        _name = "name";
    }

    //getters for the player name
    std::string Player::getName(){
        return _name;
    }

    //setters for the player name
    void Player::setName(std::string name){
        _name = name;
    }

    //return the number of cards in the player deck
    int Player::stacksize(){
        int len = playerDeck.size(); 
        return len;
    }

    //return the number of cards the player won
    int Player::cardesTaken(){
        int len = takenCards.size(); 
        return len;
    }

    //return card from player deck
    Card::card Player::getCard(){
        Card c;
        Card::card val = playerDeck.back();
        playerDeck.pop_back();
        return val;
    }

}