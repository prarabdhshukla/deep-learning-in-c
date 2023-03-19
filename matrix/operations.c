#include "operations.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int check_dimensions(Matrix* m1, Matrix* m2){
    if(m1->col == m2->row)
    return 1;
    else
    return 0;
}
int check_add_compat(Matrix* m1, Matrix* m2){
    if((m1->row == m2->row) && (m1->col==m2->col))
        return 1;
    else 
        return 0;
}
Matrix* multiply(Matrix* m1, Matrix* m2){
    if(check_dimensions(m1,m2)){
        Matrix *m3=matrix_zeros(m1->row, m2->col);
        for(int i=0;i<m1->row;i++){
            for(int j=0;j<m2->col;j++){
                for(int k=0;k<m2->row;k++)
                m3->entries[i][j]+=m1->entries[i][k]*m2->entries[k][j];
            }
        }
        return m3;
    }
    else{
        printf("Matrix dimensions are not compatible\n ");
        return NULL;
    }
}
Matrix* add(Matrix* m1, Matrix* m2){
    if(check_add_compat(m1,m2)){
        Matrix* m3= matrix_zeros(m1->row, m1->col);
        for(int i=0; i<m3->row;i++){
            for(int j=0; j<m3->col;j++)
                m3->entries[i][j]=m1->entries[i][j]+m2->entries[i][j];
        }
    return m3;
    }
    else{
        printf("Matrix dimensions are not compatible\n");
        return NULL;
    }
}
Matrix* subtract(Matrix* m1, Matrix* m2){
    if(check_add_compat(m1,m2)){
        Matrix* m3= matrix_zeros(m1->row, m1->col);
        for(int i=0; i<m3->row;i++){
            for(int j=0; j<m3->col;j++)
                m3->entries[i][j]=m1->entries[i][j]-m2->entries[i][j];
        }
    return m3;
    }
    else{
        printf("Matrix dimensions are not compatible\n");
        return NULL;
    }
}

Matrix* dot(Matrix* m1, Matrix* m2){
    if(check_add_compat(m1,m2)){
        Matrix* m3= matrix_zeros(m1->row, m1->col);
        for(int i=0; i<m3->row;i++){
            for(int j=0; j<m3->col;j++)
                m3->entries[i][j]=m1->entries[i][j]*m2->entries[i][j];
        }
    return m3;
    }
    else{
        printf("Matrix dimensions are not compatible\n");
        return NULL;
    }
}

Matrix* apply(double (*func)(double), Matrix* m){
    Matrix* M=matrix_zeros(m->row,m->col);
    for(int i=0; i<M->row;i++){
        for(int j=0; j<M->col;j++)
        M->entries[i][j]=(*func)(m->entries[i][j]); 
    }
    return M;
}
Matrix* scale(double n, Matrix* m){
    Matrix* M=matrix_zeros(m->row, m->col);
    for(int i =0; i<M->row;i++){
        for(int j=0; j<M->col;j++)
        M->entries[i][j]=n*(m->entries[i][j]);
    }
    return M;
}
Matrix* addScalar(double n, Matrix* m){
    Matrix* M=matrix_zeros(m->row, m->col);
    for(int i =0; i<M->row;i++){
        for(int j=0; j<M->col;j++)
        M->entries[i][j]=n+(m->entries[i][j]);
    }
    return M;
}
Matrix* transpose(Matrix*m){
    Matrix* mT=matrix_zeros(m->col,m->row);
    for(int i=0;i<m->col;i++){
        for(int j=0;j<m->row;j++)
        {
        mT->entries[i][j]=m->entries[j][i];
        }
    }
    return mT;
}


