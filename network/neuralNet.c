#include "neuralNet.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../matrix/operations.h"
#include "../network/activations.h"



Dense** NN_init(int input_size, int hidden, int* hidden_sizes, char** activations){
    Dense** layers=malloc(sizeof(Dense*)*hidden);
    for(int i=0; i<hidden;i++){
        Dense* layer= malloc(sizeof(Dense));
        layer->neurons=hidden_sizes[i];
        layer->activation=activations[i];
        if(i==0)
        layer->input_shape=input_size;
        else
        layer->input_shape=hidden_sizes[i-1];
        layer->b=0;
        layer->w=matrix_zeros(layer->input_shape,layer->neurons);
        layer->output=matrix_zeros(layer->neurons,1);
        layers[i]=layer;
    }
    return layers;
}
void NN_batch_train(Dense** layers, Matrix* batch){
    for(int i=0;i<batch->row;i++){
        Matrix* ex=matrix_zeros()
    }
}
