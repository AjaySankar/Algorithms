#include <iostream>
using namespace std;
#define MAX 10
//MAX defines the range of elements in the array 0 to MAX-1
void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
void CountSort(int *arr,int n){
    int count[MAX];
    for(int i=0;i<MAX;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[arr[i]]++;
    for(int i=1;i<MAX;i++)
        count[i]=count[i]+count[i-1];
    int sorted_arry[n];
    for(int i=0;i<n;i++){
        int pos=count[arr[i]];
        sorted_arry[pos-1]=arr[i];
        count[arr[i]]--;
    }
}
int main() {
	int arr[]={1, 4, 1, 2, 7, 5, 2};
	int n=sizeof(arr)/sizeof(*arr);
	CountSort(arr,n);
	PrintArray(sorted_arry,n);
	return 0;
}
