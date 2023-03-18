#include <stdio.h>

int main(){
    int a = 1025;
    int *p = &a;
    printf("size of int is %d\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);

    char *p0;
    p0 = (char*)p;  // type casting
    printf("size of char is %d\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0, *p0);

    // void pointer
    void *p1;
    p1 = p;
    // *p1 = &a; can't dereference
    printf("Address = %d, value = %d\n", p0, *p0);
}
