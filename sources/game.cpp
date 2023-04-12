#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

// using ::Game;
// using ::Player;
// using ::Card;

namespace ariel{
    Game::Game(Player& p1, Player& p2):
    _p1(p1), _p2(p2)
    {   turn_counter = 0;
        std::string last_turn = "";
        std::string log = "";
        Card c;
        Card::Deck deck;
        std::vector<Card::card> p1_vec = p1.getPlayerDeck();
        std::vector<Card::card> p2_vec = p2.getPlayerDeck();
        c.Card::initialShuffeledDeck(deck, p1_vec, p2_vec);
        p1.setPlayerDeck(p1_vec);
        p2.setPlayerDeck(p2_vec);
        std::cout << "\n p1 playerDeck size is: " << p1_vec.size() <<endl; 
        std::cout << "\n p1 stacksize is: " << p1.stacksize() << endl; 
        std::cout << "\n p1 cardesTaken is: " << p1.cardesTaken() << endl; 
        std::cout << "\n p1 name is: " << p1.getName() << endl; 
        std::cout << "\n p2 playerDeck size is: " << p2_vec.size() <<endl; 
        std::cout << "\n p2 stacksize is: " << p2.stacksize() << endl; 
        std::cout << "\n p2 cardesTaken is: " << p2.cardesTaken() << endl;
        std::cout << "\n p2 name is: " << p2.getName() << endl; 
        // std::cout << "\n1";
    }

    void Game::printLastTurn(){
        cout << ariel::Game::last_turn <<endl;
    }

    void Game::playTurn(){
        if (&_p1 == &_p2){
            throw std::invalid_argument("Can't start game with only one player. Or with 2 players with same name.");
        }

        if (_p1.stacksize() > 0 && _p2.stacksize() > 0)
        {   
            // cout << "\n1" << endl;
            last_turn = "";
            vector<Card::card> p1_vec = _p1.getPlayerDeck();
            vector<Card::card> p2_vec = _p2.getPlayerDeck();
            std::vector<Card::card> temp; 
            bool draw = false;
            // cout << "\n2" << endl;
            Card a;
            Card::card card_a = _p1.getCard();
            p1_vec.pop_back();
            Card::card card_b = _p2.getCard();
            p2_vec.pop_back();
            int comp = a.Card::compareCards(card_a, card_b);
            last_turn += _p1.getName() +" played " + a.Card::getRankString(card_a) + " of " + a.Card::getSuitString(card_a) + " " + _p2.getName() + " played " + a.Card::getRankString(card_b) + " of " + a.Card::getSuitString(card_b) + ". ";
            // cout << "\n3" << endl;
            cout << comp << endl;
            if(comp == 0){
                int still_comp;
                bool war = true;
                draw = true;
                while(war){
                    last_turn += "Draw. ";
                    std::cout << "\n &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                    std::cout << "\n1.there was draw: " << temp.size() << endl;
                    temp.push_back(card_a);
                    temp.push_back(card_b);
                    // upsidedown cards
                    temp.push_back(p1_vec.back());
                    p1_vec.pop_back();
                    temp.push_back(p2_vec.back());
                    p2_vec.pop_back();
                    std::cout << "\n2.there was draw: " << temp.size() << endl;
                    Card::card card_c = _p1.getCard();
                    p1_vec.pop_back();
                    Card::card card_d = _p2.getCard();
                    p2_vec.pop_back();
                    std::cout << "\n3.there was draw: " << temp.size() << endl;
                    last_turn += _p1.getName() +" played " + a.Card::getRankString(card_c) + " of " + a.Card::getSuitString(card_c) + " " + _p2.getName() + " played " + a.Card::getRankString(card_d) + " of " + a.Card::getSuitString(card_d) + ". ";
                    int still_comp = a.Card::compareCards(card_c, card_d);
                    // temp.push_back(card_c);
                    // temp.push_back(card_d);
                    std::cout << "\nstill comp: " << still_comp << endl;
                    if(still_comp != 0 ){
                        war = false;
                        if(still_comp == 1){
                            std::cout << "still comp == 1" << endl;
                            last_turn += _p1.getName() + " Wins.";
                            while(temp.size() != 0){
                                Card::card la = temp.back();
                                std::cout << "\np1_The card is: " << endl;
                                a.Card::printCard(la);
                                _p1.setTakenCards(la);
                                temp.pop_back();
                            }
                        }
                        else if(still_comp == 2){
                            std::cout << "still comp == 2" << endl;
                            last_turn += _p2.getName() + " Wins.";
                            while(temp.size() != 0){
                                Card::card la = temp.back();
                                std::cout << "\np2_The card is: " << endl;
                                a.Card::printCard(la);
                                _p2.setTakenCards(la);
                                temp.pop_back();
                            }
                        }
                    }
                }
            }
            else if(comp == 1){
                // std::ostringstream oss;
                // oss << _p1.getName() << " played " << a.Card::getRankString(card_a) << " of " << a.Card::getSuitString(card_a) << _p2.getName() << " played " << a.Card::getRankString(card_b) << " of " << a.Card::getSuitString(card_b) << ". " << _p1.getName() << "wins." << endl;
                // std::string last_turn = oss.str();
                last_turn += _p1.getName() + " Wins.";
                // std::cout << "\np1_vec before is: " << _p1.cardesTaken() << endl;
                _p1.setTakenCards(card_a);
                _p1.setTakenCards(card_b);
                // if(draw){
                //     std::cout << "\n &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                //     std::cout << "\nthere was draw: " << temp.size() << endl;
                //     while(temp.size() != 0){
                //         Card::card la = temp.back();
                //         std::cout << "\np1_The card is: " << endl;
                //         a.Card::printCard(la);
                //         _p1.setTakenCards(la);
                //         temp.pop_back();
                //     }
                // }
                _p1.setPlayerDeck(p1_vec);
                // std::cout << "\np1_vec after is: " << _p1.cardesTaken() << endl;
                // cout << "\n ---"<< _p1.getName() << " cardesTaken is: " << _p1.cardesTaken() << endl; 
            } 
            else if(comp == 2){
                // std::ostringstream oss;
                // oss << _p1.getName() << " played " << a.Card::getRankString(card_a) << " of " << a.Card::getSuitString(card_a) << _p2.getName() << " played " << a.Card::getRankString(card_b) << " of " << a.Card::getSuitString(card_b) << ". " << _p2.getName() << "wins." << endl;
                // std::string last_turn = oss.str();
                last_turn += _p2.getName() + " Wins.";
                // std::cout << "\np2_vec before is: " << _p2.cardesTaken() << endl;
                _p2.setTakenCards(card_a);
                _p2.setTakenCards(card_b);
                // if(draw){
                //     std::cout << "\n &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                //     std::cout << "\nthere was draw: " << temp.size() << endl;
                //     while(temp.size() != 0){
                //         Card::card la = temp.back();
                //         std::cout << "\np2_The card is: " << endl;
                //         a.Card::printCard(la);
                //         _p2.setTakenCards(la);
                //         temp.pop_back();
                //     }
                // }
                _p2.setPlayerDeck(p2_vec);
                // std::cout << "\np2_vec after is: " << _p2.cardesTaken() << endl;
                // cout << "\n ---"<< _p2.getName() << " cardesTaken is: " << _p2.cardesTaken() << endl; 
            }
            log += last_turn + "\n";
            cout << "\n" << last_turn << endl;
        }
        else{
            throw runtime_error("Can't run. Game Over.");
        }
    }

