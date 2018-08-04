#include<iostream>
#include<bits/stdc++.h>
#define N 5
#define MIN INT16_MIN
#define EMPTY '-'
using namespace std;

int UP[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,11,24,7,20,3},
    {MIN,10,18,1,14,22},
    {MIN,4,12,25,8,16},
    {MIN,23,6,19,2,15},
    {MIN,MIN,MIN,MIN,MIN,MIN}
};
int TopLeft[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,8,12,3,2},
    {MIN,MIN,2,1,10,9},
    {MIN,MIN,9,12,4,3},
    {MIN,MIN,17,5,13,21},
    {MIN,MIN,MIN,MIN,MIN,MIN},
};
int TopRight[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,13,18,1,7,MIN},
    {MIN,6,10,8,15,MIN},
    {MIN,2,8,3,11,MIN},
    {MIN,7,13,4,6,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN}
};

int cache[N+1][N+1] = {
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN},
    {MIN,MIN,MIN,MIN,MIN,MIN}
};

char path[N+1][N+1] = {
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY}
};

void printMatrix(){
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
           cout << path[i][j] << " "; 
        }
        cout << endl;
    }
}

void updatePath(int max,int up,int tl,int tr, int x, int y){
    if(max == up)
        path[x][y] = 'U';
    else if(max == tl)
        path[x][y] = 'L';
    else if(max == tr)
        path[x][y] = 'R';
    else
        path[x][y] = '-';
}

void printPath(int x,int y){
    if(x == N)
        return;
    char direction = path[x][y];
    switch(direction){
        case 'U':
                    cout << x << " " << y << " ==> " << x+1 << " " << y << " With profit: " << UP[x][y] << endl;
                    printPath(x+1,y);
                    break;
        case 'L':
                    cout << x << " " << y << " ==> " << x+1 << " " << y-1 << " With profit: " << TopLeft[x][y] << endl;
                    printPath(x+1,y-1);
                    break;
        case 'R':
                    cout << x << " " << y << " ==> " << x+1 << " " << y+1 << " With profit: " << TopRight[x][y] << endl;
                    printPath(x+1,y+1);
                    break;
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
    if(x == N-1){
        cache[x][y] = getMaxDollars(UP[x][y],TopLeft[x][y],TopRight[x][y]);
        updatePath(cache[x][y],UP[x][y],TopLeft[x][y],TopRight[x][y],x,y);
    }
    else{
      int upProfit = getDollarsByOneStep(getMaxProfit(x+1,y),UP[x][y]);
      int topLeftProfit = y == 1 ?   MIN : getDollarsByOneStep(getMaxProfit(x+1,y-1),TopLeft[x][y]);
      int topRightProfit = y == N ?   MIN : getDollarsByOneStep(getMaxProfit(x+1,y+1),TopRight[x][y]);
      cache[x][y] = getMaxDollars(upProfit,topLeftProfit,topRightProfit);
      updatePath(cache[x][y],upProfit,topLeftProfit,topRightProfit,x,y);
    }
    
    return cache[x][y];
}

int main(){
    cout << "Maximum Profit is " << getMaxProfit(1,1) << endl;
    //printMatrix();
    printPath(1,1);
    return 0;
}