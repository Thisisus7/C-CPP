#include <stdlib.h>
#include <stdio.h>
// C program
struct Node{
    int data;
    struct Node* next;  // C++: Node* next
};
struct Node* head;  // head node(global variable)

void print(){
    struct Node* temp = head; // C: struct
    printf("List is: ");
    while (temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insert(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node));
    (*temp).data = x;  // c++: temp->data = x
    (*temp).next = NULL;
    if (head != NULL) temp->next = head;  // temp points to the ist data node
    head = temp;  // head points to temp
}

int main(){
    // Node* head = NULL; local variable
    head = NULL;  // empty list: the head node initially points nowhere
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        printf("Enter the number\n");
        scanf("%d", &x);
        insert(x);
        print();
    }
}
