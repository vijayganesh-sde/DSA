#include<stdio.h>
#include<stdlib.h>
struct vertex{
  char data;
  int visited;
};
int vercount=0;
int Qcount=0;
int Q[10];
int adjMAx[10][10];
int front=0;
int rear=-1;
struct vertex *listVert[10];
void addEdge(int start,int end){
  adjMAx[start][end]=1;
  adjMAx[end][start]=1;
}
void addVertex(char s){
  struct vertex *new=(struct vertex *)malloc(sizeof(struct vertex));
  new->data=s;
  new->visited=0;
  listVert[vercount++]=new;
}
void insert(int data){
  Q[++rear]=data;
  Qcount++;
}
int delete(){
  Qcount--;
  return Q[front++];
}
void displayvertex(int ind){
  printf("%c ",listVert[ind]->data);
}
void bfs(){
  listVert[0]->visited=1;
  displayvertex(0);
  insert(0);
  while(Qcount!=0){
    int temp=delete();
    for(int i=0;i<vercount;i++){
      if(adjMAx[temp][i]==0 &&listVert[i]->visited==0){
        listVert[i]->visited=1;
        displayvertex(i);
        insert(i);
      }
    }
  }
  for(int i=0;i<vercount;i++){
    listVert[i]->visited=0;
  }
}
int main(){
  printf("%d",adjMAx[0][5]);
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
  bfs();
}