
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;


TEST_CASE("Test addMother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test addFather") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test throw when child not exist on addFather") {
    family::Tree T ("a");
    CHECK_THROWS(T.addFather("b", "c"));
    // T.addFather("Yosef", "Yaakov");
    T.addFather("a", "af");
    CHECK_THROWS(T.addFather("aff", "a"));
}

TEST_CASE("Test throw when child not exist on addMother") {
    family::Tree T ("a");
    CHECK_THROWS(T.addMother("b", "c"));
    // T.addFather("Yosef", "Yaakov");
    T.addMother("a", "am");
    CHECK_THROWS(T.addMother("amm", "a"));
}

TEST_CASE("Test add mother Mother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        CHECK(true);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test add father Mother") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addMother("af", "afm");
        CHECK(true);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test add mother father") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addFather("am", "amf");
        CHECK(true);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test add father father") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addFather("af", "aff");
        CHECK(true);
	} catch (exception ex) {
        CHECK(false);
	}
}


TEST_CASE("Test display") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.display();
        CHECK(true);
	} catch (exception ex) {
        CHECK(false);
	}
}








TEST_CASE("Test remove father") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addFather("af", "aff");
        CHECK(T.father.size() == 3);
        T.remove("aff");
        CHECK(T.father.size() == 2);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test remove father") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addFather("af", "aff");
        CHECK(T.father.size() == 3);
        T.remove("af");
        CHECK(T.father.size() == 1);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test remove mother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        CHECK(T.mother.size() == 2);
        T.remove("am");
        CHECK(T.mother.size() == 0);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test remove mother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        CHECK(T.mother.size() == 2);
        T.remove("amm");
        CHECK(T.mother.size() == 1);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test remove mixed") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addFather("am", "amf");
        CHECK(T.father.size() == 2);
        CHECK(T.mother.size() == 1);
        T.remove("amf");
        CHECK(T.father.size() == 1);
        CHECK(T.mother.size() == 1);
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test remove mixed") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addMother("af", "afm");
        CHECK(T.father.size() == 2);
        CHECK(T.mother.size() == 1);
        T.remove("afm");
        CHECK(T.father.size() == 2);
        CHECK(T.mother.size() == 0);
	} catch (exception ex) {
        CHECK(false);
	}
}


TEST_CASE("Test find father") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        CHECK(T.relation("af")=="father");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find father") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addFather("af", "aff");
        CHECK(T.relation("aff")=="grandfather");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find grandfather") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addFather("af", "aff");
        CHECK(T.relation("aff")=="grandfather");
        T.addMother("a", "am");
        T.addFather("am", "amf");
        CHECK(T.relation("amf")=="grandfather");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find mother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        CHECK(T.relation("amm")=="grandmother");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find grandmother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        CHECK(T.relation("amm")=="grandmother");
        T.addFather("a", "af");
        T.addMother("af", "afm");
        CHECK(T.relation("afm")=="grandmother");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find not exists") {
    family::Tree T ("a");
    try {
        CHECK(T.relation("am")=="unrelated");
        CHECK(T.relation("afm")=="unrelated");
        CHECK(T.relation("af")=="unrelated");
        CHECK(T.relation("fa")=="unrelated");
        CHECK(T.relation("amdgsfggf")=="unrelated");
        CHECK(T.relation("agsgvmf")=="unrelated");
        CHECK(T.relation("a32refmf")=="unrelated");
        CHECK(T.relation("a13mf")=="unrelated");
        CHECK(T.relation("asdadmf")=="unrelated");
        CHECK(T.relation("xc")=="unrelated");
        CHECK(T.relation("jrgh")=="unrelated");
        CHECK(T.relation("awerf")=="unrelated");
        CHECK(T.relation("zxvzxf")=="unrelated");
        CHECK(T.relation("nhtjhdf")=="unrelated");
        CHECK(T.relation("arfgvda")=="unrelated");
        CHECK(T.relation("aqwdsmf")=="unrelated");
        CHECK(T.relation("ghetamf")=="unrelated");
        CHECK(T.relation("iykujhf")=="unrelated");
        CHECK(T.relation("asfd")=="unrelated");
        CHECK(T.relation("jhasdiyas")=="unrelated");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find great-great") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        T.addMother("amm", "ammm");
        T.addMother("ammm", "ammmm");
        T.addMother("ammmm", "ammmmm");
        T.addMother("ammmmm", "ammmmmm");
        T.addMother("ammmmmm", "ammmmmmm");
        T.addMother("ammmmmmm", "ammmmmmmm");
        T.addMother("ammmmmmmm", "ammmmmmmmm");

        CHECK(T.relation("ammm")=="great-grandmother");
        CHECK(T.relation("ammmm")=="great-great-grandmother");
        CHECK(T.relation("ammmmm")=="great-great-great-grandmother");
        CHECK(T.relation("ammmmmm")=="great-great-great-great-grandmother");
        CHECK(T.relation("ammmmmmm")=="great-great-great-great-great-grandmother");
        CHECK(T.relation("ammmmmmmm")=="great-great-great-great-great-great-grandmother");
        CHECK(T.relation("ammmmmmmmm")=="great-great-great-great-great-great-great-grandmother");
        T.addFather("a", "af");
        T.addFather("af", "aff");
        T.addFather("aff", "afff");
        T.addFather("afff", "affff");
        T.addFather("affff", "afffff");
        T.addFather("afffff", "affffff");
        T.addFather("affffff", "afffffff");
        T.addFather("afffffff", "affffffff");
        T.addFather("affffffff", "afffffffff");
        CHECK(T.relation("afff")=="great-grandfather");
        CHECK(T.relation("affff")=="great-great-grandfather");
        CHECK(T.relation("afffff")=="great-great-great-grandfather");
        CHECK(T.relation("affffff")=="great-great-great-great-grandfather");
        CHECK(T.relation("afffffff")=="great-great-great-great-great-grandfather");
        CHECK(T.relation("affffffff")=="great-great-great-great-great-great-grandfather");
        CHECK(T.relation("afffffffff")=="great-great-great-great-great-great-great-grandfather");
	} catch (exception ex) {
        CHECK(false);
	}
}











