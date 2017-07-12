/* Divide the array into two equal halves.
   if array contains only one element then
     then it is both min and max
   else if array contains two elements
     then compare them to get min and max
   else
     Get the minimum and maximum from left array
     Get the minimum and maximum from right aray
     Compare the minimums from left and right arrays to get minimum of combined array.
     Compare the maximums from left and right arrays to get maximum of combined array
    
    T(n)=2T(n/2)+2
    T(n/2) for left and T(n/2) for right and '2' to compare minimums and maximums from left and right arrays.
     3/2n -2 comparisons.
*/

#include <stdio.h>
#include <iostream>
using namespace std;
void Min_Max(int *arr,int low,int high,int *min,int *max){
    if(low==high){
        *min=arr[low];*max=arr[high];
        return;
    }
    else if(high-low==1){
        if(arr[low]<arr[high]){
            *min=arr[low];
            *max=arr[high];
        }
        return;
    }
    int mid=(low+high)/2;
    int left_min;int left_max;
    int right_min;int right_max;
    Min_Max(arr,0,mid,&left_min,&left_max);
    Min_Max(arr,mid+1,high,&right_min,&right_max);
    if(left_min<right_min)
        *min=left_min;
    else
        *min=right_min;
    if(left_max>right_max)
        *max=left_max;
    else
        *max=right_max;
}
int main() {
    int arr[6]={10,11,45,1,33,28};
    int min,max;
    Min_Max(arr,0,5,&min,&max);
    cout << min << " " << max;
	return 0;
}
