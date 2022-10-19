#include <iostream>

class Stack{
private:
	struct Node{
		int data;
		Node* link;
		/*
		Node(int n){
			data = n;
			link = NULL;
		}
		*/
	}; 
	Node* top;
public:
	Stack(){
		top = NULL;
	}
	void Push(int x){
		Node* temp = new Node();
		temp->data = x;
		temp->link = top;
		top = temp;
	}
	void Pop(){
		if (top == NULL) return;
		Node* temp = top;
		top = top->link;
		free(temp);
	}
	int Top(){
		return top->data;
	}
	void Print(){
		Node* temp = top;
		std::cout << "Stack: ";
		while (temp != NULL){
			std::cout << temp->data <<" ";
			temp = temp->link;
		}
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
