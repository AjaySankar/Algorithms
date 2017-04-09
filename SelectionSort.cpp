#include<iostream>
using namespace std;
void my_swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index])
                min_index=j;
        }
        my_swap(&arr[i],&arr[min_index]);
    }
}
void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
int main(){
    int arr[5]={64,25,12,22,11};
    int n=sizeof(arr)/sizeof(*arr);
    SelectionSort(arr,n);
    PrintArray(arr,n);
    return 0;
}