TEST_CASE("Test find father") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        CHECK(T.find("father")=="af");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find father") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addFather("af", "aff");
        CHECK(T.find("grandfather")=="aff");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find grandfather") {
    family::Tree T ("a");
    try {
        T.addFather("a", "af");
        T.addFather("af", "aff");
        CHECK(T.find("grandfather")=="aff");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find grandfather") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addFather("am", "amf");
        CHECK(T.find("grandfather")=="amf");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find mother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        CHECK(T.find("grandmother")=="amm");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find grandmother") {
    family::Tree T ("a");
    try {
        T.addMother("a", "am");
        T.addMother("am", "amm");
        CHECK(T.find("grandmother")=="amm");
        T.addFather("a", "af");
        T.addMother("af", "afm");
        CHECK(T.find("grandmother")=="afm");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find great-great") {
    family::Tree T ("a");
    try {
        CHECK(T.find("great-grandmother")=="unrelated");
        CHECK(T.find("great-great-grandmother")=="unrelated");
        CHECK(T.find("great-great-great-grandmother")=="unrelated");
        CHECK(T.find("great-great-great-great-grandmother")=="unrelated");
        CHECK(T.find("great-great-great-great-great-grandmother")=="unrelated");
        CHECK(T.find("great-great-great-great-great-great-grandmother")=="unrelated");
        CHECK(T.find("great-great-great-great-great-great-great-grandmother")=="unrelated");

        T.addMother("a", "am");
        T.addMother("am", "amm");
        T.addMother("amm", "ammm");
        T.addMother("ammm", "ammmm");
        T.addMother("ammmm", "ammmmm");
        T.addMother("ammmmm", "ammmmmm");
        T.addMother("ammmmmm", "ammmmmmm");
        T.addMother("ammmmmmm", "ammmmmmmm");
        T.addMother("ammmmmmmm", "ammmmmmmmm");

        CHECK(T.find("great-grandmother")=="ammm");
        CHECK(T.find("great-great-grandmother")=="ammmm");
        CHECK(T.find("great-great-great-grandmother")=="ammmmm");
        CHECK(T.find("great-great-great-great-grandmother")=="ammmmmm");
        CHECK(T.find("great-great-great-great-great-grandmother")=="ammmmmmm");
        CHECK(T.find("great-great-great-great-great-great-grandmother")=="ammmmmmmm");
        CHECK(T.find("great-great-great-great-great-great-great-grandmother")=="ammmmmmmmm");

        CHECK(T.find("great-grandfather")=="unrelated");
        CHECK(T.find("great-great-grandfather")=="unrelated");
        CHECK(T.find("great-great-great-grandfather")=="unrelated");
        CHECK(T.find("great-great-great-great-grandfather")=="unrelated");
        CHECK(T.find("great-great-great-great-great-grandfather")=="unrelated");
        CHECK(T.find("great-great-great-great-great-great-grandfather")=="unrelated");
        CHECK(T.find("great-great-great-great-great-great-great-grandfather")=="unrelated");


        T.addFather("a", "af");
        T.addFather("af", "aff");
        T.addFather("aff", "afff");
        T.addFather("afff", "affff");
        T.addFather("affff", "afffff");
        T.addFather("afffff", "affffff");
        T.addFather("affffff", "afffffff");
        T.addFather("afffffff", "affffffff");
        T.addFather("affffffff", "afffffffff");
        CHECK(T.find("great-grandfather")=="afff");
        CHECK(T.find("great-great-grandfather")=="affff");
        CHECK(T.find("great-great-great-grandfather")=="afffff");
        CHECK(T.find("great-great-great-great-grandfather")=="affffff");
        CHECK(T.find("great-great-great-great-great-grandfather")=="afffffff");
        CHECK(T.find("great-great-great-great-great-great-grandfather")=="affffffff");
        CHECK(T.find("great-great-great-great-great-great-great-grandfather")=="afffffffff");
	} catch (exception ex) {
        CHECK(false);
	}
}

TEST_CASE("Test find me") {
    family::Tree T ("a");
    try {
        CHECK(T.relation("a")=="me");
	} catch (exception ex) {
        CHECK(false);
	}
}
