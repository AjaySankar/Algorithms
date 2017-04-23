//http://www.geeksforgeeks.org/find-the-element-before-which-all-the-elements-are-smaller-than-it-and-after-which-all-are-greater-than-it/
//http://code.geeksforgeeks.org/PbiinJ
//Find the index of element which partitions the array into two parts where elements in left part are less and elements of right part are 
//greater than the partition index.
//arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9} then the index is 4 as arr[4]=6 

#include <iostream>
using namespace std;

int main() {
    int arr[] = {7,0,2,5,1,4,3,8,10,17,9,6,25,26,27,28,29,30};
    //int arr[]={5, 1, 4, 4};
    int n=sizeof(arr)/sizeof(*arr);
    int i=1;
    int l,r;
    int index;
    bool searching_left=false;
    bool searching_right=false;
    bool found=false;
    while(i<n){
        if(arr[i-1]<arr[i]&&arr[i+1]>arr[i]&&!searching_left&&!searching_right){
            l=i-1;
            r=i+1;
            searching_left=true;
            searching_right=true;
        }
        if(searching_left&&arr[l]<arr[i]&&l>=0)
            l--;
        else
            searching_left=false;
        if(searching_right&&arr[r]>arr[i]&&r<n)
            r++;
        else
            searching_right=false;
        if(l==-1&&r==n){
            //cout << i;
            index=i;
            found=true;
            break;
        }
        else if(searching_left||searching_right)
            continue;
        else{
            i++;
            searching_left=false;
            searching_right=false;
        }
    }
    found?cout << "The index is " << index : cout << "There is no such index";
	return 0;
}
