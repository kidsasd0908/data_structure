#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE = 100;

typedef struct LinkedList_{
    Node* head; 
    Node* current;
    int size; 
}LinkedList;   

typedef struct Node_{
    Node* next;
    int val;
}Node;

LinkedList* initList(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    return list;
}

int append(Node* current, int val){

}

int delete(Node* current){

}

void traverse(Node** head, int idx){//O(n)

}

void testLinkedList(){

}

int main(){
    testLinkedList();
    return; 
}

