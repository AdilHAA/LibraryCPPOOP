#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>
#include <iostream>


TEST_CASE("FUNCTIONS") {
	QueueLstPr a;
	CHECK(a.IsEmpty() == true);
	a.Push(4);
	CHECK(a.IsEmpty() == false);
	CHECK(a.Top() == doctest::Approx(4));
	a.Pop();
	CHECK(a.IsEmpty() == true);
	a.Push(1);
	a.Push(2);
	a.Push(3);
	a.Push(5);
	CHECK(a.Top() == doctest::Approx(1));
	a.Pop();
	CHECK(a.Top() == doctest::Approx(2));
	QueueLstPr b;
	b.Push(5);
	a = b; 
	CHECK(a.Top() == doctest::Approx(5));


}