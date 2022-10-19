#include <iostream>

class Queue{
	private:
		struct Node{
			int data;
			struct Node* next;	
		};
		struct Node* front;
		struct Node* rear;
	public:
		Queue(){
			front = NULL;
			rear = NULL; 	
		}
		void Enqueue(int x){
			// create a temp node 
			Node* temp = new Node();
			temp->data = x;
			temp->next = NULL;
			// if queue is empty, 1st temp
			if (front == NULL && rear == NULL){
				front = rear = temp;
				return;
			}
			// if queue is not empty, 2nd - ... temp
			rear->next = temp;  // link current linked list to new node(temp)
			rear = temp;  // move rear 
		}			
		void Dequeue(){
			Node* temp = front;
			if (front == NULL) return;
			if (front == rear) front = rear = NULL;
			else front = front->next;  // front point to the next node
			free(temp); // delete the node we should dequeue
		}
		void Print() {
			Node* temp = front;
			while(temp != NULL) {
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
};

int main(){
	Queue Q;
	Q.Enqueue(2); Q.Print(); 
	Q.Enqueue(4); Q.Print();
	Q.Enqueue(6); Q.Print();
	Q.Dequeue();  Q.Print();
	Q.Enqueue(8); Q.Print();
}
