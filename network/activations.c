#include "activations.h"
#include <math.h>
#include "../matrix/operations.h"
double sigmoid(double x){
    return 1.0/(1+exp(-1*x));
}
double RELU(double x){
    if(x<0)
    return 0;
    else
    return x;
}
Matrix* softmax(Matrix* m){
    double sum=0;
    for(int i=0;i<m->row;i++){
        for(int j=0;j<m->col;j++)
        sum+=exp(m->entries[i][j]);
    }
    Matrix* out=matrix_zeros(m->row,m->col){
        for(int i=0;i<out->row;i++){
            for(int j=0;j<out->col;j++)
            out->entries[i][j]=exp(m->entries[i][j])/total;
        }
    }
    return out;
}