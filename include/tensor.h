#ifndef _TENSOR_H
#define _TENSOR_H

#include <cmath>
#include <vector>
#include <algorithm>
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

            int index(const std::vector<int>& i);

        public:
            const std::vector<double>& get_data() const { return data; }
            const std::vector<int>& get_shape() const { return shape; }
            const int& get_k() const { return k; }
            const std::vector<int>& get_strides() const { return strides; }

            tensor() = default;
            tensor(const std::vector<double>& data, const std::vector<int>& shape);
            void compute_strides();
            double& operator()(const std::vector<int>& i);
            void show();

    };
    
    double norm_p(visualize::tensor& v, int p);
    double norm_sup(visualize::tensor& v);

    visualize::tensor matmul(visualize::tensor& v, visualize::tensor& u); // matmul function
    visualize::tensor hadamard(visualize::tensor& v, visualize::tensor& u); //hadamard function
    visualize::tensor outer(visualize::tensor& v, visualize::tensor& u); // outer function
    visualize::tensor operator*(visualize::tensor& v, visualize::tensor& u); // matmul operator
	visualize::tensor operator%(visualize::tensor& v, visualize::tensor& u); // hadamard operator

    // OLD OLD OLD:

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
