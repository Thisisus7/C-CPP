#include <iostream>
#include <stack>  // stack from standard template library (STL)
#include <cstdio>

void Reverse(){
	if (head == NULL) return;
	stack<struct Node*> S;
	Node* temp = head;
	while (temp != NULL){
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while (!S.empty()){
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}
int main(){
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    print(head);
    reverse(&head);
    cout << "rev: "<< "\n";
    print(head);
}
