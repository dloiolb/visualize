#ifndef _TENSOR_H
#define _TENSOR_H

#include <cmath>
#include <vector>
#include <iostream>
#include <initializer_list>

namespace Linalg {
    class tensor {
        private:
            std::vector<double> data; // flattened data in R^{n_1 x n_2 x ... x n_k}
            std::vector<int> shape; // [n_1,n_2,...,n_k] - COMPUTED ONCE
            int k; // k is number of n_l's - COMPUTED ONCE
            std::vector<int> strides; // stride[j] = (\prod_{l=j+1}^k n_l) for j=1,...,k - COMPUTED ONCE
            //idx(T[i_1][i_2]...[i_k]) = \sum_{j=1}^ki_j*(\prod_{l=j+1}^k n_l) = \sum_{j=1}^ki_j*strides[j]

        public:
            tensor() = default;
            tensor(const std::vector<double>& data, const std::vector<int>& shape);
            void compute_strides();
            int index(const std::vector<int>& i);
            double& operator()(const std::vector<int>& i);

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
