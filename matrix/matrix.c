#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 100
Matrix* matrix_create(int row, int col, double** entries){
    Matrix *matrix= malloc(sizeof(Matrix));
    matrix->row = row;
    matrix->col=col;
    matrix->entries= entries;
    return matrix;
}
Matrix* matrix_eye(int n){
    Matrix* matrix=malloc(sizeof(Matrix));
    matrix->row=n;
    matrix->col=n;
    matrix->entries=malloc(sizeof(double*));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix->entries[i][j]=(double)1.0;
        }
    }
    return matrix;
}
Matrix* matrix_zeros(int row, int col){
    Matrix* matrix=malloc(sizeof(Matrix));
    matrix->row=n;
    matrix->col=n;
    matrix->entries=malloc(sizeof(double*));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix->entries[i][j]=(double)0.0;
        }
    }
    return matrix;
}
void matrix_print(Matrix* m){
    row=m->row;
    col=m->col;
    for(int i=0; i<row;i++){
        for(int j=0; j<col;j++){
            printf("%d ",m->entries[i][j]);
        }
        printf("\n");
    } 
}
void matrix_save(Matrix* m, char* file_name){
    FILE* file= fopen(file_name,"w");
    fprintf(file, "%d\n",m->row);
    fprintf(file,"%d\n",m->col);
    for(int i=0; i<m->row;i++){
        for(int j=0;j<m->col;j++){
            fprintf(file, "%.6f\n",m->entries[i][j]);
        }
    }
    printf("Successfully saved matrix to %s\n", file_name);
    fclose(file);
}
void matrix_update(Matrix* m,double** entries){
    m->entries=entries;
    return m;
}
Matrix* matrix_load(char* file_name){
    FILE* file= fopen(file_string, "r");
    char entry[MAXCHAR];
    fgets(entry,MAXCHAR,file);
    int rows=atoi(entry);
    fgets(entry,MAXCHAR,file);
    int cols = atoi(entry);
    Matrix* m= matrix_zeros(rows,cols);
    for(int i=0;i<m->row;i++){
        for(int j=0;j<m->col;j++){
            fgets(entry,MAXCHAR,file);
            m->entries[i][j]=strtod(entry,NULL);
        }
    }
    printf("Successfully loaded the matrix from %s\n",file_name);
    fclose(file_name);
    return m;
}
Matrix* matrix_flatten(Matrix* m, int axis){
    if(axis==1){
        Matrix* m2=matrix_zeros(m->row*m->col,1);
        int k=0;
        for(int i=0;i<m->row;i++){
            for(int j=0;j<m->col;j++){
                m2->entries[k][0]=m->entries[i][j];
                k+=1;
            }
        }
    }
    else if(axis==0){
        Matrix* m2=matrix_zeros(1,m->row*m->col);
        int k=0;
        for(int i=0;i<m->row;i++){
            for(int j=0;j<m->col;j++){
                m2->entries[0][k]=m->entries[i][j];
                k+=1
            }
        }
    }
    return m2;
}
int* matrix_argmax(Matrix* m){
    max=-1*INFINITY-1;
    max_i=0;
    max_j=0;
    for(int i=0;i<m->row;i++){
        for(int j=0;j<m->col;j++){
            if(m->entries[i][j]>max){
                max_i=i;
                max_j=j;
            }
        }
    }
    int a[2]={max_i,max_j};
    return a;
}
