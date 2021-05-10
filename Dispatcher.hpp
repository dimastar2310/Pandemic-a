#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
    class Dispatcher : public Player {
    public:
        Dispatcher(Board b, City c) : Player(b, c, "Dispatcher") {}

        Dispatcher& fly_direct(City c);
    };
}