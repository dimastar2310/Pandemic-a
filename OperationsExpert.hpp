#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
    class OperationsExpert : public Player {
    public:
        OperationsExpert(Board b, City c) : Player(b, c, "OperationsExpert") {}

        OperationsExpert& build();
    };
}