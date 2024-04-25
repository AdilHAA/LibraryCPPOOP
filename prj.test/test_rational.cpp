#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <rational/rational.hpp>

TEST_CASE("Test bool operator") {
    Rational a(12);
    Rational b(6);
    CHECK(a > b);
    CHECK(a != b);
    CHECK(a >= b);

}
TEST_CASE("Test operator +-*/") {
    Rational a(12);
    Rational b(6);
    Rational c;
    c = a + b;
    CHECK(c == 18);
    c = a - b;
    CHECK(c == 6);
    c = a * b;
    CHECK(c == 72);
    c = a / b;
    CHECK(c == 2);
}
TEST_CASE("Test constructor") {
    Rational a(18, 3);
    CHECK(a == 6);
    Rational b(12);
    CHECK(b == 12);
}