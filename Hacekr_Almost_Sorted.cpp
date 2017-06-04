//https://www.hackerrank.com/challenges/almost-sorted
//This code worked and all test cases passed
//Keep it up..
#include <iostream>
using namespace std;
bool Can_Swaps(int *arr,int n,int *left,int *right){
    //This function return boolean value if we can sort an array with one swap
    *left=-1;*right=-1;
    int ditches=0;
    int ditch_index_one=-1;
    int ditch_index_two=-1;
    if(n<=2){
        if(arr[0]>arr[1]){
            *left=0;
            *right=1;
        }
        return true;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            ditches++;
            ditches==1?ditch_index_one=i: ditch_index_one=ditch_index_one;
            ditches==2?ditch_index_two=i: ditch_index_two=ditch_index_two;
        }
    }
    //cout << "Ditches are : " << ditches << endl;
    //cout << ditch_index_one << " " << ditch_index_two << endl;
    if(ditches >= 3)
        return false;
    //In case if ditches is 2 then swap values at index ditch_index_one and ditch_index_two+1
    else if(ditches==2){
        if(arr[ditch_index_two+1]<=arr[ditch_index_one+1]&&arr[ditch_index_one]>=arr[ditch_index_two]){
            *left=ditch_index_one;*right=ditch_index_two+1;
            return true;
        }
        else
            return false;
    }
    //In case if ditches is 1 then swap values at index ditch_index_one and ditch_index_one+1
    else{
        *left=ditch_index_one;*right=ditch_index_one+1;
        if(ditch_index_one==0&&arr[ditch_index_one]<=arr[ditch_index_one+2])
            return true;
        if(ditch_index_one==n-2&&arr[ditch_index_one-1]<=arr[ditch_index_one+1])
            return true;
        if(arr[ditch_index_one-1]<=arr[ditch_index_one+1]&&arr[ditch_index_one]<=arr[ditch_index_one+2])
            return true;
        return false;
    }
}
bool Can_Reverse(int *arr,int n,int *left,int *right){
    // To be able sort an array by reversing a subsegment, so the array should be composed of one increasing
    // part(this is optional) followed by a decreasing part and then another increasing part(this is optional)
    *left=-1;*right=-1;
    int first_incr_begin=-1;int first_incr_end=-1;
    int decr_begin=-1;int decr_end=-1;
    int sec_incr_begin=-1;int sec_incr_end=-1;
    int i=0;
    bool is_Increasing=false;
    for(i=0;i<n-1;){
        if(arr[i] < arr[i+1]){
            i++;
            is_Increasing=true;
        }
        else
            break;
    }
    is_Increasing?first_incr_begin=0:first_incr_begin=-1;
    is_Increasing?first_incr_end=i:first_incr_end=-1;
    //cout << first_incr_begin << " " << first_incr_end << endl;
    if(i==n-1&&is_Increasing){
        *left=-1;*right=-1;
        return true;      //ALREADY_SORTED
    }
    if(i==n-1&&!is_Increasing){
        *left=0;*right=n-1;
        return true;   //ALREADY_SORTED_IN_REVERSE
    }
    decr_begin=i;
    for(;i<n-1;){
        if(arr[i] >= arr[i+1])
            i++;
        else
            break;
    }
    i==n-1?decr_end=n-1:decr_end=i;
    //cout << decr_begin << " " << decr_end << endl;
    if(i==n-1){     //NO_SECOND_INCREASING_PART
        if(arr[decr_end]>arr[decr_begin-1]){
            *left=decr_begin;*right=n-1;
            return true;
        }
        else
            return false;
    }
    sec_incr_begin=i;
    for(;i<n-1;){
        if(arr[i] <= arr[i+1])
            i++;
        else
            break;
    }
    sec_incr_end=i;
    //cout << sec_incr_begin << " " << sec_incr_end << endl;
    if(i!=n-1)
        return false;
    if(first_incr_begin==-1){   // No first increasing part
        if(arr[decr_begin]<arr[decr_end+1]){
            *left=0;*right=decr_end;
            return true;
        }
        else
            return false;
    }
    else{
        if(arr[decr_end]>arr[decr_begin-1]&&arr[decr_begin]<arr[decr_end+1]){
            *left=decr_begin;*right=decr_end;
            return true;
        }
        else
            return false;
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];//={1,2,3,6,5,4,7,8,9,10};
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int left,right;
    if(Can_Swaps(arr,n,&left,&right)){
        cout << "yes" << endl;
        if(left!=-1&&right!=-1)
            cout << "swap " << left+1 << " " << right+1;
        return 0;
    }
    if(Can_Reverse(arr,n,&left,&right)){
        cout << "yes" << endl;
        if(left!=-1&&right!=-1)
            cout << "reverse " << left+1 << " " << right+1;
        return 0;
    }
    cout << "no";
    return 0;
}
