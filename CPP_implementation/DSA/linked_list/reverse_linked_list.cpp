#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;	

Node* Incert(struct Node* head, int data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;

	head = temp;
	return head;
}

void Print(Node* head){
	struct Node* temp = head;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	printf("\n");
}

struct Node* Reverse(struct Node* head){
	struct 	Node *current, *prev, *next;
	current = head;
	prev = NULL;  // track the previous variable.
	while (current != NULL){
		next = current->next;  // save the address of next node, or we'll loss the address.
		current->next = prev;   //*(current).next
		prev = current;  // reset prev pointer to the next node,
		current = next;  // reset current pointer to the next node;
	}
	head = prev;
	return head;
}

int main(){
	struct Node* head = NULL;
	head = Incert(head, 2);
	head = Incert(head, 4);
	head = Incert(head, 6);
	head = Incert(head, 8);
	Print(head);
	head = Reverse(head);
	Print(head);

	return 0;
}
