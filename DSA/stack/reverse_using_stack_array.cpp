#include <iostream>
#include <stack>  // stack from standard template library (STL)
#include <cstring>  // strlen()
#include <cstdio>
#define length 51

// C[] == *C in a comilper;  n: number of chars in a str
void Reverse(char C[], int n){
	std::stack<char> S; // create a stack of char
	// loop for push  O(n)
	for (int i=0; i<n; i++){
		S.push(C[i]);
	}
	// loop for pop  O(n)
	for (int i=0; i<n; i++){
		C[i] = S.top();  // overwrite the char at index i
		S.pop();
	}
}

int main(){
	char C[length];
	std::cout << "Enter a string: ";
	std::fgets(C, length, stdin);  // (str, count, file_stream),  stdin: reading from standard input
	Reverse(C, strlen(C));
	std::cout << "Output = " << C << std::endl;
}
