//Arrange an array in wave form i,e arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …
#include <iostream>
using namespace std;
void swap(int *arr,int x,int y){
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}
void Sort_in_Wave(int *arr,int n){
    for(int i=0;i<n;i+=2){
        if(i>0&&arr[i-1]<arr[i])
            swap(arr,i-1,i);
        if(i<n&&arr[i+1]<arr[i])
            swap(arr,i,i+1);
    }
}
void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
int main() {
	int arr[8] = {10, 5, 6, 3, 2, 20, 100, 80};
	int n=8;
	Sort_in_Wave(arr,n);
	PrintArray(arr,n);
	return 0;
}
