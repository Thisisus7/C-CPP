#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
};
struct Node* head;  // global variable, pointer to head node.

// avoid duplicate code in insert_head and insert_tail.
Node* get_new_node(int x){  
	/*  This won't work, because although we return the address, the value in that address will be cleared after 
	    get_new_code function is finished.
	struct Node new_node;  store in stack
	new_node->data = x;
	new_node->prev = NULL;
	new_node->next = NULL;
	return &new_node;
	 */
	Node* new_node = new Node();  // local variable, store in heap;
	new_node->data = x;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
	delete new_node;
}

void insert_head(int x){
	Node* new_node = get_new_node(x);  // local variable;
	if (head == NULL){
		head = new_node;
		return;
	}
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
}

void reverse_print(){
	Node* temp = head;
	if (temp == NULL) return;
	// going to last node
	while (temp->next != NULL){
		temp = temp->next;
	}
	// traversing back using prev pointer
	std::cout << "Reverse: ";
	while (temp != NULL){
		std::cout << temp->data << " ";
		temp = temp -> prev;
	}
	std::cout << "\n";
}

void print(){
	Node* temp = head;
	std::cout << "Forward ";
	while (temp != NULL){
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

int main(){
	head = NULL;
	insert_head(2); print(); reverse_print();	
	insert_head(4); print(); reverse_print();	
	insert_head(6); print(); reverse_print();	
}
