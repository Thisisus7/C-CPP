#include <iostream>  // < >: only for compiler include parts, " ": for everything, also "../ " is also gonna work.
// <xxx.>h: C standard library; <xx>: C++ standard library
// using namespace std;  // can be use anywhere like in a class
// :: access class function and namespaces.
#define MAX_SIZE 101
/*
In struct, all variables and methods are going to be public by default.
In class, all variables and methods are going to be private by default.
protected: combination of private and public,
		   any thing inside this class or any class that is inheriting from this class has access
*/ 

class Stack{
private:  // only inside this class has access to this variable
	int A[MAX_SIZE];  // array to store the stack
	int top;   // variable to mark the top index of stack.
public:  // can be used by others 	
	// Stack(): a special method that is automatically called when an object of this class is created.	
	Stack(){
		top = -1;
	}

	void Push(int x){
		if (top == MAX_SIZE - 1){
			std::cout << "Error: stack overflow" << std::endl;  // printf: return an int, cout: doesn't return anything
			return;
		}
		A[++top] = x;  // increment will happen before assignment
	}

	void Pop(){
		if (top == -1){
			std::cout << "Error: No element to pop" << std::endl;
			return;
		}
		--top;
	}

	int Top(){
		return A[top];
	}

	void Print(){
		std::cout << "Stack: ";
		for (int i=0; i<=top; i++)
			std::cout << A[i] << " ";
		std:: cout << std::endl;		
	}
};

int main(){
	Stack S;
	S.Push(2); S.Print();
	S.Push(5); S.Print();
	S.Push(10); S.Print();
	S.Pop(); S.Print();
	S.Push(12); S.Print();
}
