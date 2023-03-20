#include <stdio.h>
#include <string.h>


void print(char A[]){
    int i = 0;
    while (A[i] != '\0'){  // A[i] == *(A+i)  rewrite: *A
        printf("%c", A[i]);
        i++;  // rewrite A++;
    }
    printf("\n");
}

int main(){
    printf("---rule for string---\n");
    char C[4];  // bad
    C[0] = 'J';
    C[1] = 'O';
    C[2] = 'H';
    C[3] = 'N';
    printf("%s\n", C);

    char S[20];  // good
    S[0] = 'J';
    S[1] = 'O';
    S[2] = 'H';
    S[3] = 'N';
    S[4] = '\0';
    printf("%s\n", S);
    printf("size of S[20] = %d\n", sizeof(S));
    printf("length of S[20] = %d\n", strlen(S));

    char A[] = "JOHN"; // DEFAULT
    printf("%s\n", A);
    printf("size of A[] = %d\n", sizeof(A));
    printf("length of A[] = %d\n", strlen(A));

    printf("---pointer and array---\n");
    char c1[6] = "hello";
    char* c2 = c1;
    //wrong: c1 = c1 + 1;  (array)
    // correct: c2 = c2 + 1   (pointer)

    printf("---arrays passed to function by reference---\n");
    print(A);
}
