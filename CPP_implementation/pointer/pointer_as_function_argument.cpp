#include <stdio.h>

// called func
void Increment(int *a){  // a: another loval variable
    *a += 1;
    printf("address of a in Increment: %d\n", &a);
}

// calling func
int main() {
    int a = 10; // a: local variable
    //Increment(a); --call by value
    Increment(&a); // call by reference
    printf("address of a in main: %d\n", &a);
    printf("%d", a);
}
