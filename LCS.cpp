#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const char* X="ABCBDAB";
const char* Y="BDCABA";
const int lenX = 7;
const int lenY = 6;
int cache[lenX+1][lenY+1];

int LCS(const char* X,const char* Y,int m,int n){
    if(cache[m][n] != 0){
        return cache[m][n];
    }
    if(m==0 || n==0){
        cache[m][n] = 0;
        return 0;
    }
    int len;
    if(X[m-1] == Y[n-1]){
        len = LCS(X,Y,m-1,n-1);
        cache[m][n] = len+1;
        return len+1;
    }
    else{
        len = std::max(LCS(X,Y,m,n-1),LCS(X,Y,m-1,n));
        cache[m][n]=len;
        return len;
    }
}

void printLCS(int m,int n){
    if(m==0 || n==0)
        return;
    if(X[m-1] == Y[n-1]){
        printLCS(m-1,n-1);
        cout << X[m-1];
    }
    else{
        if(cache[m][n-1]>cache[m-1][n])
            printLCS(m,n-1);
        else
            printLCS(m-1,n);
    }
}

int main(int argc, char const *argv[]){
    for(int i=0;i<lenX+1;i++)
        for(int j=0;j<lenY+1;j++)
            cache[i][j] = 0;
    cout << "LCS length is " << LCS(X,Y,lenX,lenY) << endl;
    cout << "Longest Common Subsequence is " ;
    printLCS(lenX,lenY);
    return 0;
}
