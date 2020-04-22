/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 * 
 * Date: 2020-02
 */


#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;




TEST_CASE("Test replacement of p, f and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    
    text = "xxx habby yyy";
    CHECK(find(text, "haffy") == string("habby"));
    CHECK(find(text, "habfy") == string("habby"));
    CHECK(find(text, "hafby") == string("habby"));
    CHECK(find(text, "hafpy") == string("habby"));
    CHECK(find(text, "happy") == string("habby"));



    /* Add more checks here */
}

TEST_CASE("Test letters v, w"){
    string text = "ww avvb kwwj vrought bov";
    CHECK(find(text, "vv") == string("ww"));
    CHECK(find(text, "awwb") == string("avvb"));
    CHECK(find(text, "wrought") == string("vrought"));
    CHECK(find(text, "bow") == string("bov"));
    CHECK(find(text, "kvvj") == string("kwwj"));
}
TEST_CASE("Test letters g, j"){
    string text = "gj bejjar gym aaa";
    CHECK(find(text, "jj") == string("gj"));
    CHECK(find(text, "beggar") == string("bejjar"));
    CHECK(find(text, "bejgar") == string("bejjar"));
    CHECK(find(text, "jym") == string("gym"));
    CHECK(find(text, "gym") == string("gym"));
    CHECK(find(text, "begjar") == string("bejjar"));
}

TEST_CASE("Test letters c, k and q"){
    string text = "AcK corn caKe question ckq ";
    CHECK(find(text, "AcK") == string("AcK"));
    CHECK(find(text, "AkK") == string("AcK"));
    CHECK(find(text, "akk") == string("AcK"));
    CHECK(find(text, "Korn") == string("corn"));
    CHECK(find(text, "kaqe") == string("caKe"));
    CHECK(find(text, "kuestion") == string("question"));
    CHECK(find(text, "ckc") == string("ckq"));
    CHECK(find(text, "ckk") == string("ckq"));
    CHECK(find(text, "kkk") == string("ckq"));
    CHECK(find(text, "ccc") == string("ckq"));
}

TEST_CASE("Test letters s, z"){
    string text = "Sam zapper zusein ssszzz";
    CHECK(find(text, "Sam") == string("Sam"));
    CHECK(find(text, "ZAM") == string("Sam"));
    CHECK(find(text, "sAppEr") == string("zapper"));
    CHECK(find(text, "susein") == string("zusein"));
    CHECK(find(text, "szszsz") == string("ssszzz"));
    CHECK(find(text, "szsssz") == string("ssszzz"));
    CHECK(find(text, "zzszsz") == string("ssszzz"));
}

TEST_CASE("Test letters d, t"){
    string text = "dude tremble dont dddttt DattT";
    CHECK(find(text, "dute") == string("dude"));
    CHECK(find(text, "dremble") == string("tremble"));
    CHECK(find(text, "tond") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "dTdtDt") == string("dddttt"));
    CHECK(find(text, "dtdttt") == string("dddttt"));
    CHECK(find(text, "tadtT") == string("DattT"));
}

TEST_CASE("Test letters o, u"){
    string text = "wow you ouch ooouuu";
    CHECK(find(text, "wuw") == string("wow"));
    CHECK(find(text, "yoo") == string("you"));
    CHECK(find(text, "uoch") == string("ouch"));
    CHECK(find(text, "ooch") == string("ouch"));
    CHECK(find(text, "ououou") == string("ooouuu"));
}

TEST_CASE("Test letters i, y"){
    string text = "yes interesting immediately iiiyyy";
    CHECK(find(text, "yes") == string("yes"));
    CHECK(find(text, "ies") == string("yes"));
    CHECK(find(text, "ynteresting") == string("interesting"));
    CHECK(find(text, "ymmediateli") == string("immediately"));
    CHECK(find(text, "yiyiyi") == string("iiiyyy"));
}


TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "xxX") == string("xxx"));
    CHECK(find(text, "YyY") == string("yyy"));
}

TEST_CASE("Test finding correct words") {
    string text = "hello how do you";
    CHECK(find(text, "hello") == string("hello"));
    CHECK(find(text, "how") == string("how"));
    CHECK(find(text, "do") == string("do"));
    CHECK(find(text, "you") == string("you"));
}
TEST_CASE("Test finding words that appear multiple times") {
    string text = "aa aa ff ff baby bafy";
    CHECK(find(text, "aa") == string("aa"));
    CHECK(find(text, "bb") == string("ff"));
    CHECK(find(text, "baby") == string("baby"));
    CHECK(find(text, "bafy") == string("baby"));
}
TEST_CASE("Test single letter text"){
    string text1 = "y";
    CHECK(find(text1, "y") == string("y"));
    CHECK(find(text1, "i") == string("y"));
}
TEST_CASE("Test single letter word"){
    string text1 = "y k m l";
    CHECK(find(text1, "y") == string("y"));
    CHECK(find(text1, "k") == string("k"));
    CHECK(find(text1, "m") == string("m"));
    CHECK(find(text1, "l") == string("l"));
}

