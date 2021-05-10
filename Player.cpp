#include "Player.hpp"
using namespace pandemic;
using namespace std;

Player& Player::drive(City c){
    return *this;
}

Player& Player::fly_direct(City c){
    return *this;
}

Player& Player::fly_charter(City c){
    return *this;
}

Player& Player::fly_shuttle(City c){
    return *this;
}

Player& Player::build(){
    return *this;
}

Player& Player::discover_cure(Color c){
    return *this;
}

Player& Player::treat(City c){
    return *this;
}

Player& Player::take_card(City c){
    return *this;
}

string Player::role(){
    return _role;
}