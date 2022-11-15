#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
struct Node *head =NULL;
void insert_begin(int i){
  struct Node *temp=NULL;
  struct Node *new = NULL;
  temp=head;
  new=(struct Node *)malloc(sizeof(struct Node));
  new->data=i;
  new->next=NULL;
  if(head==NULL){
    head=new;
    new->next=new;
  }
  else{
    new->next=head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=new;
    head=new;
  }
  printf("%d",new->data);
}
int main(){
  insert_begin(8);
  insert_begin(9);
  insert_begin(10);
  
}