#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int n = 6;
int p[7] = {30,35,15,5,10,20,25};
int cache[7][7];
int split[7][7];
int scalarCount(int i,int j);

int scalarCount(int i,int j){
    if(cache[i][j] != -1){
        return cache[i][j];
    }
    if(i==j){
        cache[i][j] = 0;
        return 0;
    }
    int min = INT16_MAX;
    int splitAt  = -1;
    for(int k=i;k<j;k++){
        int temp = scalarCount(i,k)+scalarCount(k+1,j)+p[i-1]*p[k]*p[j];
        if(temp < min){
            min = temp;
            splitAt = k;
        }
    }
    cache[i][j] = min;
    split[i][j] = splitAt;
    return min;
}

std::string printSplits(int lower,int upper){
    if(upper-lower==0){
        return "(" + std::to_string(lower) + ")";
    }
    if(upper-lower==1){
        return "(" + std::to_string(lower) + std::to_string(upper) + ")";
    }
    return "("+printSplits(lower,split[lower][upper])+printSplits(split[lower][upper]+1,upper)+")";
}

int main(){
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++){
            cache[i][j] = -1;
            split[i][j] = -1;
        }
    }
    cout << "NUmber of multiplications needed " << scalarCount(1,n) << endl;
    cout << printSplits(1,n);
    return 0;
}