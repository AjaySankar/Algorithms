//https://www.geeksforgeeks.org/game-theory-choice-area/
#include <iostream>
#include <map>
#define numPowers 2
enum powerIndex {A=0,B=1};
using namespace std;
int X[numPowers] = {3,2};
int Y[numPowers] = {-5,-10};
int Z[numPowers] = {-20,5};
map< pair<int, int>, int > memory;

int max(int a,int b){
  return a > b ? a : b;
}

int getMaxTime(int powA,int powB,char startArea){
  if(powA <= 0 || powB <= 0)
    return 0;
  pair<int, int> cur = make_pair(powA, powB);
  if (memory.find(cur) != memory.end()){
    cout << "Match found inside " << powA << " " << powB << endl;
    return memory[cur]; 
  }
  int currTimeAfterMoving = 0;
  if(startArea == 'X')
    currTimeAfterMoving = 1+max(getMaxTime(powA+X[A],powB+X[B],'Y'),getMaxTime(powA+X[A],powB+X[B],'Z'));
  else if (startArea == 'Y')
    currTimeAfterMoving = 1+max(getMaxTime(powA+Y[A],powB+Y[B],'X'),getMaxTime(powA+Y[A],powB+Y[B],'Z'));
  else
    currTimeAfterMoving = 1+max(getMaxTime(powA+Z[A],powB+Z[B],'X'),getMaxTime(powA+Z[A],powB+Z[B],'Y'));
  //memory[cur] = currTimeAfterMoving;
  return currTimeAfterMoving;
}

int main(int argc, char const *argv[]){
  int powA = 20,powB = 8;
  cout << getMaxTime(powA,powB,'X');
  return 0;
}
