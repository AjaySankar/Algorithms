/*This program does binary search over a sorted array*/
#include<stdio.h>
#include<iostream>
using namespace std;
int BinarySearch(int *arr,int l,int r,int to_find){
    if(r>=l){
        int mid=l+(r-l)/2;
        if(arr[mid]==to_find)
            return mid;
        if(arr[mid]>to_find)
            return BinarySearch(arr,l,mid-1,to_find);
        else
            return BinarySearch(arr,mid+1,r,to_find);
    }
    return -1;
}
int main(){
    int arr[5]={1,2,3,4,5};
    int x=1;
    int n=sizeof(arr)/sizeof(*arr);
    int index=BinarySearch(arr,0,n-1,x);
    if(index!=-1)
        cout << "The number is found at " << index+1 << "th position";
    else
        cout << "The element is not found";
    return 0;
}
