#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float randFloat(){
    float scale;
    scale = rand() / (float)RAND_MAX;
    scale = 0.0 + scale * (10.0 - 0.0);
    return scale;
}

 
float** generate2DRandomMatrix(int n){
    int i,j;
    float x;
     
    // ######### MATRISE YER AYIRMAK ICIN ############
    float **arr = (float **)malloc(n*sizeof(float *));
    for (i = 0; i<n; i++) {
        arr[i] = (float *)malloc(n*sizeof(float));
    }
    // ######### MATRISE YER AYIRMAK ICIN ############
    
    // ######### MATRISI DOLDURMAK ICIN ##############
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            x = randFloat();
            (*(arr[i]+j)) = x;
        }
    }
    // ######### MATRISI DOLDURMAK ICIN ##############
  
    return arr;
}


void print2DArray(float** arr, int n){
    int i, j;
    for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%f\t", arr[i][j]);
            }
            printf("\n\n");
        }
}


void multiplyIJK(float **fr, float **sc, float **th, int n){
    int i, j, k;
    for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
              for(k = 0; k < n; k ++){
                th[i][j] += fr[i][k] * sc[k][j];
              }
            }
          }
}

void multiplyIKJ(float **fr, float **sc, float **th, int n){
    int i, j, k;
    for(i = 0; i < n; i ++){
            for(k = 0; k < n; k ++){
              for(j = 0; j < n; j ++){
                th[i][j] += fr[i][k] * sc[k][j];
              }
            }
          }
}

void multiplyJIK(float **fr, float **sc, float **th, int n){
    int i, j, k;
    for(j = 0; j < n; j ++){
            for(i = 0; i < n; i ++){
              for(k = 0; k < n; k ++){
                th[i][j] += fr[i][k] * sc[k][j];
              }
            }
          }
}

void multiplyJKI(float **fr, float **sc, float **th, int n){
    int i, j, k;
    for(j = 0; j < n; j ++){
            for(k = 0; k < n; k ++){
              for(i = 0; i < n; i ++){
                th[i][j] += fr[i][k] * sc[k][j];
              }
            }
          }
}

void multiplyKIJ(float **fr, float **sc, float **th, int n){
    int i, j, k;
    for(k = 0; k < n; k ++){
            for(i = 0; i < n; i ++){
              for(j = 0; j < n; j ++){
                th[i][j] += fr[i][k] * sc[k][j];
              }
            }
          }
}

void multiplyKJI(float **fr, float **sc, float **th, int n){
    int i, j, k;
    for(k = 0; k < n; k ++){
        for(j = 0; j < n; j ++){
            for(i = 0; i < n; i ++){
                th[i][j] += fr[i][k] * sc[k][j];
              }
            }
          }
}


void matrixMatrixMultiply(float **fr, float **sc, int n){
    clock_t begin, end;
    double time_spent;
    int i;
    float **th = (float **)malloc(n*sizeof(float *));
    for (i = 0; i<n; i++) {
        th[i] = (float *)malloc(n*sizeof(float));
    }
    printf("IJK multiply starting...\n");
    begin = clock();
    multiplyIJK(fr, sc, th, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for IJK multiply process: %f second.\n", time_spent);
    
    printf("IKJ multiply starting...\n");
    begin = clock();
    multiplyIKJ(fr, sc, th, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for IKJ multiply process: %f second.\n\n", time_spent);
    
    printf("JIK multiply starting...\n");
    begin = clock();
    multiplyJIK(fr, sc, th, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for JIK multiply process: %f second.\n", time_spent);
    
    printf("JKI multiply starting...\n");
    begin = clock();
    multiplyJKI(fr, sc, th, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for JKI multiply process: %f second.\n\n", time_spent);
    
    printf("KIJ multiply starting...\n");
    begin = clock();
    multiplyKIJ(fr, sc, th, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for KIJ multiply process: %f second.\n", time_spent);
    
    printf("KJI multiply starting...\n");
    begin = clock();
    multiplyKJI(fr, sc, th, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for KJI multiply process: %f second.\n\n", time_spent);
    
    
    
}
