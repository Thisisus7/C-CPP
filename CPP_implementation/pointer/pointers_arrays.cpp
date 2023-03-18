#include <stdio.h>

int main(){
    int A[] = {2, 4, 5, 8, 1};
    printf("A: %d\n", A);
    printf("&A[0]: %d\n", &A[0]);
    printf("A[0]: %d\n", A[0]);
    printf("*A: %d\n", *A);


    for(int i=0; i<5; i++){
        printf("&A[i]: %d\n", &A[i]);
        printf("A+i: %d\n", A+i);
        printf("A[i]: %d\n", A[i]);
        printf("*(A+i): %d\n", *(A+i));
    }
}
