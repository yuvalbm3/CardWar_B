#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"


namespace ariel{
    // Constructor
    Game::Game(Player& player_1, Player& player_2):
    _p1(player_1), _p2(player_2)
    {   p1_win_rate = 0;
        p2_win_rate= 0;
        draw_num = 0;
        turn_num = 0;
        std::string last_turn = "";
        std::string log = "";
        Card c;
        Card::Deck deck;
        std::vector<Card::card> p1_vec = player_1.getPlayerDeck();
        std::vector<Card::card> p2_vec = player_2.getPlayerDeck();
        c.Card::initialShuffeledDeck(deck, p1_vec, p2_vec);
        player_1.setPlayerDeck(p1_vec);
        player_2.setPlayerDeck(p2_vec);
        // std::cout << "\n p1 playerDeck size is: " << p1_vec.size() <<endl; 
        // std::cout << "\n p1 stacksize is: " << p1.stacksize() << endl; 
        // std::cout << "\n p1 cardesTaken is: " << p1.cardesTaken() << endl; 
        // std::cout << "\n p1 name is: " << p1.getName() << endl; 
        // std::cout << "\n p2 playerDeck size is: " << p2_vec.size() <<endl; 
        // std::cout << "\n p2 stacksize is: " << p2.stacksize() << endl; 
        // std::cout << "\n p2 cardesTaken is: " << p2.cardesTaken() << endl;
        // std::cout << "\n p2 name is: " << p2.getName() << endl; 
        // std::cout << "\n1";
    }

// function that print the last turn
    void Game::printLastTurn(){
        cout << ariel::Game::last_turn <<endl;
    }

// play one turn, if draw play another one
    void Game::playTurn(){
        // check that there are 2 different players
        if (&_p1 == &_p2){
            throw std::invalid_argument("Can't start game with only one player. Or with 2 players with same name.");
        }
        //enter only if there are cards in the players decks
        else if (_p1.stacksize() > 0 && _p2.stacksize() > 0)
        {   
            // increase the number of turns for the statitstics
            turn_num ++;
            last_turn = "";
            // create 2 vectors of card for the players
            vector<Card::card> p1_vec = _p1.getPlayerDeck();
            vector<Card::card> p2_vec = _p2.getPlayerDeck();
            // temp vector from draw situations
            std::vector<Card::card> temp; 
            bool draw = false;
            Card a;
            //get the cards for the card war
            Card::card card_a = _p1.getCard();
            p1_vec.pop_back();
            Card::card card_b = _p2.getCard();
            p2_vec.pop_back();
            //compare both cards
            int comp = a.Card::compareCards(card_a, card_b);
            last_turn += _p1.getName() +" played " + a.Card::getRankString(card_a) + " of " + a.Card::getSuitString(card_a) + " " + _p2.getName() + " played " + a.Card::getRankString(card_b) + " of " + a.Card::getSuitString(card_b) + ". ";
            // if comp is 0, there is a draw
            if(comp == 0){
                int still_comp;
                bool war = true;
                draw = true;
                // enter the card to the temp deck
                temp.push_back(card_a);
                temp.push_back(card_b);
                while(war){
                    draw_num++;
                    last_turn += "Draw. ";
                    // upsidedown cards
                    temp.push_back(p1_vec.back());
                    p1_vec.pop_back();
                    temp.push_back(p2_vec.back());
                    p2_vec.pop_back();
                    //check 2 new cards
                    Card::card card_c = _p1.getCard();
                    p1_vec.pop_back();
                    Card::card card_d = _p2.getCard();
                    p2_vec.pop_back();
                    last_turn += _p1.getName() +" played " + a.Card::getRankString(card_c) + " of " + a.Card::getSuitString(card_c) + " " + _p2.getName() + " played " + a.Card::getRankString(card_d) + " of " + a.Card::getSuitString(card_d) + ". ";
                    //compare the cards
                    int still_comp = a.Card::compareCards(card_c, card_d);
                    //id still_comp is not 0, there is no draw again.
                    if(still_comp != 0 ){
                        //to break the while loop
                        war = false;
                        //player 1 is the winner
                        if(still_comp == 1){
                            p1_win_rate++;
                            last_turn += _p1.getName() + " Wins.";
                            //bring all the cards in the temp vector to the winner
                            while(temp.size() != 0){
                                Card::card this_card = temp.back();
                                _p1.setTakenCards(this_card);
                                temp.pop_back();
                            }
                        }
                        //player 2 is the winner
                        else if(still_comp == 2){
                            p2_win_rate++;
                            last_turn += _p2.getName() + " Wins.";
                            //bring all the cards in the temp vector to the winner
                            while(temp.size() != 0){
                                Card::card this_card = temp.back();
                                _p2.setTakenCards(this_card);
                                temp.pop_back();
                            }
                        }
                    }
                }
            }
            //player 1 is the winner
            else if(comp == 1){
                p1_win_rate++;
                last_turn += _p1.getName() + " Wins.";
                _p1.setTakenCards(card_a);
                _p1.setTakenCards(card_b);
                _p1.setPlayerDeck(p1_vec);
                } 
            //player 2 is the winner
            else if(comp == 2){
                p2_win_rate++;
                last_turn += _p2.getName() + " Wins.";
                _p2.setTakenCards(card_a);
                _p2.setTakenCards(card_b);
                _p2.setPlayerDeck(p2_vec);
                }
            log += last_turn + "\n";
        }
        else{
            throw runtime_error("Can't run. Game Over.");
        }
    }

// this function play all the turns until the cards are done
    void Game::playAll(){
        while(_p1.stacksize() > 0 && _p2.stacksize() > 0){
            Game::playTurn();
        }
    }

// this function print the winner
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

//this function print all the turn of the game
    void Game::printLog(){
        std::cout << log << endl;
    }

// this function print all the statistics about the game.
    void Game::printStats(){
        // calculate the statistics
        double p1_wr = (double)p1_win_rate/turn_num;
        double p2_wr = (double)p2_win_rate/turn_num;
        double draw_rate = (double)draw_num/turn_num;
        // print all the statistics
        std::cout << _p1.getName() << "'s statistics:\n\twin rate:" <<  p1_wr << "\n\tcards won: " << _p1.cardesTaken() << endl; 
        std::cout << _p2.getName() << "'s statistics:\n\twin rate:" <<  p2_wr << "\n\tcards won: " << _p2.cardesTaken() << endl;
        std::cout << "\nGeneral statistics:\n\tDraw rate: " << draw_rate << "\n\tDraw amount: " << draw_num << endl;
    }
}