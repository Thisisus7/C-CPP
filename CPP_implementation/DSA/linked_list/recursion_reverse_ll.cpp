#include <iostream>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;
// work for global variable
void Reverse(struct Node* p){
	if(p->next == NULL){
		head = p;
		// return;
		return ;
	}
	Reverse(p->next);
	// struct 	Node* q = p->next;
	// q->next = p;
	// these two lines are same thing as the below line
	p->next->next = p;
	p->next = NULL;
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

void Print(struct Node* p){
	if (p == NULL){
		std::cout << "\n";
		 return;
	}	 
	std::cout << p->data << " ";  // print the value in the node
	Print(p->next);  // recursive call
}

int main()
{
	// struct Node* head = NULL;  // local variable
	head = NULL;
	head = Insert(head, 2);  // we have to use head = to modify local variable head
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 5);
	head = Insert(head, 8);
	Print(head);
	Reverse(head);
	Print(head);
}
