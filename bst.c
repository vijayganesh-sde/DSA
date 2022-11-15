#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};
struct TreeNode *root=NULL;
struct TreeNode *temp;
struct TreeNode * insert(struct TreeNode *root,int i){
  struct TreeNode *new;
  new=(struct TreeNode *)malloc(sizeof(struct TreeNode));
  new->data=i;
  new->left=new->right=NULL;
  if(root==NULL){
    return new;
  }
  if(i<root->data){
    root->left=insert(root->left,i);
  }
  else{
    root->right=insert(root->right,i);
  }
  return root;
}
void search(struct TreeNode *root){
  int value=50;
  if(value==root->data){
    printf("FOund\n");
    return;
  }
  if(root->left==NULL || root->right==NULL){
    printf("nOt found\n");
    return;
  }
  if(value<root->data){
    search(root->left);
  }
  else{
    search(root->right);
  }
}
void search_1(int value){
  if(value==root->data){
    printf("Found\n");
    return;
  }
  if(root->left==NULL || root->right==NULL){
    printf("nOt found\n");
    return;
  }
  if(value<root->data){
    root=root->left;
    search_1(value);
  }
  else{
    root=root->right;
    search_1(value);
  }
}
void postorder(struct TreeNode *root){
  if(root==NULL){
    return ;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}
void inorder(struct TreeNode *root){
  if(root==NULL){
    return ;
  }
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
void preorder(struct TreeNode *root){
  if(root==NULL){
    return ;
  }
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
struct TreeNode *inOrderSucc(struct TreeNode *root){
  if(root->left==NULL){
    
  }
  while(root->left->left!=NULL){
    root=root->left;
  }
  return root;
}
void delete(int val){
  struct TreeNode *parent;
  struct TreeNode *grandparent;
  struct TreeNode *temp=root;
  if(temp==NULL){
    return;
  }
  while(temp!=NULL){
    if(temp->data==val){
      /*No child condition*/
      if(temp->right==NULL && temp->left==NULL){
        if(temp->data>parent->data){
        parent->right=NULL;
        printf("%d %d\n",parent->data,temp->data);
        return;
        }
        else{
          parent->left=NULL;
          printf("%d %d\n",parent->data,temp->data);
          return;
        }
      }
      /*single child condition*/
      if(temp->right==NULL){
        temp->data=temp->left->data;
        temp->left=NULL;
        return;
      }
      if(temp->left==NULL){
        temp->data=temp->right->data;
        temp->right=NULL;
        return;
      }
      /*Two children condition*/
      struct TreeNode *successor=inOrderSucc(temp->right);
      if(successor->left->right==NULL){
        temp->data=successor->left->data;
        successor->left=NULL;
      }
      else{
        temp->data=successor->left->right->data;
        successor->left->right=NULL;
      }
      return;
    }
    if(temp->data<val){
      /*if(temp->right->left->data==val || temp->right->right->data==val){
        grandparent=temp;
        parent=temp->right;
      }*/
      if(temp->right->data==val){
        parent=temp;
      }
      temp=temp->right;
    }
    if(temp->data>val){
      /*if(temp->left->left->data==val || temp->left->right->data==val){
        grandparent=temp;
        parent=temp->left;
      }*/
      if(temp->left->data==val){
        parent=temp;
        
      }
      temp=temp->left;
    }
  }  
}
int maxDepth(struct TreeNode* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
struct TreeNode *inordSucc(struct TreeNode *root){
  while(root->left!=NULL){
    root=root->left;
  }
  return root;
}
struct TreeNode* deletion(int val,struct TreeNode *root){
  struct TreeNode *parent;
  struct TreeNode *grandparent;
  struct TreeNode *succ;
  if(root==NULL){
    return root;
  }
  if(root->data==val){
    if(root->right==NULL && root->left==NULL){
      free(root);
      return NULL;
    }
    
    if(root->right==NULL){
      root->data=root->left->data;
      root->left=deletion(root->left->data,root->left);
      return root;
    }
    if(root->left==NULL){
      root->data=root->right->data;
      root->right=deletion(root->right->data,root->right);
      return root;
    }
    succ=inordSucc(root->right);
    root->data=succ->data;
    root->right=deletion(succ->data,root->right);
    return root;
  }
  if(root->data<val){
    if(root->right->data==val){
        parent=root;
      }
    root->right=deletion(val,root->right);
  }
  if(root->data>val){
    if(root->left->data==val){
        parent=root;
      }
    root->left=deletion(val,root->left);
  }
  return root;
}
int main(){
  root=insert(root,20);
  insert(root,30);
  insert(root,10);
  insert(root,15);
  insert(root,5);
  insert(root,25);
  insert(root,35);
  insert(root,28);
  insert(root,26);
  search(root);
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  deletion(30,root);
  inorder(root);
  printf("\n%d ",maxDepth(root));
}