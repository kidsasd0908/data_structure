/**
* arraylist 구현
* 일반적인 타입에 대한 ArrayList를 구현한다.
**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 

typedef struct ArrayList_{

  int size; 
  int arr[100];

}ArrayList;  

ArrayList* initArrayList(){//return type is *ArrayLIst 
  ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
  list->size = 0;
  return list;
}

void append(ArrayList* list, int val){
  if(list->size == MAX_LIST_SIZE){ printf("ERROR : MAX SIZE ! \n"); } //array out of bound
  else{
    *( list->arr + list->size ) = val; //O(1)
    ++(list->size);
  }
}

void iterator(ArrayList* list){
  printf("[");
  for(int i=0; i< list->size; i++){
    printf("%d, ", *(list->arr + i));
  }
  printf("]\n");
}

void testArrayList(){
  //init arraylist
  ArrayList* list = initArrayList(); 
 
  //append elements 
  //append(list, 5);
  //append(list, 7);
  
  //max size error test (edge case)
  for(int i=0; i<MAX_LIST_SIZE + 30; i++){
     append(list, i);
  }

  //interate elements
  iterator(list);
}

int main(){
  testArrayList();
} 





