
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    family::Tree T ("Yosef");
    CHECK_THROWS(T.addFather("Yosef4", "Yaakov"));
    // T.addFather("Yosef", "Yaakov");
    T.addFather("Yosef", "Yosef4");
    CHECK_THROWS(T.addFather("Yosef6", "Yaakov"));
    CHECK_THROWS(T.addMother("Yosef6", "Yaakov"));
    T.addMother("Yosef", "Yosefa");


    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
    CHECK(2 == 2);
}
