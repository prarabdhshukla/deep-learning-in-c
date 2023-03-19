#pragma once
#include "../matrix/matrix.h"
typedef struct{
    int features;//number of neurons in the layer
    Matrix* w;//weights to be multiplied with the output of prev layer
    char* activation;//type of activation function
    double bias;//bias 
    Matrix* A; //activations of this layer
    Matrix* dA;// gradient of the output of this layer
}layer;
typedef struct{
    char* loss_fn;
    char* activation;
    Matrix* out; //output=activation(prev_layer_output)
    double loss;
    Matrix* dL;
}output_layer;
typedef struct{
    int input_size;
    Matrix* inp; //input vector
}input_layer;

typedef struct{
    int hidden;
    char** activations;
    char* loss_fn;
    int input_size;
    input_layer* iL;
    output_layer* oL;
    layer** hidden_layers;
}nn;

nn* nn_init(int hidden, char** activations, char* loss_fn, int input_size, input_layer* iL, output_layer* oL, layer** hidden_layers);