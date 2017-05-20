#include <iostream>
using namespace std;
#define MAX 10
//MAX defines the range of elements in the array 0 to MAX-1
void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
void CountSort(int *arr,int n,int exp){
    int count[MAX];
    for(int i=0;i<MAX;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;
    for(int i=1;i<MAX;i++)
        count[i]=count[i]+count[i-1];
    int sorted_arry[n];
    for(int i=0;i<n;i++){
        int pos=count[(arr[i]/exp)%10];
        sorted_arry[pos-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=sorted_arry[i];
}
int getMax(int *arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
void RadixSort(int *arr,int n){
    int max=getMax(arr,n);
    for(int exp=1;max/exp>0;exp=exp*10)
        CountSort(arr,n,exp);
}
int main() {
	int arr[]={1, 4, 1, 2, 7, 5, 2};
	int n=sizeof(arr)/sizeof(*arr);
	RadixSort(arr,n);
	PrintArray(arr,n);
	return 0;
}
