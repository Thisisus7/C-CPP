#include <stdio.h>

int main(){
    int a = 10;
    int *p = &a; // address of a

    printf("p: %d\n", p);
    printf("value at address p: %d\n", *p);
    printf("address of a: %d\n", &a);

    *p = 12; //dreferencing
    printf("a (after dereferencing by *p): %d\n", a);

    // pointer arithmetic
    printf("p+1: %d\n", p+1);  // +4: int -- 4 bytes
    printf("value at address p+1: %d\n", *(p+1));
}
