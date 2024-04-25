#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <sstream>
#include <complex/complex.hpp>
#include "doctest.h"


TEST_CASE("Test operators") {
	Complex a(12, 6);
	Complex b(3, 2);
	Complex c(15, 8);
	Complex d(9, 4);
	Complex e(24, 42);
	CHECK((a+b) == c);
	CHECK(a - b == d);
	CHECK(a != b);
	CHECK(a * b == e);
	
}


