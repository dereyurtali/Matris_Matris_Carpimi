#ifndef MatrixMultiply_h
#define MatrixMultiply_h
#endif /* MatrixMultiply_h */

float randFloat(void);


float** generate2DRandomMatrix(int); // creates a matrixgenerate2DRandomMatrix                                                                                   // and n column with random integers.

void print2DArray(float **, int);


void multiplyIJK(float **, float **, float **, int);

void multiplyIKJ(float **, float **, float **, int);

void multiplyJIK(float **, float **, float **, int);

void multiplyJKI(float **, float **, float **, int);

void multiplyKIJ(float **, float **, float **, int);

void multiplyKJI(float **, float **, float **, int);

void matrixMatrixMultiply(float **, float **, int); // takes two arrays,
                                          // multiplies them in
                                          // different ways. prints wasted time.
