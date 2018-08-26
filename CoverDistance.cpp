#include<iostream>
using namespace std;
int* dp = NULL; //The value at 'i'th index stores the number of ways distance 'i' can be formed by steps of size 1,2,3
int countWays(int distance){
  //Base cases
  dp[0]=1;
  dp[1] = 1;  //1 can be formed in 1 way by taking 1 step
  dp[2] = 2;  //2 can be fomed in 2 ways by taking either 2 steps of each size 1 or 1 step of size 1
  for(int i=3;i<=distance;i++){
    dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
  }
  return dp[distance];
}

int main(int argc, char const *argv[]){
  int dis;
  cin >> dis;
  dp = (int *)malloc((dis+1)*sizeof(int));
  cout << "Number of ways to cover distance "<< dis << " : " << countWays(dis);
  free(dp);
  return 0;
}
