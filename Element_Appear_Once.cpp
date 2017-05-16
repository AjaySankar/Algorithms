// This program outputs the element that appears only once in a sorted array on O(logn)

#include <iostream>
using namespace std;
void search_element_once(int *arr,int low,int high){
    if(low==high){
        cout << "The element that appears only once is " << arr[low];
        return;
    }
    if(low<high){
        int mid=(low+high)/2;
        if(mid%2){  //mid is odd
            if(arr[mid]==arr[mid-1])
                search_element_once(arr,mid-2,high);    //Search in right half
            else
                search_element_once(arr,low,mid-1);     //Search in left half
        }
        else{       //mid is even
            if(arr[mid]==arr[mid+1])
                search_element_once(arr,mid+2,high);    //Search in right half
            else
            search_element_once(arr,low,mid) ;        //Search in left half
        }
    }
    else
        return;
}

int main() {
    int arr[] = {1, 1, 2, 4, 4, 5, 5, 6, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    search_element_once(arr, 0, len-1);
    return 0;
}
