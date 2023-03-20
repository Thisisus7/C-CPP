#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    Node* link;  // C: struct Node* link;
};

int main(){
    // create a pointer to node named A, points nowhere
    Node* A = NULL;  // empty list
    // insert a node in this list
    Node* temp = new Node(); // C: (Node*)malloc(sizeof(Node));
    // fill in data and link in this particular node
    temp->data = 2; // C: (*temp).data = 2;
    temp->link = NULL; // C: (*temp).link = NULL;
    // write the address of the newly created node in A
    A = temp;

    // temp stores the address of new node
    temp = new Node(); // temp now store the address of the new node
    temp->data = 4;
    temp->link = NULL;

    // write the address of the newly created node into the address field of the last node
    Node* temp1 = A;  // initially point to the head node
    while (temp1->link != NULL){  // traverse
        temp1 = temp1->link;  // get to the next node
        printf("%d", temp->data);
    }
    temp1->link = temp;
}
