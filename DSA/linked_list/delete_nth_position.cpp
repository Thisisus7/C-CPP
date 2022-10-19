#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;  // global variale: a pointer to node, will store the address of head node
// insert an int at the end of list
void Insert(int data){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    Node* temp2 = head;

    if (temp2 == NULL){
        head = temp1;
        return;
    }
    while (temp2->next != NULL){  //temp2->next !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

// print all elementss
void Print(){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// deleter nth nodes
void Delete(int n){
    struct Node* temp1 = head;  // temporary variable
    // 1) delete the 1st ndoe
    if (n == 1){
        head = temp1->next;  // head points to second node
        free(temp1);
        return;
    }
    // 2) delete nth node
    for (int i=0; i<n-2; i++){  // go to (n-1)th node
        temp1 = temp1->next;
    }
    struct Node* temp2 = temp1->next;  // nth node
    temp1->next = temp2->next;  // (n+1)th node
    free(temp2);  // delete temp2
    // 3) deleter last node
}

int main(){
    head = NULL;  // empty linked list, head = 0
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);  // list = 2, 4, 6, 5
    Print();
    int n;
    printf("Enter a position\n");
    scanf("%d", &n);
    Delete(n);
    Print();

}
