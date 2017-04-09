#include<iostream>>
#include<algorithm>
#include<vector>
/*
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.
*/
using namespace std;
void BucketSort(int *arr,int n){
    int max_ele=arr[0];
    for(int i=0;i<n;i++){
        if(max_ele<arr[i])
            max_ele=arr[i];
    }
    int no_of_buckets=max_ele/10;
    vector<int>buckets[no_of_buckets+1];
    for(int i=0;i<n;i++){
        int bi=arr[i]/10;
        buckets[bi].push_back(arr[i]);
    }
    int k=0;
    for(int i=0;i<n;i++)
        sort(buckets[i].begin(),buckets[i].end());
    for(int i=0;i<no_of_buckets+1;i++){
        for(int j=0;j<buckets[i].size();j++)
            arr[k++]=buckets[i][j];
    }
}
void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
int main(){
    int arr[7]={64,25,12,99,22,11,4};
    int n=sizeof(arr)/sizeof(*arr);
    BucketSort(arr,n);
    PrintArray(arr,n);
    return 0;
}
