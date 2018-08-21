#include<iostream>
#include <map>
#include<bits/stdc++.h>
using namespace std;
#define N 8
//Challenge is to cut the rod into pieces to make maximum profit
//Following table give the price of the rod at a given length
/*length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20*/
map<int, int> priceMap = {
		{1,1},
		{2,5},
    {3,8},
    {4,9},
    {5,10},
    {6,17},
    {7,17},
    {8,20}
};
int table[N+1] = {0,0,0,0,0,0,0,0,0};
//int cuts[N+1] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
map<int,int> cuts;

int maxProfit(){
  table[1] = priceMap[1];
  cuts[priceMap.begin()->first] = 0;
  for(int i=2;i<=N;i++){
    int temp = 0;int max = INT16_MIN;int index = -1;
    for(int j=0;j<=(i/2);j++){
      temp = j==0 ? priceMap[i] : table[i-j]+table[j];
      if(temp > max){
        index = j;
        max = temp;
      }
    }
    table[i] = max;
    cuts[i] = index;
  }
  return table[N];
}

void printArray(){
  for(int i=1;i<=N;i++)
    cout << table[i] << " ";
  cout << endl;
  map<int, int>::iterator iter;
  for (iter = cuts.begin(); iter != cuts.end(); ++iter) {
    cout << iter->first << " " << iter->second << endl;
  }
}

void cutTheRod(int n){
  if(cuts[n] == 0){
    cout << n << " " << priceMap[n]  << endl;
    return;
  }
  cout << cuts[n] << " " << priceMap[cuts[n]] << endl;
  cutTheRod(n-cuts[n]);
}

int main(){
  cout << "Maximum profit from cutting is " << maxProfit() << endl;
  cout << endl;
  //printArray();
  cutTheRod(N);
  return 0;
}
