#include "neuralNet.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../matrix/operations.h"
#include "../network/activations.h"

nn* nn_init(int hidden, char** activations, char* loss_fn, int input_size,int hidden_sizes[]){
    nn* network = malloc(sizeof(nn));
    network->hidden=hidden;
    network->activations=activations;
    network->loss_fn=loss_fn;
    network->input_size=input_size;
    network->iL=malloc(sizeof(input_layer));
    network->iL->input_size=network->input_size;
    network->iL->inp=matrix_zeros(input_size,1);
    network->hidden_layers=(layer **)malloc(network->hidden*sizeof(layer*));
    for(int i=0;i<hidden;i++){
        network->hidden_layers[i]=malloc(sizeof(layer));
        network->hidden_layers[i]->features=hidden_sizes[i];
        network->hidden_layers[i]->bias=uniform_xavier_rand(-1,1);
        if(i==0)
            network->hidden_layers[i]->w=random_matrix(input_size,network->hidden_layers[i]->features,-1,1);
        else
            network->hidden_layers[i]->w=random_matrix(network->hidden_layers[i-1]->features,network->hidden_layers[i]->features,-1,1);
        network->hidden_layers[i]->activation=activations[i];
        network->hidden_layers[i]->A=matrix_zeros(network->hidden_layers[i]->features,1);
        network->hidden_layers[i]->dA=matrix_zeros(network->hidden_layers[i]->A->row,network->hidden_layers[i]->A->col);
    }
    network->oL=malloc(sizeof(output_layer));
    network->oL->loss_fn=loss_fn;
    network->oL->activation= (char *)(&network->activations+1)-1; //last element of activations array
    layer *last_layer=(layer *)(&network->hidden_layers+1)-1;
    network->oL->out=matrix_zeros(last_layer->features, 1);
    network->oL->loss=(double)0.0;
    network->oL->dL=matrix_zeros(last_layer->features,1);
    return network;
}

// void main(){
//     char *activations[2]={"ReLU","Sigmoid"};
//     // char **activations;
//     // int SIZE=10;
//     // activations=(char **)malloc(SIZE*sizeof(char*));
//     // for(int row=0;row<2;row++){
//     //     activations[row]=(char *)malloc(SIZE*sizeof(char));
//     // }
//     // for(int row=0;row<2;row++)
//     //     activations[row]=a[row];
//     char *loss_fn="mse";
//     int hidden_sizes[2]={4,3};
//     nn* basic_net=nn_init(2,activations,loss_fn,5,hidden_sizes);
//     // printf("%i\n ",basic_net->input_size);
//     matrix_print(basic_net->hidden_layers[0]->w);
//     free(basic_net);
// }


