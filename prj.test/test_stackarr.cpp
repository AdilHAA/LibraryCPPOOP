#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stackarr/stackarr.hpp>
#include<complex/complex.hpp>



TEST_CASE("Stack_on_array") {
	StackArr a(Complex(7));
	CHECK(a.Top() == Complex(7));
	a.Push(Complex(5));
	a.Push(Complex(3));
	CHECK(a.Top() == Complex(3));
	a.Pop();
	CHECK(a.Top() == Complex(5));
}