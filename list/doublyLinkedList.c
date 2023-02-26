#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE = 100;

typedef struct Node_{
    struct Node_* next;
    struct Node_* prev;
    int val;
}Node;

typedef struct LinkedList_{
    Node* head; 
    Node* tail;
    int size; 
}LinkedList;   

/************
 * 리스트 생성 
 ************/
LinkedList* makeList(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL; 
    list->tail = NULL;
    list->size = 0;
    return list;
}

 void deleteList(LinkedList* list){

    Node* curr = list->head; 
    Node* temp; 

    while(curr != NULL){
        temp = curr; 
        free(temp);
        curr++;         
    }

 }

/************
 * 노드 삽입
 ************/
int append(LinkedList* list, int val){

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> val = val; 

    if(list->head == NULL){ //최초 입력시
        list->head = newNode;
        list->tail = newNode;
        list->size = 1;
    }else{
        Node* tmp = list->tail; 

        list->tail += 1;
        list->tail = newNode; 
        list->tail -> prev = tmp;    
        tmp->next = list->tail;

        (list->size)++;
    }
}
/************
 * 노드 수정
 ************/
int addNode(LinkedList* list, int idx, int val){

    if(list->size < idx++){
        printf("list out of bound!! >>> \n");
        return -1; 
    }

    Node* curr = list->head; 
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> val = val;

    while(--idx){
        curr = curr->next;
    }

    curr->prev->next = newNode; 
    newNode->next = curr;  
    curr->prev = newNode; 
}

/************
 * 첫번째 노드 삭제
 ************/
int deleteFirst(LinkedList* list){
    if(list->head != NULL){
        Node* tmp = list->head; 
        list->head = list->head->next;
        free(tmp);
        return 1; 
    }else{
        printf("list is empty >> \n");
        return -1;
    }
}

int delete(LinkedList* list, int idx){

    if(list->size < idx++){
        printf("list out of bound!! >>> \n");
        return -1; 
    }

    if(idx == 1){
        return deleteFirst(list);
    }

    Node* curr = list->head; 

    while(--idx){
        curr = curr->next;
    }

    curr->prev->next =curr->next;
    curr->next->prev =curr->prev;

    free(curr);

    return 1; 
}

/************
 * 리스트 순회
 ************/
void traverse(LinkedList* list){//O(n)

    int idx = 0;
    Node* curr = list->head; 
   
    while(curr != list->tail){
        printf("list idx >> %d , val >> %d \n", idx++, curr->val);
        curr = curr->next;
    }

}


/************
 * 리스트 테스트
 ************/
void testLinkedList(){
    LinkedList* list = makeList();

    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);

    printf("works fine>\n"); 
    traverse(list);

    delete(list,2);   

    traverse(list);
}


int main(){
    testLinkedList();
    return 0; 
}

