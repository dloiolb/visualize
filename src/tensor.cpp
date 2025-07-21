#include "../include/tensor.h"

Linalg::tensor::tensor(const std::vector<double>& data, const std::vector<int>& shape) 
    : data(data), shape(shape), k(shape.size()), strides(k)
{
    compute_strides();
}

void Linalg::tensor::compute_strides(){
    int k = shape.size();
    strides[k-1] = 1;
    for(int l=k-2;l>=0;--l){
        strides[l] = strides[l+1] * shape[l+1];
    }
}

int Linalg::tensor::index(const std::vector<int>& i){
    int idx = 0;
    int k = shape.size();
    for(int j=0;j<k; ++j){
        idx += i[j] * strides[j];
    }
    return idx;
}

double& Linalg::tensor::operator()(const std::vector<int>& i){
    return data[index(i)];
}
