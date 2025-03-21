#include <iostream>
#include "../include/Linalg.h"

int main() {
	Linalg::vector_space V(Linalg::R, 5);
	V.show();
	Linalg::vector_space U(V);
	U.show();

	Linalg::vector_space W(Linalg::R, 3);
	W.show();

	Linalg::vector owo(W, { 1,2,3 });


	Linalg::vector uwu(W, { 2,6,2 });
	Linalg::vector awa = Linalg::vector_add(owo, uwu);
	Linalg::vector awa2 = owo + uwu;
	Linalg::vector ewe(owo);
	std::cout << "owo: "; owo.show();
	std::cout << "uwu: "; uwu.show();
	std::cout << "awa: "; awa.show();
	std::cout << "awa2: "; awa2.show();
	std::cout << "ewe: "; ewe.show();
	int p = 3;
	std::cout << p << "-norm of owo: " << owo.norm(p) << std::endl;
	int i = uwu.index(1);
	std::cout << "uwu value at " << i << "\n";
	std::cout << "dot product of owo and uwu: " << Linalg::dot(owo, uwu) << std::endl;
	float g = Linalg::metric(owo, uwu);
	std::cout << "distance between owo and uwu (using l2-norm): " << Linalg::metric(owo, uwu) << std::endl;
	float cosine = Linalg::cos(80, 7);
	std::cout << "cos(3.6): " << cosine << "\n";

	Linalg::matrix T(V, W, { {1,2,3,7,6},
							   {0,0,0,1,1},
							   {5,5,3,2,10} } );
	T.show();

	Linalg::vector v(V, { 1,2,-3,9,8 });
	std::cout << "v: "; v.show();
	Linalg::vector va = Linalg::scalar_mult(3, v);
	std::cout << "va: "; va.show();
	Linalg::vector Tv = Linalg::vector_transform(v, T);
	std::cout << "Tv: "; Tv.show();

	//Linalg::vector aaa = { 1,2,3,7,7,10 };
	//aaa.show();
}
