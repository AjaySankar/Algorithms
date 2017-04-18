// This program counts the number of ones in a given sorted array in O(logn)

#include <iostream>
using namespace std;
int Count_Ones(int *arr,int low,int high){
    int mid=low+(high-low)/2;
    if(arr[mid]==1&&arr[mid+1]==0)
        return mid;
    if(arr[mid]==1&&arr[mid+1]==1)
        return Count_Ones(arr,mid+1,high);
    if(arr[mid]==0)
        return Count_Ones(arr,low,mid-1);
    return -1;
}
int main() {
	int arr[9]={0,0,0,0,0,0,0,0,0};
	int n=sizeof(arr)/sizeof(*arr);
	if(arr[0]==0)
	    cout << "The number of ones in the array are: 0"; 
	else if(arr[n-1]==1)
	    cout << "The number of ones in the array are: " << n; 
	else
	    cout << "The number of ones in the array are: " << Count_Ones(arr,0,n-1)+1;
	return 0;
}
