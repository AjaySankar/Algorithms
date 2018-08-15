#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<chrono>
using namespace std;
#define N 6
int p[N+1] = {30,35,15,5,10,20,25};
int cache[N+1][N+1];
int split[N+1][N+1];
int table[N+1][N+1];
int scalarCountMem(int i,int j);    //By memorization technique
int scalarCountTab();    //By Tabulation technique

int scalarCountMem(int i,int j){
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
        int temp = scalarCountMem(i,k)+scalarCountMem(k+1,j)+p[i-1]*p[k]*p[j];
        if(temp < min){
            min = temp;
            splitAt = k;
        }
    }
    cache[i][j] = min;
    split[i][j] = splitAt;
    return min;
}

int scalarCountTab(){
    for(int length=1;length<N;length++){
        int i=1;int j=i+length;
        for(;i<=N-length;i++,j=i+length){
            int min = INT16_MAX;
            for(int k=i;k<j;k++){
                int temp = table[i][k]+table[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp < min)
                    min = temp;
            }
            table[i][j] = min;
        }
    }
    return table[1][N];
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
    for (int i = 0; i < N+1; i++){
        for (int j = 0; j < N+1; j++){
            cache[i][j] = -1;
            split[i][j] = -1;
            table[i][j] = 0;
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Number of multiplications needed by memorization "  << scalarCountMem(1,N) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
    start = std::chrono::high_resolution_clock::now();
    cout << "Number of multiplications needed by tabulation "  << scalarCountTab() << endl; 
    stop = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
    cout << printSplits(1,N);
    return 0;
}