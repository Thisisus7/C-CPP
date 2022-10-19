#include <iostream>
#define MAX_SIZE 101

class queue{
	private:
		int A[MAX_SIZE];
		int front, rear;	
	public:
		// initialization
		queue(){
			front = -1;
			rear = -1;
		}
		// return elements at the front of queue
		int Front(){
			if (front == -1){
				std::cout << "Error: cannot return front from empty queue" << std::endl;
				return -1;
			}
			return A[front];
		}
		void Enqueue(int x){
			std::cout << "Enqueuing " << x << std::endl;
			if (is_full()){
				std::cout << "Error: Queue is full" << std::endl;
				return;
			}
			if (is_empty()){
				front = rear = 0;
			}
			else{
				// circular array: if rear = 100, (rear + 1) % MAX_SIZE = 0; 
				rear = (rear+1) % MAX_SIZE;
			}
			A[rear] = x;
				
		}
		void Dequeue(){
			std::cout << "Dequeuing " << std::endl;
			// check -1
			if (is_empty()){
				std::cout << "Error: Queue is empty" << std::endl;
				return;
			}
			// check equal
			else if (front == rear){
				front = rear = -1;
			}
			else{
				front = (front+1) % MAX_SIZE;
			}
		}
		bool is_empty(){
			return (front == -1 && rear == -1);
		}
		// rear == size(A) - 1
		bool is_full(){
			return (rear+1) % MAX_SIZE == front ? true:false;
		}
		void Print(){
			int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
			std::cout << "Queue: ";
			for (int i=0; i<count; i++){
				int idx = (front + i) % MAX_SIZE; // traversing circularly from front
				std::cout << A[idx] << " ";
			}
			std::cout << std::endl;
		}
};

int main(){
	queue Q;
	Q.Enqueue(2); Q.Print();
	Q.Enqueue(4); Q.Print();
	Q.Enqueue(6); Q.Print();
	Q.Dequeue(); Q.Print();
	Q.Enqueue(8); Q.Print();
}
