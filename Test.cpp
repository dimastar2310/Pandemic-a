#include "doctest.h"
#include "Board.hpp" 
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE("Dispatcher"){
    Board board;
    Dispatcher dispatcher{board, City::Chicago};
    CHECK_THROWS(dispatcher.fly_direct(City::Lagos));
    dispatcher.take_card(City::Chicago);
    CHECK_NOTHROW(dispatcher.build());
    CHECK_NOTHROW(dispatcher.fly_direct(City::Lagos));
    dispatcher.take_card(City::Cairo);
    CHECK_THROWS(dispatcher.drive(City::Cairo));
    dispatcher.take_card(City::SaoPaulo);
    CHECK_NOTHROW(dispatcher.drive(City::SaoPaulo));
}

TEST_CASE("FieldDoctor"){
    Board board;
    FieldDoctor doc{board,City::Tokyo};
    board[City::Shanghai] = 3;
    board[City::SanFrancisco] = 1;
    CHECK_THROWS(doc.treat(City::SanFrancisco));
    CHECK_NOTHROW(doc.treat(City::Shanghai));
    CHECK(board[City::Shanghai] == 2);
    doc.take_card(City::Sydney)
    .take_card(City::Jakarta)
    .take_card(City::HongKong)
    .take_card(City::Taipei)
    .take_card(City::Shanghai);
    CHECK_THROWS(doc.discover_cure (Color::Blue));
    CHECK_THROWS(doc.discover_cure (Color::Red));
    CHECK_NOTHROW(doc.build());
    CHECK_THROWS(doc.discover_cure (Color::Red));
    doc.take_card(City::Shanghai);
    CHECK_NOTHROW(doc.discover_cure (Color::Red));
}

TEST_CASE("GeneSplicer"){
    Board board;
    GeneSplicer g{board,City::Moscow};
    g.take_card(City::NewYork)
    .take_card(City::Jakarta)
    .take_card(City::Paris)
    .take_card(City::Baghdad)
    .take_card(City::Shanghai)
    .take_card(City::Moscow);
    CHECK_THROWS(g.discover_cure(Color::Black));
    CHECK_NOTHROW(g.build());
    CHECK_NOTHROW(g.discover_cure(Color::Black));
}

TEST_CASE("Medic"){
    Board board;
    Medic m{board,City::Santiago};
    board[City::Santiago] = 5;
    CHECK(board[City::Santiago]==0);
    CHECK_NOTHROW(m.treat(City::Santiago));
    CHECK(board[City::Santiago]==0);
    m.take_card(City::Sydney)
    .take_card(City::Jakarta)
    .take_card(City::HongKong)
    .take_card(City::Taipei)
    .take_card(City::Shanghai);
    CHECK_THROWS(m.discover_cure(Color::Yellow));
    CHECK_NOTHROW(m.discover_cure(Color::Red));
    board[City::HongKong] = 5;
    m.take_card(City::Santiago);
    CHECK_NOTHROW(m.fly_charter(City::HongKong));
    CHECK(board[City::HongKong]==0);
}

TEST_CASE("OperationsExpert"){
    Board b;
    OperationsExpert exp{b,City::Istanbul};
    CHECK_NOTHROW(exp.build());
    exp.take_card(City::Karachi);
    CHECK_NOTHROW(exp.fly_direct(City::Karachi));
    CHECK_NOTHROW(exp.build());
    CHECK_NOTHROW(exp.fly_shuttle(City::Istanbul));
}

TEST_CASE("Reasercher"){
    Board b;
    Researcher r{b,City::LosAngeles};
    r.take_card(City::LosAngeles)
    .take_card(City::Miami)
    .take_card(City::MexicoCity)
    .take_card(City::Santiago)
    .take_card(City::Bogota);
    CHECK_NOTHROW(r.discover_cure(Color::Yellow));
    CHECK(r.role() == "Reasercher");
}

TEST_CASE("Scientist"){
    Board b;
    Scientist s{b,City::Madrid, 3};
    s.take_card(City::Madrid)
    .take_card(City::London)
    .take_card(City::Paris);
    CHECK_NOTHROW(s.discover_cure(Color::Yellow));
}

TEST_CASE("Virologist"){
    Board b;
    Virologist v{b,City::Paris};
    b[City::Moscow] = 3;
    CHECK_THROWS(v.treat(City::Moscow));
    v.take_card(City::Moscow);
    CHECK_NOTHROW(v.treat(City::Moscow));
    CHECK(b[City::Moscow] == 2);

}