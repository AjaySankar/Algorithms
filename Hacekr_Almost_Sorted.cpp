//https://www.hackerrank.com/challenges/almost-sorted
#include <iostream>
using namespace std;
bool Can_Swaps(int *arr,int n){
    int ditches=0;
    int ditch_index_one=-1;
    int ditch_index_two=-1;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            ditches++;
            ditches==1?ditch_index_one=i: ditch_index_one=ditch_index_one;
            ditches==2?ditch_index_two=i: ditch_index_two=ditch_index_two;
        }
    }
    if(ditches >= 3)
        return false;
    else if(ditches==2){
        if(arr[ditch_index_two+1]<arr[ditch_index_one+1]&&arr[ditch_index_one]>arr[ditch_index_two])
            return true;
        else
            return false;
    }
    else{
        return true;
    }
}
int main() {
    int arr[]={1,5,3,4,2,6,7};
    int n=sizeof(arr)/sizeof(*arr);
    Can_Swaps(arr,n) ? cout << "true" : cout << "false";
	return 0;
}
