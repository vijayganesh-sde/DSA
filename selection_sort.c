#include<stdio.h>
#include<stdlib.h>
int arr[10]={2,5,12,45,23,1,67,43,21,9};
void swap(int a, int b){
  int temp=arr[a];
  arr[a]=arr[b];
  arr[b]=temp;
}
int minimum(int start,int end){
  int minind=start;
  for (int i=start;i<=end;i++){
    if(arr[i]<arr[minind]){
      minind=i;
    }
  }
  return minind;
}
int main(){
  for (int i=0;i<9;i++){
    int key=arr[i];
    int min_ind=minimum(i+1,9);
    if(arr[i]>arr[min_ind]){
      swap(i,min_ind);
    }
  }
  for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
  }
}
