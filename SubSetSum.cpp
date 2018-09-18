#include <iostream>
using namespace std;
#define N 6

bool isSubSet(int* arr,int n,int sum){
  if(sum == 0)
    return true;  //sum to be formed is zero
  if(sum !=0 && n == 0)
    return true;  //sum is still there but no more elements are available
  if(arr[n] > sum)
    return isSubSet(arr,n-1,sum); //If the element is bigger than the sum to be formed the exclude the element
  else
    return isSubSet(arr,n-1,sum) || isSubSet(arr,n-1,sum-arr[n]); //either exclude the element OR include the element in the sum
}

bool isSubSetTab(int* arr,int n,int sum){
  bool table[n+1][sum+1];
  for(int i=0;i<=n;i++)
    table[i][0] = true; //when sum is zero the return true
  for(int i=1;i<=sum;i++)
    table[0][i] = false;  //when array is empty and sum is not zero then return true
  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
      if(j < arr[i-1])
        table[i][j] = table[i-1][j];
      else
        table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
    }
  }
  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
  return table[n][sum];
}

int main(int argc, char const *argv[]){
  int arr[N] = {3,34,4,12,5,2};
  int sum = 9;
  cout << isSubSetTab(arr,N-1,sum);
  return 0;
}
