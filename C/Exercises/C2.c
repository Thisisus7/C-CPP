#include <stdio.h>

void smile(void);
void one_three(void);
void two(void);
void smile(void);

int main(void) {
    printf("7");
    smile(); smile(); smile(); printf("\n");
    smile(); smile(); printf("\n");
    smile(); printf("\n");

    printf("8");
    printf("starting now:\n");
    one_three();
    printf("done!\n");
    
    return 0;
}

void smile(void) {
    printf("Smile!");
}

void one_three(void) {
    printf("one\n");
    two();
    printf("three\n");
}

void two(void) {
    printf("twp\n");
}