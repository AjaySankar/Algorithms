/*
  Find the maximum path length from a given cell such that all the cells in the path
  have difference 1 with previous cell in the path
*/
#include <iostream>
#include<cmath>
using namespace std;
#define M 3
#define N 3
enum directions {NO_DIRECTION=0,TOP,DOWN,LEFT,RIGHT};
#define MIN INT16_MIN
int matrix[M][N] = {
  {4,6,7},
  {12,3,8},
  {11,10,9}
};

bool canTakeStep(int current,int next){
  return abs(current-next) == 1;
}

bool isPreviousStep(int nextX,int nextY,int prevX,int prevY){
  return (nextX == prevX) && (nextY == prevY);
}

int findPath(int x,int y,int prevX,int prevY){
  int top  = x == N-1 ? MIN : matrix[x+1][y];
  int down = x == 0   ? MIN : matrix[x-1][y];
  int left = y == 0   ? MIN : matrix[x][y-1];
  int right = y == N-1 ? MIN : matrix[x][y+1];
  int currentPosition = matrix[x][y];
  if(prevX == -1 && prevY == -1)
    cout << "Path in matrix " << matrix[x][y];
  if(canTakeStep(currentPosition,top) && !isPreviousStep(x+1,y,prevX,prevY)){
    cout << " ==> " << matrix[x+1][y];
    return 1+findPath(x+1,y,x,y);
  }
  else if(canTakeStep(currentPosition,down) && !isPreviousStep(x-1,y,prevX,prevY)){
    cout << " ==> " << matrix[x-1][y];
    return 1+findPath(x-1,y,x,y);
  }
  else if(canTakeStep(currentPosition,left) && !isPreviousStep(x,y-1,prevX,prevY)){
    cout << " ==> " << matrix[x][y-1];
    return 1+findPath(x,y-1,x,y);
  }
  else if(canTakeStep(currentPosition,right) && !isPreviousStep(x,y+1,prevX,prevY)){
    cout << " ==> " << matrix[x][y+1];
    return 1+findPath(x,y+1,x,y);
  }
  cout << endl;
  return 0;
}

void printMatrix(){
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main(int argc, char const *argv[]){
  //printMatrix();
  cout << "Length of longest path: " << 1+findPath(0,1,-1,-1);
  return 0;
}
