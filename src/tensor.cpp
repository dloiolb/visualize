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

double visualize::norm_p(visualize::tensor& v, int p){
    int k = v.get_k();
    std::vector<double> data= v.get_data();
    std::vector<int> shape= v.get_shape();
    if(k==1){
        double norm = 0;
        for(int i=0;i<shape[k-1];i++){
            norm += std::pow(std::abs(data[i]),p);
        }
        norm = std::pow(norm, 1.0/p);
        return norm;
    }
    else{
        return 0;
    }
}

double visualize::norm_sup(visualize::tensor& v){
    int k = v.get_k();
    std::vector<double> data = v.get_data();
    if(k==1){
        double norm = 0;
        auto result = std::max_element(data.begin(), data.end(), [](int a, int b)
        {
            return std::abs(a) < std::abs(b);
        });
        norm = *result;
        return norm;
    }
    else{
        return 0;
    }
}

/*
Operations on between multiple visualize::tensor objects:
*/

// visualize::tensor visualize::matmul(visualize::tensor& v, visualize::tensor& u){
//     int k_v = v.get_k();
//     std::vector<double> data_v = v.get_data();
//     std::vector<int> shape_v = v.get_shape();
//     int k_u = u.get_k();
//     std::vector<double> data_u = u.get_data();
//     std::vector<int> shape_u = u.get_shape();
//     if (k_v>2) {
//         throw std::invalid_argument("k too large: k>2");
//     }
//     else if (shape_v != shape_u) {
//         throw std::invalid_argument("inner dimensions dont match");
//     }
//     else if(k_v==1){   
//         for(int i=0;i<shape_v[k_v]-1;i++){

//         }
//     }
//     else if(k_v==2){   
//         for(int i=0;i<){

//         }
//     }
// }
visualize::tensor visualize::hadamard(visualize::tensor& v, visualize::tensor& u){
    if (v.get_shape() != u.get_shape()) {
        throw std::invalid_argument("Hadamard product requires same shape");
    }

    const std::vector<double>& a = v.get_data();
    const std::vector<double>& b = u.get_data();
    std::vector<double> result(a.size());

    std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                   [](double x, double y) { return x * y; });

    return visualize::tensor(result, v.get_shape());
}
// visualize::tensor visualize::outer(visualize::tensor& v, visualize::tensor& u){

// }


// visualize::tensor visualize::operator*(visualize::tensor& v, visualize::tensor& u){

// }
visualize::tensor visualize::operator%(visualize::tensor& v, visualize::tensor& u){
    return visualize::hadamard(v,u);
}


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
