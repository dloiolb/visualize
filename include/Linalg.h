#ifndef _Linalg_h
#define _Linalg_h

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

namespace Linalg {

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
		vector_space(const Linalg::vector_space & V) : field(V.field), n(V.n) {} //copy constructor

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
		vector(const Linalg::vector& v) : elements(v.elements), V(v.V) {} //copy constructor
		//vector(std::initializer_list<int> args) : elements(args) { } //variable number of elements

		std::vector<int> get_vector();
		void show(); //print vector
		float norm(int p);
		int dimension(); //return number of elements
		int index(int i); //value of xi for x = [x1,x2,...,xn], i in {1,2,...,n}
		void modify(int index, int value);
		//friend vector operator+(Linalg::vector a, Linalg::vector b);
		vector& operator=(Linalg::vector other);
		//friend int dot(Linalg::vector a, Linalg::vector b);
		//Linalg::vector cross(Linalg::vector a, Linalg::vector b);
	};

	//Binary operations between two vectors. In order to compute, two vectors must belong to the same vector space.
	int dot(Linalg::vector v, Linalg::vector u);
	float metric(Linalg::vector v, Linalg::vector u);
	vector operator+(Linalg::vector v, Linalg::vector u);
	Linalg::vector vector_add(Linalg::vector v, Linalg::vector u);

	Linalg::vector scalar_mult(int a, Linalg::vector v); //real field
	//Linalg::vector scalar_mult(double a, double b, Linalg::vector v); //complex field

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

	Linalg::matrix transpose(Linalg::matrix T);
	Linalg::vector vector_transform(Linalg::vector v, Linalg::matrix T);
	Linalg::matrix matrix_transform(Linalg::matrix T, Linalg::matrix F);

	double cos(float x, int M);







	class tensor {
	private:
		std::vector<double> data; // flattened data in R^{n_1 x n_2 x ... x n_k}
		std::vector<int> shape; // [n_1,n_2,...,n_k] - COMPUTED ONCE
		int k; // k is number of n_l's - COMPUTED ONCE
		std::vector<int> strides; // stride[j] = (\prod_{l=j+1}^k n_l) for j=1,...,k - COMPUTED ONCE
		//idx(T[i_1][i_2]...[i_k]) = \sum_{j=1}^ki_j*(\prod_{l=j+1}^k n_l) = \sum_{j=1}^ki_j*strides[j]

	public:
		tensor() = default;
		tensor(const std::vector<double>& data, const std::vector<int>& shape) 
			: data(data), shape(shape), k(shape.size()), strides(k)
		{
			compute_strides();
		}
		void compute_strides(){
			int k = shape.size();
			strides[k-1] = 1;
			for(int l=k-2;l>=0;--l){
				strides[l] = strides[l+1] * shape[l+1];
			}
		}
		int index(const std::vector<int>& i){
			int idx = 0;
			int k = shape.size();
			for(int j=0;j<k; ++j){
				idx += i[j] * strides[j];
			}
			return idx;
		}
		double& operator()(const std::vector<int>& i){
			return data[index(i)];
		}

		// std::vector<int> get_tensor();
		// void show(); //print vector
		// void show2();
		// float norm(int p);
		// int dimension(); //return number of elements
		// int index(int i); //value of xi for x = [x1,x2,...,xn], i in {1,2,...,n}
		// void modify(int index, int value);
		// //friend vector operator+(Linalg::vector a, Linalg::vector b);
		// tensor& operator=(Linalg::tensor other);
		// //friend int dot(Linalg::vector a, Linalg::vector b);
		// //Linalg::vector cross(Linalg::vector a, Linalg::vector b);
		// int dimension_X();
		// int dimension_Y();

	};

	//Binary operations between two vectors. In order to compute, two vectors must belong to the same vector space.
	int dot(Linalg::tensor v, Linalg::tensor u);
	float metric(Linalg::tensor v, Linalg::tensor u);
	tensor operator+(Linalg::tensor& v, Linalg::tensor& u);
	tensor operator*(Linalg::tensor v, Linalg::tensor u);
	// tensor operator%(Linalg::tensor v, Linalg::tensor u);
	Linalg::tensor vector_add(Linalg::tensor v, Linalg::tensor u);

	Linalg::tensor scalar_mult(int a, Linalg::tensor v); //real field
	//Linalg::vector scalar_mult(double a, double b, Linalg::vector v); //complex field
	
	Linalg::tensor transpose(Linalg::tensor T);
	Linalg::tensor vector_transform(Linalg::tensor v, Linalg::tensor T);
	// Linalg::tensor matrix_transform(Linalg::tensor T, Linalg::matrix F);

	double cos(float x, int M);
}



#endif
