#include "../include/old.h"
#include <cmath>
#include <vector>
#include <iostream>

/*
Linalg::vector_space
public functions:
*/

Linalg::Field Linalg::vector_space::get_field() {
	return field;
}

void Linalg::vector_space::show() {
	std::cout << ((field == 0)? "R" : "C") << "^" << n << "\n";
}

int Linalg::vector_space::dimension() {
	return n;
}

/*
Linalg::vector
public functions:
*/

std::vector<int> Linalg::vector::get_vector() {
	return elements;
}

float Linalg::vector::norm(int p) {
	float sump = 0;
	for (int elem : elements) {
		sump += (float)pow(elem, p);
	}
	sump = pow(sump, 1.0f / p);
	return sump;
}

void Linalg::vector::show() {
	std::cout << "[ ";
	for (int i = 0; i < dimension(); i++) {
		if (i == dimension() - 1) std::cout << elements[i] << " ";
		else std::cout << elements[i] << ", ";
	}
	std::cout << "] in ";
	V.show();
	std::cout << "\n";
}
int Linalg::vector::dimension() {
	//return elements.size();
	return V.dimension();
}
int Linalg::vector::index(int i) {
	return elements[i];
}

void Linalg::vector::modify(int index, int value) {
	elements[index] = value;
}

/*
Operations on Linalg::vector:
*/

int Linalg::dot(Linalg::vector v, Linalg::vector u) {
	int dotprod = 0;
	for (int i = 0; i < v.dimension(); i++) {
		dotprod += v.index(i) * u.index(i);
	}
	return dotprod;
}

float Linalg::metric(Linalg::vector v, Linalg::vector u) {
	Linalg::vector x(v);
	for (int i = 0; i < v.dimension(); i++) {
		int sum = v.index(i) - u.index(i);
		x.modify(i, sum);
	}
	return x.norm(2);
}

Linalg::vector Linalg::vector_add(Linalg::vector v, Linalg::vector u) {
	Linalg::vector x(v);
	for (int i = 0; i < v.dimension(); i++) {
		int sum = v.index(i) + u.index(i);
		x.modify(i, sum);
	}
	return x;
}

Linalg::vector Linalg::operator+(Linalg::vector v, Linalg::vector u) {
	Linalg::vector x = v;
	for (int i = 0; i < v.dimension(); i++) {
		int val = v.index(i) + u.index(i);
		x.modify(i, val);
	}
	return x;
}

Linalg::vector& Linalg::vector::operator=(Linalg::vector other) {
	for (int elem : other.elements) {
		this->elements.push_back(elem);
	}
	return *this;
}

Linalg::vector Linalg::scalar_mult(int a, Linalg::vector v) {
	Linalg::vector x(v);
	for (int i = 0; i < v.dimension(); i++) {
		int mult = a*v.index(i);
		x.modify(i, mult);
	}
	return x;
}

//Linalg::vector scalar_mult(double a, double b, Linalg::vector v);

//

double factorial(int n) {
	int fact = 1;
	for (int i = n; i>0; i--) {
		fact *= i;
	}
	return fact;
}

double Linalg::cos(float x, int M) {

	double approx = 0;
	for (int i = 0; i < M; i++) {
		approx += (pow(-1, i) * pow(x, 2 * i)) / (factorial(2*i));
	}
	return approx;
}

//

/*
Linalg::matrix
public functions:
*/

std::vector<std::vector<int> > Linalg::matrix::get_matrix() {
	return elements;
}

void Linalg::matrix::show() {
	std::cout << "[\n";
	for (int i = 0; i < Y.dimension(); i++) {
		std::cout << "[";
		for (int j = 0; j < X.dimension(); j++) {
			if (j == X.dimension() - 1) std::cout << elements[i][j] << "";
			else std::cout << elements[i][j] << ",";
			//std::cout << elements[i][j];
		}
		std::cout << " ],\n";
	}
	std::cout << "] \nin " << Y.dimension() << "x" << X.dimension() << "\n";
	std::cout << "\n";
}

int Linalg::matrix::dimension_X() {
	return X.dimension();
}

int Linalg::matrix::dimension_Y() {
	return Y.dimension();
}

Linalg::vector_space Linalg::matrix::get_X() {
	return X;
}

Linalg::vector_space Linalg::matrix::get_Y() {
	return Y;
}
/*
Linalg::matrix Linalg::transpose(Linalg::matrix T) {

}
*/

Linalg::vector Linalg::vector_transform(Linalg::vector v, Linalg::matrix T) {
	Linalg::vector columns(T.get_Y());
	for (int i = 0; i < T.dimension_Y(); i++) {
		Linalg::vector temp(T.get_X(), T.get_matrix().at(i));
		columns.modify(i, Linalg::dot(v, temp));
	}
	return columns;
}

Linalg::matrix matrix_transform(Linalg::matrix T, Linalg::matrix F);

/*
Linalg::vector cross(Linalg::vector a, Linalg::vector b) {
}
*/

/*
Linalg::tensor
public functions:
*/



/*
Operations on Linalg::tensor:
*/