TEST_CASE("Test exceptions for spaces in text"){
    string text1 = " y", text2 = "z ", text3 = " x ";
    CHECK_THROWS_AS(find(text1, " "), const exception&);
    CHECK(find(text1, "y") == string("y"));
    CHECK_THROWS_AS(find(text1, "y "), const exception&);
    CHECK(find(text2, "z") == string("z"));
    CHECK_THROWS_AS(find(text2, "z "), const exception&);
    CHECK(find(text3, "x") == string("x"));
    CHECK_THROWS_AS(find(text3, " x "), const exception&);
    CHECK_THROWS_AS(find(text3, " x"), const exception&);
    CHECK_THROWS_AS(find(text3, "x "), const exception&);
}
TEST_CASE("Test exceptions for invalid word input other than spaces"){
    string text = "what a wonderful day";
    CHECK_THROWS_AS(find(text, "#"), const exception&);
    CHECK_THROWS_AS(find(text, "what?"), const exception&);
    CHECK_THROWS_AS(find(text, "@#*&asdgf$@$#"), const exception&);
    CHECK_THROWS_AS(find(text, "2"), const exception&);
    CHECK_THROWS_AS(find(text, "2day"), const exception&);
}
TEST_CASE("Check bad text input"){
    string text1 = "", text2 = " ", text3 = "2", text4 = "%", text5 = "hel!o abby", text6 = "3jack apple";
    CHECK_THROWS_AS(find(text1, ""), const exception&);
    CHECK_THROWS_AS(find(text2, " "), const exception&);
    CHECK_THROWS_AS(find(text3, "2"), const exception&);
    CHECK_THROWS_AS(find(text4, "%"), const exception&);
    CHECK_THROWS_AS(find(text5, "abby"), const exception&);
    CHECK_THROWS_AS(find(text6, "apple"), const exception&);
}


TEST_CASE("Check words that shouldn't be found"){
    string text = "what a wonderful day";
    CHECK_THROWS_AS(find(text, "ghat"), const exception&);
    CHECK_THROWS_AS(find(text, "b"), const exception&);
    CHECK_THROWS_AS(find(text, "dty"), const exception&);
    CHECK_THROWS_AS(find(text, "wondewful"), const exception&);
    CHECK_THROWS_AS(find(text, "aa"), const exception&);
}

TEST_CASE("Check all letters together"){
    string text = "abcdefghijklmnopqrstuvwxyz";
    string textc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    CHECK(find(text, "abcdefghijklmnopqrstuvwxyz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text, "afktepjhygqlmnubcrzdowvxis") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(textc, "abcdefghijklmnopqrstuvwxyz") == string("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}

TEST_CASE("Check words similar to words that should be found"){
    string text = "avw wbfp lsGJkm myckqqq mszzsk odtm";
    CHECK_THROWS_AS(find(text, "wv"), const exception&);
    CHECK_THROWS_AS(find(text, "aw"), const exception&);
    CHECK_THROWS_AS(find(text, "wbffq"), const exception&);
    CHECK_THROWS_AS(find(text, "sGgkm"), const exception&);
    CHECK_THROWS_AS(find(text, "myck"), const exception&);
    CHECK_THROWS_AS(find(text, "msszss"), const exception&);
    CHECK_THROWS_AS(find(text, "odmm"), const exception&);
    CHECK_THROWS_AS(find(text, "odtm "), const exception&);
    CHECK_THROWS_AS(find(text, "odmm"), const exception&);
    CHECK_THROWS_AS(find(text, "lGGJkm"), const exception&);
    CHECK_THROWS_AS(find(text, "bvv"), const exception&);
    CHECK_THROWS_AS(find(text, "mykkmqq"), const exception&);
    CHECK_THROWS_AS(find(text, "slGJkm"), const exception&);
}

TEST_CASE("Ceck that spaces are not ignored"){
    string text = "jonny ate an apple m";
    CHECK_THROWS_AS(find(text, "jonnyate"), const exception&);
    CHECK_THROWS_AS(find(text, "jonnyade"), const exception&);
    CHECK_THROWS_AS(find(text, "atean"), const exception&);
    CHECK_THROWS_AS(find(text, "applem"), const exception&);
    CHECK_THROWS_AS(find(text, "jonnyateanapplem"), const exception&);
}