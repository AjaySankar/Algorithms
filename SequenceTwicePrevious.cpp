#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printVector(vector<int> v){
  for(int i=0;i<v.size();i++)
    cout << v[i] << " ";
}

int main(){
  int m = 10;
  int n = 2;
  vector<int> lastValues;
  for(int i=n;i>=1;i--){
    vector<int> arr1;
    for(int j=1;j<=m/(pow(2,i-1));j++)
      arr1.push_back(j);
    if(i==n){
      for(int j=0;j<arr1.size();j++)
        lastValues.push_back(arr1[j]);
      continue;
    }
    vector<int> arr2;
    for(int k=0;k<lastValues.size();k++){
      for(int e=0;e<arr1.size();e++){
        if(arr1[e]>=2*lastValues[k])
          arr2.push_back(arr1[e]);
      }
    }
    if(i!=1){
      for(int k=0;k<lastValues.size();k++)
        lastValues.pop_back();
      for(int k=0;k<arr2.size();k++)
        lastValues.push_back(arr2[k]);
    }
    else
      cout << arr2.size();
  }
  return 0;
}