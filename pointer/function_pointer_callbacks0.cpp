#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// callback function
// change 1 and -1 get ascending and descending sort
int absolute_compare(int a, int b){
    if (abs(a) > abs(b)) return 1;
    else return -1;
}

int compare(const void* a, const void* b){  // void pointer: general pointer
    int A = *((int*)a); // (int*): typecast
    int B = *((int*)b);
    return A - B;  // B-A: descending
}

void bubble_sort(int *A, int n, int (*compare)(int,int)){  // int A[] == int *A
    int i, j, temp;
    for (i=0; i<n; i++){
        for (j=0; j<n-1; j++){
            if (compare(A[j], A[j+1]) > 0){  // < discending
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int A[] = {-31, 22, -1, 50, -6, 4}; // sort absolute value
    bubble_sort(A, 6, absolute_compare);
    for (int i=0; i<6; i++) printf("%d ", A[i]);
    printf("\n");
    qsort(A, 6, sizeof(int), compare);
    for (int i=0; i<6; i++) printf("%d ", A[i]);
}

//void A(){  // callback function
//    printf("Hello");
//}

//void B(void (*ptr)()){  // takes a function pointer as arugument
//    ptr();  // callback function that ptr points to
//}

//int main(){
    // void (*p)() = A;
    // B(p);
//    B(A);
//}
