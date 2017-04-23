  //This program outputs the pair in an array whose sum 
  //is equal to a given value
  //Method 1 : By Sorting --- TimeComplexity : O(nlogn) for sorting and O(n) for pair search, Space Complexity : O(1)
  //Method 2:  By Hashing --- TimeComplexity : O(n) , Space Complexity : O(N) where N is the max value in the array.
  
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000
void findTriplets(int arr[], int n)
{
    bool found = false;
 
    // sort array elements
    sort(arr, arr+n);
 
    for (int i=0; i<n-2; i++)
    {
        // initialize left and right
        int l = i + 1;
        int r = n - 1;
        int x = arr[i];
        while (l < r)
        {
            if (x + arr[l] + arr[r] == 0)
            {
                // print elements if it's sum is zero
                printf("%d %d %d\n", x, arr[l], arr[r]);
                l++;
                r--;
                found = true;
            }
 
            // If sum of three elements is less
            // than zero then increment in left
            else if (x + arr[l] + arr[r] < 0)
                l++;
 
            // if sum is greater than zero than
            // decrement in right side
            else
                r--;
        }
    }
 
    if (found == false)
        cout << " No Triplet Found" << endl;
}
void FindPairBySorting(int *arr,int n,int sum){
    int l=0;
    int r=n-1;
    while(l<r){
        if(arr[l]+arr[r]==sum){
            cout << arr[l] << " " << arr[r];
            return;
        }
        if(arr[l]+arr[r]<sum)
            l++;
        else
            r--;
    }
}
void FindPairByHashing(int *arr,int n,int sum){
    bool hash_table[MAX]={0};
    for(int i=0;i<n;i++)
        hash_table[arr[i]]=1;
    for(int i=0;i<n;i++){
        if(hash_table[sum-arr[i]]){
            cout << arr[i] << " " << sum-arr[i] << endl;
            return;
        }
    }
    
}
int main() {
    int sum = 16;
    int arr_size = 6;
	int arr[arr_size] = {1, 4, 45, 6, 10, 8};
	sort(arr,arr+arr_size);
	FindPairBySorting(arr,arr_size,sum);
	cout << endl;
	FindPairByHashing(arr,arr_size,sum);
	return 0;
}
