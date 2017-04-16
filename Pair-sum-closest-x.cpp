//This porgram find the pair (x,y) each from two different sorted arrays such that 
//the sum of the pair is closest to a given value x
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;
void Merge_Arrays(int *left,int n1,int *right,int n2,int *temp,int *b_array){
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	while(i<n1&&j<n2){
		if(left[i]<right[j]){
			temp[k++]=left[i++];
			b_array[l++]=0;
		}
		else{
			temp[k++]=right[j++];
			b_array[l++]=1;
		}
	}
	while(i<n1){
		temp[k++]=left[i++];
		b_array[l++]=0;
	}
	while(j<n2){
		temp[k++]=right[j++];
		b_array[l++]=1;
	}
}
void Find_Pair_Sum_Closest_To_x(int *arr1,int *arr2,int n1,int n2,int x){
	int l=0;
	int r=n2-1;
	int left_index;
	int right_index;
	int min_diff=9999;
	while(l<=n1-1&&r>=0){
		if (abs(arr1[l] + arr2[r] - x) < min_diff)
		{
			left_index = l;
			right_index = r;
			min_diff = abs(arr1[l] + arr2[r] - x);
		}
		if (arr1[l] + arr2[r] > x)
			r--;
		else
			l++;
	}
	cout << "The closest pair is [" << arr1[left_index] << ", "<< arr2[right_index] << "]"<<"\n";
}
void PrintArray(int *temp,int n){
	for(int i=0;i<n;i++)
		cout << temp[i] << " ";
}
int main() {
	int left[]={1, 4, 5, 7};
	int right[]={10, 20, 30, 40};
	int n1=sizeof(left)/sizeof(*left);
	int n2=sizeof(right)/sizeof(*right);
	int temp[n1+n2];
	int b_array[n1+n2];
	Merge_Arrays(left,n1,right,n2,temp,b_array);
	int x = 38;
	int n=n1+n2;
	Find_Pair_Sum_Closest_To_x(left,right,n1,n2,x);
	return 0;
}

