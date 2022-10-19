#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    int *A = (int*)malloc(n*sizeof(int));  //  int A[n]: compilation error
    // int *A = (int*)calloc(n, sizeof(int));

    for (int i=0; i<n; i++){
        A[i] = i + 1;
    }
    int *B = (int*)realloc(A, n/2*sizeof(int));  // if A = NULL: realloc == malloc
    printf("Prev block address = %d, new address = %d\n", A, B);

    free(A); // we still can print A[i], but they are garbage values
    A[2] = 6;

    for (int i=0; i<n; i++){
        printf("%d ", A[i]);
    }

    free(B);
}
