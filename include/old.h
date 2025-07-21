#ifndef _OLD_H
#define _OLD_H

#include <cmath>
#include <vector>
#include <iostream>
#include <initializer_list>
//#include <cassert>

/*
* Vector: m elements
* matrix: m x n elements
* Ax = b, matrix A (m,n), vectors x (n,1), b (m,1)... number of elements of x must be == num of columns of A
*/

namespace visualize {

	//Fields are sets with the operations of addition and multiplication that obey important properties. Every vector space is over a field.
	enum Field { R, C };

	//Vector spaces:
	class vector_space {
	private:
		Field field; //R or C
		int n; // KxKx...xK = K^n = {(x1,...,xn): xi in K for i=1,...,n}
	public:
		vector_space() = default;
		vector_space(Field field, int n) : field(field), n(n) {}
		vector_space(const visualize::vector_space & V) : field(V.field), n(V.n) {} //copy constructor

		int dimension();
		Field get_field();
		void show();
	};

	//Vectors are elements of a vector space:
	class vector {
	private:
		std::vector<int> elements;
		vector_space V;
		//int dimension; //

	public:
		vector() = default;
		vector(vector_space V, std::vector<int> args) : V(V), elements(args) { }
		vector(vector_space V) : V(V), elements(V.dimension(), 0) { }
		vector(const visualize::vector& v) : elements(v.elements), V(v.V) {} //copy constructor
		//vector(std::initializer_list<int> args) : elements(args) { } //variable number of elements

		std::vector<int> get_vector();
		void show(); //print vector
		float norm(int p);
		int dimension(); //return number of elements
		int index(int i); //value of xi for x = [x1,x2,...,xn], i in {1,2,...,n}
		void modify(int index, int value);
		//friend vector operator+(visualize::vector a, visualize::vector b);
		vector& operator=(visualize::vector other);
		//friend int dot(visualize::vector a, visualize::vector b);
		//visualize::vector cross(visualize::vector a, visualize::vector b);
	};

	//Binary operations between two vectors. In order to compute, two vectors must belong to the same vector space.
	int dot(visualize::vector v, visualize::vector u);
	float metric(visualize::vector v, visualize::vector u);
	vector operator+(visualize::vector v, visualize::vector u);
	visualize::vector vector_add(visualize::vector v, visualize::vector u);

	visualize::vector scalar_mult(int a, visualize::vector v); //real field
	//visualize::vector scalar_mult(double a, double b, visualize::vector v); //complex field

	//Matrices are linear transformations between two vector spaces
	class matrix {
	private:
		//T:X->Y
		std::vector<std::vector<int> > elements;
		vector_space X;
		vector_space Y;
		//int m; //elements.size()
		//int n; //elements[i].size()
	public:
		matrix() = default;
		matrix(vector_space X, vector_space Y,  std::vector<std::vector<int> > args) : X(X), Y(Y), elements(args) { }

		std::vector<std::vector<int> > get_matrix();
		void show();
		vector_space get_X();
		vector_space get_Y();
		int dimension_X();
		int dimension_Y();

	};

	visualize::matrix transpose(visualize::matrix T);
	visualize::vector vector_transform(visualize::vector v, visualize::matrix T);
	visualize::matrix matrix_transform(visualize::matrix T, visualize::matrix F);

	double cos(float x, int M);

}



#endif
