#include <stdio.h>

void PrintHello(char* name){
    printf("Hello %s!\n", name);
}

int Add(int a, int b){
    return a+b;
}

int main(){
    void (*ptr)(char);
    ptr = PrintHello;
    ptr("transformer");

    int (*p)(int, int) = &Add;  // pointer to function, (int, int) as argument
    // int* p(int, int): declare a function that would return int*
    int c = (*p)(2,3);  //(*p):dereference and execute the function
    printf("sum = %d\n", c);
}
