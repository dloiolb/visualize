// #include <iostream>
#include "../include/tensor.h"

int main() {
	std::cout << "-------test2.cpp-------\n\n\n";

	Linalg::tensor L({1,2,3,4,5,6}, {2,3});
	int opa = L({1,0});
	std::cout << "OPAOPAOPAO: " << opa << std::endl;
}
