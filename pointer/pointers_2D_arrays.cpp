#include <stdio.h>


int main(){
    int A[2][3] = {1,2,3,4,5,6};

    printf("A = %d\n", A);
    printf("&A[0] = %d\n", &A[0]);
    printf("*A = %d\n", *A);  // **A == 0
    printf("A[0] = %d\n", A[0]);
    printf("&A[0][0] = %d\n", &A[0][0]);
    printf("A+1 = %d\n", A+1);
    printf("&A[1] = %d\n", &A[1]);
    printf("&A[1][0] = %d\n", &A[1][0]);
    printf("*(A+1) = %d\n", *(A+1));
    printf("*(A+1)+2 = %d\n", *(A+1)+2);
    printf("A[1]+2 = %d\n", A[1]+2);
    printf("&A[1][2] = %d\n", &A[1][2]);
    printf("*(*A+1) = %d\n", *(*A+1));
    printf("A[0][1] = %d\n", A[0][1]);

}
