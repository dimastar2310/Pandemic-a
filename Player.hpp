#pragma once
#include "Board.hpp"

namespace pandemic{

    class Player{
    protected:
        Board _b;
        City _c;
        std::string _role;
        std::unordered_set<City> cards;
    public:
        Player(Board b, City c, std::string role):_b(b),_c(c),_role(role){}
        virtual Player&  drive(City c);
            
        virtual Player& fly_direct(City c);
            
        
        virtual Player& fly_charter(City c);
            
        virtual Player&  fly_shuttle(City c);
            
        virtual Player& build();

        virtual Player& discover_cure(Color c);

        virtual Player& treat(City c);

        virtual std::string role();

        virtual Player& take_card(City c);

    };

}