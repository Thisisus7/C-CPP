// int A[] only pass a address, not the whole array!
#include <stdio.h>

int sum_of_element(int A[]){  // in compiler: int A == int* A
    int sum = 0;
    int size = sizeof(A) / sizeof(A[0]);
    printf("SOE: A = %d", A);
    printf("SOE: size of A = %d, sizeof A[0] = %d\n", sizeof(A), sizeof(A[0]));
    for (int i=0; i<size; i++){
        sum += A[i];
    }
    return sum;
}

void Double(int* A, int size){
    for (int i=0; i<size; i++){
        A[i] = 2 * A[i];
    }
}

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(A) / sizeof(A[0]);
    int total = sum_of_element(A); // A == &A[0]
    printf("sum of elements = %d\n", total);
    printf("main: size of A = %d, sizeof A[0] = %d\n", sizeof(A), sizeof(A[0]));

    Double(A, size);
    for (int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
}
