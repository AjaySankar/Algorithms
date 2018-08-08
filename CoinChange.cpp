//https://www.hackerrank.com/challenges/coin-change/problem
#include <iostream>
using namespace std;
#define MIN INT16_MIN
#define N 3

int arr[N] = {1,2,3};
int sum = 4;
int cache[5] = {MIN,MIN,MIN,MIN,MIN};
//int temp[N] = {0,0,0};
int min_arr = 1;

int getWays(int balance){
  if(balance >0 && cache[balance] != MIN)
    return cache[balance];
  if(balance == 0){
    cache[balance] = 1;
    return cache[balance];
  }
  else if(balance < min_arr || balance < 0){
    if(balance < 0)
      return 0;
    cache[balance] = 0;
    return cache[balance];
  }
  else{
    int temp[N] = {0,0,0};
    cache[balance] = 0;
    for(int i=0;i<N;i++){
      temp[i] = getWays(balance-arr[i]);
      cache[balance]+=temp[i];
      cout << temp[i] << " ";
    }
    cout << endl;
  }
  return cache[balance];
}

int main(){
    getWays(4);
    return 0;
}
