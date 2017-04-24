// This program is to find the first and second max of an array in one pass

#include <iostream>
#include <limits.h>
using namespace std;
int main() {
	int arr[]={1, 4, 3, 6, 7, 0 , 10};
	int n=sizeof(arr)/sizeof(*arr);
	int i=0;
	int first_max=INT_MIN;
	int second_max=INT_MIN;
	int temp;
	while(i<n){
	   if(arr[i]>first_max){
	       temp=first_max;
	       first_max=arr[i];
	       second_max=temp;
	   }
	   else if(arr[i]>second_max)
	       second_max=arr[i];
	   i++; 
	}
	cout << first_max << " " << second_max;
	return 0;
}
