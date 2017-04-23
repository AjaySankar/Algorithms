//This program is to test if reversing a sub array sorts the entire array in ascending  order
// arr[] = {1,2,3,6,5,4,7,8,9}
//Step 1 : Find the first increasing part  -- 1,2,3
//Step 2 : Find the decreasing part        -- 6,5,4
//Step 3 : Find the second increasing part -- 7,8,9
//Time Complexity : O(n)
//This can also be solved by sorting the array and comparing the original and sorted arrays -- O(nlogn)

#include <iostream>
using namespace std;
bool checkReverse(int *arr,int n){
    //find the increasing part
    int i=0;
    int j;
    while(i<n-1){
        if(arr[i]<=arr[i+1])
            j=i;
        else
            break;
        i++;
    }
    cout << "The increasing part begins at 0 and ends at " << j << endl;
    if(j==n-1)
        return true;
    //find the decreasing part
    int k=j+1;
    int l;
    while(k<n-1){
        if(arr[k]>=arr[k+1])
            l=k;
        else
            break;
        k++;
    }
    cout << "The decreasing part begins at " << j+1 << " and ends at " << l+1 << endl;
    if(l==n-1)
        return true;
    if(arr[j]>arr[l+1])  // To handle cases like 1 2 3 6 5 -1 7 8 9     (3>-1)
        return false;
    if(arr[l+1]>arr[j+2])   //To handle cases like 1 2 3 10 5 4 7 8 9  (10>7)
        return false;
    //find second increasing part
    int m=l+2;
    while(m<n-1){
        if(arr[m]>arr[m+1])
            return false;
        m++;
    }
    return true;
}
int main() {
	int arr [] = {1, 3, 4, 10, 9, 8};
	int n=sizeof(arr)/sizeof(*arr);
	checkReverse(arr, n)? cout << "Yes" : cout << "No";
	return 0;
}
