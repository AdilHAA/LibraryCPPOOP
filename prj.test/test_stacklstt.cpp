#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklstt/stacklstt.hpp>
#include <string>
#include <vector>




TEST_CASE("TEMP") {
	StackLstT<int> A;
	A.Push(5);
	CHECK(A.Top() == 5);
	A.Pop();
	CHECK(A.IsEmpty());
	StackLstT<float> B;
	B.Push(5);
	CHECK(B.Top() == doctest::Approx(5));
	B.Pop();
	CHECK(B.IsEmpty());
	StackLstT<std::string> C;
	C.Push("first string");
	C.Push("second string");
	C.Push("third string");
	CHECK(C.Top() == "third string");
	C.Pop();
	CHECK(C.Top() == "second string");
	C.Pop();
	CHECK(C.Top() == "first string");
}



