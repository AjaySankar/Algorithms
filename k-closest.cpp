//Find the k-closest values to an element in a sorted array
#include <iostream>
using namespace std;
int Binary_Search(int *arr,int low,int high,int x){
    int mid=low+(high-low)/2;
    if(arr[mid]==x)
        return mid;
    else if(arr[mid]>x)
        return Binary_Search(arr,low,mid-1,x);
    else
        return Binary_Search(arr,mid+1,high,x);
    return -1;
}
void find_k_closest_elements(int *arr,int n,int k,int x){
    int index=Binary_Search(arr,0,n-1,x);
    int left=index-1;
    int right=index+1;
    int count=0;
    while(count<k&&left>=0&&right<=n-1){
        if(arr[index]-arr[left]<arr[right]-arr[index])
            cout << arr[left--] << " ";
        else
            cout << arr[right++] << " ";
        count++;
    }
    while(count<k&&left>=0){
        cout << arr[left--] << " ";
        count++;
    }
    while(count<k&&right<=n-1){
        cout << arr[right++] << " ";
        count++;
    }
}
int main() {
    int arr[13]= {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k=4;
    int x=35;
    find_k_closest_elements(arr,13,k,x);
	return 0;
}
