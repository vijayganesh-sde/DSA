#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int arr[10];
int hash(int key){
  return key%10;
}
void insert(int val){
  int hashkey=hash(val);
  int i=1;
  while(arr[hashkey]!=0){
    hashkey=(hashkey+(int)pow(i,2))%10;
    i++;
  }
  arr[hashkey]=val;
}
void delete(int val){
  int hashkey=hash(val);
  int i=1;
  while(arr[hashkey]!=val){
    hashkey=(hashkey+(int)pow(i,2))%10;
    i++;
  }
  arr[hashkey]=0;
}
void search(int val){
  int hashkey=hash(val);
  int c=0;
  while(arr[hashkey]!=val){
    hashkey=(hashkey+(int)pow((c+1),2))%10;
    c++;
    if(c==10){
      printf("Not Found\n");
      return;
    }
  }
  printf("found at %d position\n",hashkey+1);
}
void display(){
  for(int val=0;val<10;val++){
    printf("%d ",arr[val]);
  }
}
int main(){
  insert(10);
  insert(30);
  insert(120);
  insert(25);
  insert(45);
  insert(77);
  insert(89);
  insert(99);
  display();
  printf("\n");
  delete(120);
  display();
  printf("\n");
  search(99);
}