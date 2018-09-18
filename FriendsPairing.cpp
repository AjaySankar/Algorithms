////https://www.geeksforgeeks.org/friends-pairing-problem/
#include <iostream>
using namespace std;
int numFriends = 4;

int getCount(int n){
  int *arr = (int*)malloc((n+1)*sizeof(int));
  arr[1] = 1; //BaseCase : Only one friend nothing do to 
  arr[2] = 2; //BaseCase : Only two friends then pair them or seperate them
  for(int i=3;i<=n;i++)
    arr[i] = arr[i-1]+arr[i-2]*(i-1);
  int finalCount = arr[n];
  free(arr);
  return finalCount;
}

int main(int argc, char const *argv[]){
  cout << getCount(numFriends);
  return 0;
}
