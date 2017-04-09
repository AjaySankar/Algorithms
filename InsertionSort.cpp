#include<iostream>
using namespace std;
int main(){
    int n;
    int arr[100];
    int i,key,j;
    i=1;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    while(i<n){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
        i=i+1;
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return 0;
}
