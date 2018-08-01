#include<iostream>
#include<bits/stdc++.h>
#define N 5
#define MIN INT16_MIN
using namespace std;

int UP[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,23,6,19,2,15},
    {MIN,4,12,25,8,16},
    {MIN,10,18,1,14,22},
    {MIN,11,24,7,20,3}
};
int TopLeft[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,17,5,13,21},
    {MIN,MIN,9,12,4,3},
    {MIN,MIN,2,1,10,9},
    {MIN,MIN,8,12,3,2}
};
int TopRight[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,7,13,4,6,MIN},
    {MIN,2,8,3,11,MIN},
    {MIN,6,10,8,15,MIN},
    {MIN,13,18,1,7,MIN}
};

int cache[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
};

void printMatrix(){
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
           cout << cache[i][j] << " "; 
        }
        cout << endl;
    }
}

int getMaxDollars(int a,int b,int c){
    int max = ( a < b ) ? b : a;
    return ( ( max < c ) ? c : max );
}

int getDollarsByOneStep(int cProfit,int stepValue){
    if(stepValue == MIN)    //if illegal step then donot add any value just return MIN so that it doesnot
                            //effect the max function output
        return MIN;
    else
        return cProfit+stepValue;
}

int getMaxProfit(int x,int y){
    if(cache[x][y] != MIN)
        return cache[x][y];
    if(x == N-1)
        cache[x][y] = getMaxDollars(UP[x][y],TopLeft[x][y],TopRight[x][y]);
    else
        cache[x][y] = getMaxDollars(getDollarsByOneStep(getMaxProfit(x+1,y),UP[x][y]),
                                    getDollarsByOneStep(getMaxProfit(x+1,y-1),TopLeft[x][y]),
                                    getDollarsByOneStep(getMaxProfit(x+1,y+1),TopRight[x][y]));
    return cache[x][y];
}

int main(){
    cout << "Maximum Profit is " << getMaxProfit(1,1) << endl;
    printMatrix();
    return 0;
}