/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main() {
  // Create two players with their names 
  Player p1("Alice");
  Player p2("Bob");

  Game game(p1,p2); 
  for (int i=0;i<5;i++) {
   game.playTurn();
  }
  game.printLastTurn(); // print the last turn stats. For example:
                                                   // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                   // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
  cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
  cout << p1.cardesTaken() << endl;
  cout << p2.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
  cout << p2.cardesTaken() << endl; // prints the amount of cards this player has won. 
  game.playAll(); //playes the game untill the end
  game.printWiner(); // prints the name of the winning player
  game.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  game.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

  cout << "+++++++++++++++++++++++++++++++++++" << endl;

  Player p3("Meitar");
  Player p4("Yuval");

  Game game1(p3,p4); 
  game1.playAll(); //playes the game untill the end
  // game1.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  game1.printStats();
  
  cout << "+++++++++++++++++++++++++++++++++++" << endl;

  Player p5("Bar");
  Player p6("Maoz");

  Game game2(p5,p6); 
  game2.playAll(); //playes the game untill the end
  // game2.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  game2.printStats();

  cout << "+++++++++++++++++++++++++++++++++++" << endl;

  Player p7("Ricky");
  Player p8("Eric");

  Game game3(p7,p8); 
  game3.playAll(); //playes the game untill the end
  // game3.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  game3.printStats();

  cout << "+++++++++++++++++++++++++++++++++++" << endl;

  Player p9("Donna");
  Player p10("Hide");

  Game game4(p9,p10); 
  game4.playAll(); //playes the game untill the end
  // game4.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  game4.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )


}