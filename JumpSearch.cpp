/*
Works only sorted arrays.
The optimal size of a block to be jumped is O(√ n). This makes the time complexity of Jump Search O(√ n).
The time complexity of Jump Search is between Linear Search ( ( O(n) ) and Binary Search ( O (Log n) ).
Binary Search is better than Jump Search, but
Jump search has an advantage that we traverse back only once
(Binary Search may require up to O(Log n) jumps, consider a situation where the
 element to be search is the smallest element or smaller than the smallest).
So in a systems where jumping back is costly, we use Jump Search.*/
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int JumpSearch(int *arr,int n,int x){
    int step=sqrt(n);
    int index;
    for(int i=0;i<n;i=i+step){
        if(arr[i]==x)
            return i;
        if(arr[i]<x&&arr[i+step]>x){
            index=i;
            break;
        }
    }
    for(int i=index;i<n;i++){
        if(arr[i]==x)
            return i;
    }
    return -1;
}
int main(){
    int arr[16]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n=sizeof(arr)/sizeof(*arr);
    int x=610;
    int index=JumpSearch(arr,n,x);
    if(index!=-1)
        cout << "The element is found at: " << index+1;
    else
        cout << "The element is not found";
    return 0;
}
