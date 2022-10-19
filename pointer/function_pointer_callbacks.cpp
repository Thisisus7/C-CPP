#include <stdio.h>

// callback function
// change 1 and -1 get ascending and descending sort
int compare(int a, int b){
    if (a > b) return -1;
    else return 1;
}

void bubble_sort(int A[], int n, int (*compare)(int,int)){  // int A[] == int *A
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
    int A[] = {3, 4, 2, 6, 1, 5};
    bubble_sort(A, 6, compare);
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
