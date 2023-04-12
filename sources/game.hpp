#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "card.hpp"

namespace ariel{
    class Game{
    public:
        Game();
        Game(Player&, Player&);
        // ~Game(){};
        void printLastTurn();
        void playTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

    private:
        std::string _name;
        std::string last_turn;
        std::string log;
        int turn_counter;
        Player &_p1;
        Player &_p2;
        // std::vector<Card::cardData> p2_hand;
        // std::vector<Card::cardData> p1_hand;

    };
}
#endif