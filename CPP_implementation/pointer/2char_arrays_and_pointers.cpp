#include <stdio.h>
#include <string.h>

void print(char *C){  // const char *C: also read only
    while(*C != '\0'){
        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main(){
    // char C[20] = "Hello"; string gets stored in the space for array
    char* C ="Hello";  // string gets stored as compile time constant, read only
    // C[0] = 'A';  wrong!! can't be modified
    print(C);
}
