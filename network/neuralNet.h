#pragma once
#include "../matrix/matrix.h"
typedef struct {
    int neurons;
    char* activation;
    int input_shape;
    Matrix* w; //weights
    int b; //bias
    Matrix* output;
}Dense;
// typedef struct{
//     int input_size;
//     Matrix* input_vec;
// }Input;
// typedef struct{
//     int output_size;
//     Matrix* output;
// }Output;

Dense** NN_init(int input_size, int hidden, int* hidden_sizes, char** activation);
void NN_batch_train(Dense** layers, Matrix* batch);