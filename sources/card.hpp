#ifndef CARD_HPP
#define CARD_HPP
#include <vector>
#include <string>

namespace ariel{
    enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    enum class Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
    
    class Card{
    // private:
        // enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    public:
    // enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
        struct card {
            Rank rank;
            Suit suit;
        };
        struct Deck{
            std::vector<card> cards;
        };
        //getters and setters
        void setRank();
        void setSuit();
        int getRank(const card&);
        std::string getRankString(const card&);
        std::string getSuitString(const card&);

        //functions
        const int rankSize = 13;
        const int suitSize = 4;
        int stacksize();
        int cardesTaken();
        void initialShuffeledDeck(Deck&, std::vector<card>&, std::vector<card>&);
        int compareCards(card, card );
        void printDeck(const Deck&);
        void printCard( card&);
    };
}
#endif