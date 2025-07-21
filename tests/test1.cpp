#include <iostream>
#include "../include/old.h"

int main() {
	std::cout << "-------test1.cpp-------\n\n\n";
	visualize::vector_space V(visualize::R, 5);
	V.show();
	visualize::vector_space U(V);
	U.show();

	visualize::vector_space W(visualize::R, 3);
	W.show();

	visualize::vector owo(W, { 1,2,3 });


	visualize::vector uwu(W, { 2,6,2 });
	visualize::vector awa = visualize::vector_add(owo, uwu);
	visualize::vector awa2 = owo + uwu;
	visualize::vector ewe(owo);
	std::cout << "owo: "; owo.show();
	std::cout << "uwu: "; uwu.show();
	std::cout << "awa: "; awa.show();
	std::cout << "awa2: "; awa2.show();
	std::cout << "ewe: "; ewe.show();
	int p = 3;
	std::cout << p << "-norm of owo: " << owo.norm(p) << std::endl;
	int i = uwu.index(1);
	std::cout << "uwu value at " << i << "\n";
	std::cout << "dot product of owo and uwu: " << visualize::dot(owo, uwu) << std::endl;
	float g = visualize::metric(owo, uwu);
	std::cout << "distance between owo and uwu (using l2-norm): " << visualize::metric(owo, uwu) << std::endl;
	float cosine = visualize::cos(80, 7);
	std::cout << "cos(3.6): " << cosine << "\n";

	visualize::matrix T(V, W, { {1,2,3,7,6},
							   {0,0,0,1,1},
							   {5,5,3,2,10} } );
	T.show();

	visualize::vector v(V, { 1,2,-3,9,8 });
	std::cout << "v: "; v.show();
	visualize::vector va = visualize::scalar_mult(3, v);
	std::cout << "va: "; va.show();
	visualize::vector Tv = visualize::vector_transform(v, T);
	std::cout << "Tv: "; Tv.show();

	//visualize::vector aaa = { 1,2,3,7,7,10 };
	//aaa.show();
}
