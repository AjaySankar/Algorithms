//https://www.geeksforgeeks.org/tiling-problem/
//Assumption : At any point of time if we have problem of dimension (2xn) then we can only fill tiles in either
// a. 1 vertical tile of dimensions 1x2 so that next problem to be solved is of size (2x(n-1))
// b. 2 horizontal tiles one above the other (vertically) so that the problem to be solved is of size (2x(n-2))

#include<iostream>
#include<map>
using namespace std;
int n = 4;
map<int,int> memory;
map<int,int> table;
map<int,int>::iterator it;

int countMem(int tilingColumn){
  it = memory.find(tilingColumn);
  if (it != memory.end())
    return it->second;
  if(tilingColumn == n){
    memory[tilingColumn] = 1;
    return 1;
  }
  if(tilingColumn == n-1){
    memory[tilingColumn] = 2;
    return 2;
  }
  int ways = countMem(tilingColumn+1)+countMem(tilingColumn+2); //ways = arranging 1 tile vertically 1x2 + arranging 2 tiles horizontally 2x1
  memory[tilingColumn] = ways;
  return ways;
}

int countTab(int tilingColumn){
  table[tilingColumn] = 1;
  table[tilingColumn+1] = 2;
  for(int i=tilingColumn+2 ; i<=n ; i++)
    table[i] = table[i-1]+table[i-2];
  return table[n];
}

int main(int argc, char const *argv[]){
  cout << countTab(1);
  return 0;
}
