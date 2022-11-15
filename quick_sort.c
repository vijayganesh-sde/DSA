#include<stdio.h>
#include<stdlib.h>
int arr[10]={19,5,12,45,23,1,67,43,21,90};
void swap(int a, int b){
  int temp=a;
  a=b;
  b=temp;
}
void divide(int arr[],int l,int r){
  if(l==r){
    return;
  }
  int l_temp=l;
  int r_temp=r;
  int pivot=arr[l];
  while(l!=r){
    if(arr[l]==pivot){
      if(arr[r]<pivot){
        int temp=arr[r];
        arr[r]=arr[l];
        arr[l]=temp;
        pivot=arr[r];
      }
      else{
        r--;
      }
    }
    else {
      if(arr[l]>pivot){
        int temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        pivot=arr[l];
      }
      else{
        l++;
      }
    }
  }
  if(l-1>=l_temp) divide(arr,l_temp,l-1);
  if(r_temp>=r+1) divide(arr,r+1,r_temp);
}
int main(){
  divide(arr,0,9);
  for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
  }
}