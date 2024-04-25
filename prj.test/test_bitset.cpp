#include <bitset/bitset.hpp>


int main() {


	BitSet a(2);
	a.Set(31, true);
	std::cout << a.Get(31);
	a.Set(31, false);
	std::cout << a.Get(31);

	a[31] = true;
	std::cout << a.Get(31);
}