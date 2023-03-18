#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void Print(struct Node* p){
	if (p == NULL){
		cout << "\n";
		 return;
	}	 
	cout << p->data << " ";  // print the value in the node
	Print(p->next);  // recursive call
}

void ReversePrint(struct Node* p){
	if (p == NULL){
		return;  // exit condition
	}
	ReversePrint(p->next);  // recursive call
	cout << p->data << " ";  // print the value in the node
}

struct Node* Insert(Node* head, int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	
	if(head == NULL) head = temp;
	else
       	{
		Node* temp1 = head;
		while(temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

int main()
{
	struct Node* head = NULL;  // local variable
	head = Insert(head, 2);  // we have to use head = to modify local variable head
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 5);
	Print(head);
	ReversePrint(head);

}
