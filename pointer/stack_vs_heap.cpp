#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;  // goes on stack
    int *p;
    p = new int;  // p = (int*)malloc(20 * sizeof(int));  goes on heap
    *p = 10;
    delete p;  // free(p);
    p = new int[20];  // for array
    delete[] p;
}
