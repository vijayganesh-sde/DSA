#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
struct Node *temp = NULL;
struct Node *nex = NULL;
struct Node *head =NULL;
struct Node *first;
void insert(int i){
  struct Node *new;
  new = (struct Node *)malloc(sizeof(struct Node));
  new->data= i;
  new->next = NULL;
  if(head==NULL) head = new;
  else {
    struct Node *temp;
    temp=head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=new;
  }
}
void createLoop(){
  temp=head;
  nex=head->next;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=nex;
}
int loop_check(){
  first=head;
  struct Node *second=head;
  while(first!=NULL && second!=NULL){
    first=first->next;
    second=second->next->next;
    if(first==second){
      return 1;
    }
  }
  return 0;
}

int main(){
  insert(5);
  insert(6);
  insert(7);
  
  createLoop();
  if(loop_check()){
    printf("loop is present at %d",first->data);
  }
}