#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;  // pointer to head
void Print(){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Incert(int data, int n){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1){
        // head => temp1 +> 1st node
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;  // start at head
    for (int i; i<n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

int main(){
    head = NULL;
    Incert(2, 1);  // list: 2
    Incert(3, 2);  // list: 2, 3
    Incert(4, 1);  // list: 4, 2, 3
    Incert(5, 2);  // list: 4, 5, 2, 3
    Print();
}
