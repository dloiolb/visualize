#ifndef _TENSOR_H
#define _TENSOR_H

#include <cmath>
#include <vector>
#include <iostream>
#include <initializer_list>

namespace visualize {
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
            void show();

    };

	//Binary operations between two vectors. In order to compute, two vectors must belong to the same vector space.
	int dot(visualize::tensor v, visualize::tensor u);
	float metric(visualize::tensor v, visualize::tensor u);
	tensor operator+(visualize::tensor& v, visualize::tensor& u);
	tensor operator*(visualize::tensor v, visualize::tensor u);
	// tensor operator%(visualize::tensor v, visualize::tensor u);
	visualize::tensor vector_add(visualize::tensor v, visualize::tensor u);

	visualize::tensor scalar_mult(int a, visualize::tensor v); //real field
	//visualize::vector scalar_mult(double a, double b, visualize::vector v); //complex field
	
	visualize::tensor transpose(visualize::tensor T);
	visualize::tensor vector_transform(visualize::tensor v, visualize::tensor T);
	// visualize::tensor matrix_transform(visualize::tensor T, visualize::matrix F);

	double cos(float x, int M);
}

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct visualize_tensor visualize_tensor;
    visualize::tensor* tensor_new(const double* data, size_t data_len, const int* shape, size_t shape_len);
    void tensor_show(visualize::tensor* T);
    void tensor_delete(visualize::tensor* T);

#ifdef __cplusplus
}
#endif


#endif
