#include "../DirectedWeightedGraph.cpp"
#include "catch.hpp"

TEST_CASE( "Testing Read Graph", "[ReadGraph]" ) {
    DirectedWeightedGraph testGraph("testInput.txt");
    pair<int, int> *size = testGraph.size();

    REQUIRE(size->first == 4);
    REQUIRE(size->first == size->second);
}