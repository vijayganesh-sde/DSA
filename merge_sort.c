#include<stdio.h>
#include<stdlib.h>
int arr[10]={2,32,45,21,67,54,89,38,26,6};
void merge(int arr[],int start,int mid,int end){
  int n1=mid-start+1;
  int n2=end-mid;
  int arr1[n1],arr2[n2];
  for(int i=0;i<n1;i++){
    arr1[i]=arr[start+i];
  }
  for(int j=0;j<n2;j++){
    arr2[j]=arr[mid+1+j];
  }
  
  int i=0;
  int j=0;
  int k=start;
  while(i<n1 && j<n2){
    if(arr1[i]<=arr2[j]){
      arr[k]=arr1[i];
      i++;
    }
    else{
      arr[k]=arr2[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    arr[k]=arr1[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k]=arr2[j];
    j++;
    k++;
  }
}
void merge_sort(int arr[],int l,int r){
  if(l<r){
    int val=l+(r-l)/2;
    merge_sort(arr,l,val);
    merge_sort(arr,val+1,r);
    
    merge(arr,l,val,r);
  }
}
int main(){
  merge_sort(arr,0,9);
  for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
  }
}