#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int arr[10]={3,5,112,67,56,7,4,8,87,45};
int arr1[10][10];
void insert(int ind,int val){
  int i=0;
  while(arr1[ind][i]!=0){
    i++;
  }
  arr1[ind][i]=val;
}
int main(){
  int k=0;
  while(k<3){
  for (int i=0;i<10;i++){
    float dig=(arr[i]/((int)pow(10,k)));
    int digi=(int)(dig)%((int)pow(10,k+1));

    insert(digi,arr[i]);
  }
  int i=0;
  int j=0;
  while(i<10){
    int p=0;
    while(arr1[j][p]!=0){
      arr[i]=arr1[j][p];
      arr1[j][p]=0;
      i++;
      p++;
    }
    j++;
  }
  k++;}
  for(int i=0; i<10; i++){
    printf("%d ",arr[i]);
  }
  
}