#include<iostream>
using namespace std;
//Array will be sorted from right to left
//that is from end to begin
//Worst case when array is reverse sorted and Best Case already sorted
void my_swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void BubbleSort(int *arr,int n){
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++){
     swapped = false;
     for (j = 0; j < n-i-1; j++){
        if (arr[j] > arr[j+1]){
           my_swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
}
void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
int main(){
    int arr[5]={64,25,12,22,11};
    int n=sizeof(arr)/sizeof(*arr);
    BubbleSort(arr,n);
    PrintArray(arr,n);
    return 0;
}
