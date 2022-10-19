#include<stdio.h>
#include<stdlib.h>

int* Add(int* a, int* b){  // called
    printf("Address of a in Add() is %d\n", a);
    int* c = (int*)malloc(sizeof(int));  // we must use heap or global like this
    *c = *a + *b;
    return c;
}


int main(){  // calling
    int a = 2, b = 4;
    printf("Address of a in main() is %d\n", &a);
    // call by value
    // int z = Add(a, b);  value in a,b of main() are copied to a,b of Add()

    //
    int* ptr = Add(&a, &b);  // value in a,b of main() are copied to a,b of Add()
    printf("Sum = %d\n", *ptr);
    free(ptr);
}
