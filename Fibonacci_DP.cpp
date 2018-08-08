#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 20
#define MIN INT16_MIN
int cache[N+1];

int NthFibonacci(int t1,int t2,int n){
    if(cache[n] != MIN)
        return cache[n];
    if(n == t1 || n == t2){
        cache[n] = n;
    }
    else{
        int f1 = NthFibonacci(t1,t2,n-1);
        int f2 = NthFibonacci(t1,t2,n-2);
        cache[n] = (f1*f1)+f2;
    }
    return cache[n];
}

int main(int argc, char const *argv[]){
    for(int i=0;i<N+1;i++){
        cache[i] = MIN;
    }
    int n = 5;
    cout << NthFibonacci(0,1,n-1);
    return 0;
}