    void Game::playAll(){
        int i=0;
        while(_p1.stacksize() > 0 && _p2.stacksize() > 0){
            // cout << i << "\n" << endl;
            cout << "\np1 stacksize in round " << i <<" : " << _p1.stacksize() << endl;
            cout << "\np2 stacksize in round " << i <<" : " << _p2.stacksize() << endl;
            cout << "\np1 cardsTaken in round " << i <<" : " << _p1.cardesTaken() << endl;
            cout << "\np2 cardsTaken in round " << i <<" : " << _p2.cardesTaken() << endl;
            i++;
            Game::playTurn();
        }
    }

    void Game::printWiner(){
        if( _p1.cardesTaken() > _p2.cardesTaken() ){
            std::cout << "The winner is: " << _p1.getName() << endl; 
        }
        else if( _p1.cardesTaken() < _p2.cardesTaken() ){
            std::cout << "The winner is: " << _p2.getName() << endl; 
        }
        else if( _p1.cardesTaken() == _p2.cardesTaken() ){
            std::cout << "There is no winner, it's a DRAW!" << endl; 
        }
    }

    void Game::printLog(){
        std::cout << log << endl;
    }

    void Game::printStats(){
        std::cout << "printStats";
    }
}






























// typedef struct game
// {
//     Player _p1;
//     Player _p2;

// }Game;

// class game{
// private:
//     Player _p1;
//     Player _p2;
// public:
    // game(Player p1, Player p2){
    //     _p1 = p1;
    //     _p2 = p2;
    // };
    // string printLastTurn();
    // void playTurn();
    // void playAll();
    // void printWiner();
    // void printLog();
    // void printStats();
//};