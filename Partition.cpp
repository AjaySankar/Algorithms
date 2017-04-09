#include<iostream>>
using namespace std;
void myswap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
int Partition(int *arr,int p,int r){
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(arr[j]<=x){
            i=i+1;
            myswap(arr+i,arr+j);
        }
    }
    myswap(arr+i+1,arr+r);
    return i+1;
}
void QuickSort(int *arr,int p,int r){
    if(p<r){
        int q=Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}
int main(){
    int arr[8]={2,8,7,1,3,5,6,4};
    QuickSort(arr,0,7);
    for(int i=0;i<8;i++)
        cout << arr[i] << " ";
    return 0;
}
