#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 7
#define MIN INT16_MIN
int cache[N+1];

int NthFibonacci(int n){
    if(cache[n] != MIN)
        return cache[n];
    if(n == 0 || n==1){
        cache[n] = n;
    }
    else{
        int f1 = NthFibonacci(n-1);
        int f2 = NthFibonacci(n-2);
        cache[n] = f1+f2;
    }
    return cache[n];
}

int main(int argc, char const *argv[]){
    for(int i=0;i<N+1;i++){
        cache[i] = MIN;
    }
    cout << NthFibonacci(N);
    return 0;
}
