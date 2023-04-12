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
    Player::Player(string nam){
        _name = nam;
    }

    Player::Player(){
        _name = "name";
    }

    std::string Player::getName(){
        return _name;
    }

    void Player::setName(std::string name){
        _name = name;
    }

    int Player::stacksize(){
        int len = playerDeck.size(); 
        return len;
    }

    int Player::cardesTaken(){
        int len = takenCards.size(); 
        return len;
    }

    Card::card Player::getCard(){
        // std::cout << "\n~~getCard - size before " << playerDeck.size() << endl;
        Card c;
        Card::card val = playerDeck.back();
        playerDeck.pop_back();
        // std::cout << "\n~~getCard - size after " << playerDeck.size() << endl;
        return val;
    }

}