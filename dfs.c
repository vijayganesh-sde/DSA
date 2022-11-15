#include<stdio.h>
#include<stdlib.h>
struct vertex{
  char data;
  int visited;
};
struct vertex *listVert[10];
char stack[10];
int stackcount=0;
int vertcount=0;
int adjMax[10][10];
void addVertex(char c){
  struct vertex *new;
  new=(struct vertex *)malloc(sizeof(struct vertex));
  new->data=c;
  new->visited=0;
  listVert[vertcount++]=new;
}
void addEdge(int start, int end){
  adjMax[start][end]=1;
  adjMax[end][start]=1;
}
void dfs(){
  stack[stackcount++]=listVert[0]->data;
  listVert[0]->visited=1;
  printf("%c ",listVert[0]->data);
  while(stackcount!=0){
    int temp=stackcount-1;
    int check=0;
    for(int i=0;i<vertcount;i++){
      if(listVert[i]->visited==0 && adjMax[temp][i]==1){
        stack[stackcount++]=listVert[i]->data;
        listVert[i]->visited=1;
        check=1;
        printf("%c ",listVert[i]->data);
      }
    }
    if(check==0){
      stackcount--;
    }
  }
  
}
int main(){
  addVertex('a');
  addVertex('b');
  addVertex('c');
  addVertex('d');
  addVertex('e');
  addEdge(0,1);
  addEdge(0,2);
  addEdge(0,3);
  addEdge(3,4);
  addEdge(2,4);
  dfs();
}