#include "Transfer.h"

void test_function() {
	int* p1 = new int(10);
	std::cout << p1 << std::endl;
	int* p2 = new int[10];
	std::cout << p2 << std::endl;
	std::cout << *(p2 - 4) / sizeof(int) << std::endl;
	std::cout << _msize(p2) / sizeof(int) << std::endl;
	delete p1;
	delete [] p2;
}