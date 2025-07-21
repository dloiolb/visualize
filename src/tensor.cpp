#include "../include/tensor.h"

/*
visualize::tensor
public functions:
*/

visualize::tensor::tensor(const std::vector<double>& data, const std::vector<int>& shape) 
    : data(data), shape(shape), k(shape.size()), strides(k)
{
    compute_strides();
}

void visualize::tensor::compute_strides(){
    int k = shape.size();
    strides[k-1] = 1;
    for(int l=k-2;l>=0;--l){
        strides[l] = strides[l+1] * shape[l+1];
    }
}

int visualize::tensor::index(const std::vector<int>& i){
    int idx = 0;
    int k = shape.size();
    for(int j=0;j<k; ++j){
        idx += i[j] * strides[j];
    }
    return idx;
}

double& visualize::tensor::operator()(const std::vector<int>& i){
    return data[index(i)];
}

void visualize::tensor::show() {
    if (k == 1) {
        std::cout << "[ ";
        for (int i = 0; i < shape[0]; ++i)
            std::cout << data[i] << " ";
        std::cout << "]\n";
    }
    else if (k == 2) {
        std::cout << "[\n";
        for (int i = 0; i < shape[0]; ++i) {
            std::cout << "  [ ";
            for (int j = 0; j < shape[1]; ++j) {
                std::cout << (*this)({i, j}) << " ";
            }
            std::cout << "]\n";
        }
        std::cout << "]\n";
    }
    else {
        std::cout << "tensor::show() for dimension " << k << " not available.\n";
    }
}

/*
Operations on between multiple visualize::tensor objects:
*/


/*
C functions available to python:
*/

visualize::tensor* tensor_new(const double* data, size_t data_len, const int* shape, size_t shape_len){
    std::vector<double> vec_data(data, data + data_len);
    std::vector<int> vec_shape(shape, shape + shape_len);
    return new visualize::tensor(vec_data, vec_shape);
}

void tensor_show(visualize::tensor* T){
    T->show();
}

void tensor_delete(visualize::tensor* T){
    delete T;
}
