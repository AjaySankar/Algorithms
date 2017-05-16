// An inversion is a pair (arr[i],arr[j]) such that if arr[i] > arr[j] then i < j
//The number of inversion define how close the array is to sortedness
/* Suppose we know the number of inversions in the left half and right half of the array (let be inv1 and inv2), 
what kinds of inversions are not accounted for in Inv1 + Inv2? The answer is – the inversions we have to count during the merge step. 
Therefore, to get number of inversions, we need to add number of inversions in left subarray, right subarray and merge().
In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), 
if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, 
so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]. */

#include <iostream>
using namespace std;
int MergeSort(int *arr,int *temp,int low,int high);
int Merge(int *arr,int *temp,int low,int mid,int high);
void PrintArray(int *arr,int len){
    for(int i=0;i<len;i++)
        cout << arr[i] << " ";
}
void _mergeSort(int *arr,int n){
    int *temp=(int*)malloc(n*sizeof(int));
    cout << "The number of inversions are " << MergeSort(arr,temp,0,n-1) << endl;
}
int Merge(int *arr,int *temp,int low,int mid,int high){
    int inv_count=0;
    int i=low;
    int j=mid;
    int k=low;
    while(i<=mid-1&&j<=high){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv_count+=(mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=high)
        temp[k++]=arr[j++];
    for(int i=low;i<=high;i++)
        arr[i]=temp[i];
    return inv_count;
}
int MergeSort(int *arr,int *temp,int low,int high){
    int inv_count=0;
    if(low<high){
        int mid=(low+high)/2;
        inv_count=MergeSort(arr,temp,low,mid);      // inversions in left half of array
        inv_count+=MergeSort(arr,temp,mid+1,high);  // inversions in right half of array
        inv_count+=Merge(arr,temp,low,mid+1,high);  // inversions after merging two arrays
    }
    return inv_count;
}
int main() {
    int arr[5]={1, 20, 6, 4, 5};
    int size=sizeof(arr)/sizeof(*arr);
    _mergeSort(arr,size);
    PrintArray(arr,size);
	return 0;
}
