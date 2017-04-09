#include<stdio.h>
#include<iostream>
using namespace std;
int LinearSearch(int *arr,int n,int to_find){
    for(int i=0;i<n;i++){
        if(arr[i]==to_find)
            return i;
    }
    return -1;
}
int main(){
    int arr[5]={3,2,1,4,5};
    int to_find=7;
    int n=sizeof(arr)/sizeof(*arr);
    int index=LinearSearch(arr,n,to_find);
    if(index!=-1)
        cout << "The number is found at " << index+1 << "th position";
    else
        cout << "The element is not found";
    return 0;
}
