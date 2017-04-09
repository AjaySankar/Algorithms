#include <iostream>
using namespace std;
int BinarySearch(int *arr,int low,int high,int x){
    if(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            return BinarySearch(arr,low,mid-1,x);
        else
            return BinarySearch(arr,mid+1,high,x);
    }
    return -1;
}
int ExponentialSearch(int *arr,int n,int x){
    int arr_size=1;
    while(arr_size<n&&arr[arr_size-1]<x)
            arr_size=arr_size*2;
    return BinarySearch(arr,(arr_size-1)/2,min(arr_size-1,n),x);
}
int main() {
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int x=9;
	int n=sizeof(arr)/sizeof(*arr);
	int index=ExponentialSearch(arr,n,x);
	if(index!=-1)
	    cout << "The element is found at " << index+1;
	else
	    cout << "The element is not found";
	return 0;
}

