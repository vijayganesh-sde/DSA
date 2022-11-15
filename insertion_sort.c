#include<stdio.h>
#include<stdlib.h>
int arr[10]={2,44,4,8,48,3,12,5,90,15};
void swap(int a, int b){
  int temp=arr[a];
  arr[a]=arr[b];
  arr[b]=temp;
}
void insertion_sort(){
  for(int i=1;i<10;i++){
    for(int j=i-1;j>=0;j--){
      if(arr[j+1]<arr[j]){
        swap(j+1,j);
      }
    }
  }
}
int main(){
  insertion_sort();
  for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
  }
}