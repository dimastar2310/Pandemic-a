#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
    class Scientist : public Player {
    private:
        unsigned int num_of_cards_to_discover;
    public:
        Scientist(Board b, City c, unsigned int num) : Player(b, c, "Scientist"), num_of_cards_to_discover(num) {}

        Scientist &discover_cure(Color c);
    };
}