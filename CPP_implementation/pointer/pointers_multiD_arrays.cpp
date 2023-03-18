#include <stdio.h>
      // int (*C)[2][2] or ***C
int Func(int C[][2][2])  // int *A or A[]:  passing 1-d array
{}                        // int A[][]: passing 2-d array

int main(){
    int C[3][2][2] = {{{2,5}, {7,9}},
                      {{3,4}, {6,1}},
                      {{0,8}, {11,13}}};
    int A[2] = {1,2};
    int B[2][3] = {{2,4,6}, {5,7,8}};

    printf("%d %d %d %d\n", C, *C, C[0], &C[0][0]);

    Func(C);
}
