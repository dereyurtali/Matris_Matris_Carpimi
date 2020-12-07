#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


int main() {
    int n;
    
    printf("Give the size of matrix: \n");
    scanf("%d",&n);
    printf("Matrix will be generated %d X %d.\n\n",n,n);
    
    printf("Generating the first matrix...\n");
    float **array1 = generate2DRandomMatrix(n);
    printf("First matrix generated.\n\n");
    printf("Generating the second matrix...\n");
    float **array2 = generate2DRandomMatrix(n);
    printf("Second matrix generated.\n\n");
    
    /*
    printf("\n\nfirst matrix:\n");
    print2DArray(array1, n);
    
    printf("\n\nsecond matrix:\n");
    print2DArray(array2, n);
    */
    
    printf("Matrix multiplication starting...\n");
    matrixMatrixMultiply(array1, array2, n);
    printf("Matrix multiplication finished...\n");
   
    
    
    return 0;
}
