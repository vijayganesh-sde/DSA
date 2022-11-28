#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
  char color;
  struct node *parent;
};
struct node *root=NULL;
int height(struct node *N) {
  if (N == NULL)
        return 0;
    else {
        int lDepth = height(N->left);
        int rDepth = height(N->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int max(int a, int b) {
  return (a > b) ? a : b;
}
struct node *rightRotate(struct node *y) {
  struct node *x = y->left;
  struct node *T2 = x->right;
  x->right = y;
  y->left = T2;
  return x;
}

// Left rotate
struct node *leftRotate(struct node *x) {
  struct node *y = x->right;
  struct node *T2 = y->left;

  y->left = x;
  x->right = T2;



  return y;
}
struct node *insert(struct node *root,struct node *n){
    struct node* x = root;
    struct node* y = NULL;
    while (x != NULL) {
        y = x;
        if (n->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL){
        y = n;}
    else if (n->data < y->data){
        y->left = n;
        n->parent=y;}
    else{
        n->parent=y;
        y->right = n;}
    return y;
}
void RBinsert(int val){
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=val;
  new->left=NULL;new->right=NULL;
  new->color='r';new->parent=NULL;
  if(root==NULL){
    root=new;
    new->color='b';
    return;
  }
  insert(root,new);
  printf("%d ",new->parent->data);
  if(new->parent->color=='b'){
    return;
  }
  if(new->parent->data>new->parent->parent->data){
    if(new->parent->parent->left->color=='b' || new->parent->parent->left==NULL){
      new->parent->parent->parent=leftRotate(new->parent->parent);
      new->parent->color='b';
      new->parent->parent->color='r';
    }
    else{
      new->parent->parent->left->color='b';
      new->parent->color='b';
      if(new->parent->parent==root){
        return;
      }
      new->parent->parent->color='r';
    }
  }
  else{
    if(new->parent->parent->right->color=='b' || new->parent->parent->right==NULL){
      new->parent->parent->parent=rightRotate(new->parent->parent);
      new->parent->color='b';
      new->parent->parent->color='r';
    }
    else{
      new->parent->parent->right->color='b';
      new->parent->color='b';
      if(new->parent->parent==root){
        return;
      }
      new->parent->parent->color='r';
    }
  }
}
void inorder(struct node *root){
  if(root==NULL){
    return ;
  }
  inorder(root->left);
  printf("%d %c\n",root->data,root->color);
  inorder(root->right);
}
int main(){
  RBinsert(10);
  RBinsert(6);
  RBinsert(12);
  RBinsert(20);
  RBinsert(2);
  RBinsert(15);
  inorder(root);
  
}