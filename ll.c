#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
struct Node *head =NULL;
void insertposn(int i){
  struct Node *new;
  struct Node* curr;
  curr=head;
  new=(struct Node *)malloc(sizeof(struct Node));
  new->data=i;
  new->next=NULL;
  int n;
  scanf("%d",&n);
  int count=1;
  while(count!=n-1 && curr->next!=NULL){
    curr=curr->next;
    count++;
  }
  new->next=curr->next;
  curr->next=new;
}
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
void display(){
  struct Node *temp;
  temp=head;
  while(temp!=NULL){
    printf("%d->",temp->data);
   
    temp=temp->next;
  }
}
int  main(){
  printf("%p ",&head);
  insert(5);
  insert(6);
  insert(7);
  insertposn(4);
  display();
}
