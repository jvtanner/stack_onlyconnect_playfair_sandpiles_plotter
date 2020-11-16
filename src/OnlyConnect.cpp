/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Try to solve: FTHTGR
 */
#include "OnlyConnect.h"
#include "Testing/OnlyConnectTests.h"
#include "strlib.h"

using namespace std;



//ONLY
string consonant(char character);

string onlyConnectize(string phrase){
    string connectize = "";
    if (phrase == ""){
        return "";
    } else {
        connectize += consonant(phrase[0]) +
                onlyConnectize(phrase.substr(1));
    }
    return connectize;
}

string consonant(char character) {
    character = toUpperCase(character);
    if (isalpha(character) && !(character == 'A' ||
                character == 'E' || character == 'I' ||
                character == 'O' || character == 'U' ||
                character == 'Y')){
        return charToString(character);
    } else {
        return "";
    }
}



/* * * * * * Test Cases * * * * * */

ADD_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

ADD_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

ADD_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

ADD_TEST("Handles the empty string") {
    EXPECT_EQUAL(onlyConnectize(""), "");
}

ADD_TEST("Handles multiple spaces") {
    EXPECT_EQUAL(onlyConnectize("H      H"), "HH");
    EXPECT_EQUAL(onlyConnectize(" q q q e q "), "QQQQ");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */






