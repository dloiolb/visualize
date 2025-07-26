// #include <iostream>
#include "../include/tensor.h"

int main() {
	std::cout << "-------test2.cpp-------\n\n\n";

	visualize::tensor L({1,2,3,4,5,6}, {2,3});
	int opa = L({1,0});
	std::cout << "OPAOPAOPAO: " << opa << std::endl;
	L.show();
	std::cout << norm_p(L,3) << std::endl;
	visualize::tensor T({1,2,3,4}, {4});
	visualize::tensor J({7,7,7,7}, {4});
	T.show();
	double j = norm_p(T,2);
	std::cout << j << std::endl;
	j = norm_sup(T);
	std::cout << j << std::endl;
	visualize::tensor M = visualize::hadamard(T,J);
	M.show();
	visualize::tensor N = T%J;
	N.show();
}
