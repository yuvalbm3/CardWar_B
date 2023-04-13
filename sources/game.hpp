#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "card.hpp"

namespace ariel{
    class Game{
    public:
        Game(Player&, Player&);
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
        // integer from statistics
        int p1_win_rate, p2_win_rate, draw_num, turn_num;
        Player &_p1;
        Player &_p2;

    };
}
#endif