#include "Board.hpp"
using namespace pandemic;
using namespace std;


int& Board::operator[](City c){
    return disease_rate[c];
}

bool Board::is_clean(){
    for(auto& pair : disease_rate){
        if(pair.second > 0){
            return false;
        }
    }
    return true;
}

void Board::remove_cures(){

}

ostream& pandemic::operator<<(ostream& out, const Board& b){
    out<<" "<<endl;
    return out;
}