#pragma once
#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {

    class Researcher : public Player {
    public:
        Researcher(Board b, City c) : Player(b, c, "Researcher") {}

        Researcher &discover_cure(Color c);
    };
}