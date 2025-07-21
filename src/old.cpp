#include "../include/old.h"
#include <cmath>
#include <vector>
#include <iostream>

/*
visualize::vector_space
public functions:
*/

visualize::Field visualize::vector_space::get_field() {
	return field;
}

void visualize::vector_space::show() {
	std::cout << ((field == 0)? "R" : "C") << "^" << n << "\n";
}

int visualize::vector_space::dimension() {
	return n;
}

/*
visualize::vector
public functions:
*/

std::vector<int> visualize::vector::get_vector() {
	return elements;
}

float visualize::vector::norm(int p) {
	float sump = 0;
	for (int elem : elements) {
		sump += (float)pow(elem, p);
	}
	sump = pow(sump, 1.0f / p);
	return sump;
}

void visualize::vector::show() {
	std::cout << "[ ";
	for (int i = 0; i < dimension(); i++) {
		if (i == dimension() - 1) std::cout << elements[i] << " ";
		else std::cout << elements[i] << ", ";
	}
	std::cout << "] in ";
	V.show();
	std::cout << "\n";
}
int visualize::vector::dimension() {
	//return elements.size();
	return V.dimension();
}
int visualize::vector::index(int i) {
	return elements[i];
}

void visualize::vector::modify(int index, int value) {
	elements[index] = value;
}

/*
Operations on visualize::vector:
*/

int visualize::dot(visualize::vector v, visualize::vector u) {
	int dotprod = 0;
	for (int i = 0; i < v.dimension(); i++) {
		dotprod += v.index(i) * u.index(i);
	}
	return dotprod;
}

float visualize::metric(visualize::vector v, visualize::vector u) {
	visualize::vector x(v);
	for (int i = 0; i < v.dimension(); i++) {
		int sum = v.index(i) - u.index(i);
		x.modify(i, sum);
	}
	return x.norm(2);
}

visualize::vector visualize::vector_add(visualize::vector v, visualize::vector u) {
	visualize::vector x(v);
	for (int i = 0; i < v.dimension(); i++) {
		int sum = v.index(i) + u.index(i);
		x.modify(i, sum);
	}
	return x;
}

visualize::vector visualize::operator+(visualize::vector v, visualize::vector u) {
	visualize::vector x = v;
	for (int i = 0; i < v.dimension(); i++) {
		int val = v.index(i) + u.index(i);
		x.modify(i, val);
	}
	return x;
}

visualize::vector& visualize::vector::operator=(visualize::vector other) {
	for (int elem : other.elements) {
		this->elements.push_back(elem);
	}
	return *this;
}

visualize::vector visualize::scalar_mult(int a, visualize::vector v) {
	visualize::vector x(v);
	for (int i = 0; i < v.dimension(); i++) {
		int mult = a*v.index(i);
		x.modify(i, mult);
	}
	return x;
}

//visualize::vector scalar_mult(double a, double b, visualize::vector v);

//

double factorial(int n) {
	int fact = 1;
	for (int i = n; i>0; i--) {
		fact *= i;
	}
	return fact;
}

double visualize::cos(float x, int M) {

	double approx = 0;
	for (int i = 0; i < M; i++) {
		approx += (pow(-1, i) * pow(x, 2 * i)) / (factorial(2*i));
	}
	return approx;
}

//

/*
visualize::matrix
public functions:
*/

std::vector<std::vector<int> > visualize::matrix::get_matrix() {
	return elements;
}

void visualize::matrix::show() {
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

int visualize::matrix::dimension_X() {
	return X.dimension();
}

int visualize::matrix::dimension_Y() {
	return Y.dimension();
}

visualize::vector_space visualize::matrix::get_X() {
	return X;
}

visualize::vector_space visualize::matrix::get_Y() {
	return Y;
}
/*
visualize::matrix visualize::transpose(visualize::matrix T) {

}
*/

visualize::vector visualize::vector_transform(visualize::vector v, visualize::matrix T) {
	visualize::vector columns(T.get_Y());
	for (int i = 0; i < T.dimension_Y(); i++) {
		visualize::vector temp(T.get_X(), T.get_matrix().at(i));
		columns.modify(i, visualize::dot(v, temp));
	}
	return columns;
}

visualize::matrix matrix_transform(visualize::matrix T, visualize::matrix F);

/*
visualize::vector cross(visualize::vector a, visualize::vector b) {
}
*/

/*
visualize::tensor
public functions:
*/



/*
Operations on visualize::tensor:
*/
