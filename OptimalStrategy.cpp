//https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
#include<iostream>
using namespace std;
# define N 4
int coins[N] = {8, 15, 3, 7};
int Ascores[N][N];
int Bscores[N][N];
int Acoins[N][N];
int Bcoins[N][N];
char turn = 'A';  //who first begins the game

int getMaxScore(){
  for(int i=0;i<N-1;i++){ //when number of coins in the game is 2(base case) then choose the largest value coin
    int j = i+1;
    int max = coins[i] > coins[j] ? coins[i] : coins[j];
    int min = coins[i] < coins[j] ? coins[i] : coins[j];
    if(turn == 'A'){
      Ascores[i][j] = max;
      Bscores[i][j] = min;
      Acoins[i][j] = coins[i] > coins[j] ? i : j;
    }
    else{
      Ascores[i][j] = min;
      Bscores[i][j] = max;
      Bcoins[i][j] = coins[i] > coins[j] ? i : j;
    }
  }
  for(int num=2;num<N;num++){ //number of coins in the game currently (starting at 3)
    turn = turn == 'A' ? 'B' : 'A'; //switch turn for each iteration (By now already once game is played with 2 coins. See above)
    for(int i=0 ;i<N-num;i++){
      //Working on problem with coins from i to i+num inclusive of boundries
      int profitByLeft = 0;int profitByRight = 0;
      if(turn == 'A'){  //when turn it is A's turn
        profitByLeft = coins[i]+Ascores[i+1][i+num];  //profit by choosing leftmost coin in the sequence
        profitByRight = coins[i+num]+Ascores[i][i+num-1]; //profit by choosing rightmost coin in the sequence
        if(profitByLeft > profitByRight){
          Ascores[i][i+num] = profitByLeft; //get max of those profits and initialize A's profit
          Bscores[i][i+num] = Bscores[i+1][i+num];  //get B's profit from previous turn
          Acoins[i][i+num] = i;
        }
        else{
          Ascores[i][i+num] = profitByRight;
          Bscores[i][i+num] = Bscores[i][i+num-1];
          Acoins[i][i+num] = i+num;
        }
      } 
      else{ //Mirror image of above if block
        profitByLeft = coins[i]+Bscores[i+1][i+num];
        profitByRight = coins[i+num]+Bscores[i][i+num-1];
        if(profitByLeft > profitByRight){
          Bscores[i][i+num] = profitByLeft;
          Ascores[i][i+num] = Ascores[i+1][i+num];
          Bcoins[i][i+num] = i;
        }
        else{
          Bscores[i][i+num] = profitByRight;
          Ascores[i][i+num] = Ascores[i][i+num-1];
          Bcoins[i][i+num] = i+num;
        }
      }
    }
  }
  return turn == 'A' ? Ascores[0][N-1] : Bscores[0][N-1];
}

void printGame(char turn,int start,int end){
  char nextTurn = turn == 'A' ? 'B' : 'A';
  int coinIndex = turn == 'A' ? Acoins[start][end] : Bcoins[start][end];
  if(end - start == 1){
    cout << turn << " takes " << coins[coinIndex] << endl;
    int lastCoinIndex = coinIndex == end ? end-1 : start+1;
    cout << nextTurn << " takes " << coins[lastCoinIndex] << endl;    
    return;
  }
  cout << turn << " takes " << coins[coinIndex] << endl;
  if(coinIndex == start)
    printGame(nextTurn,start+1,end);
  else
    printGame(nextTurn,start,end-1);
}

void printArrays(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << Bcoins[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      Ascores[i][j] = 0;
      Bscores[i][j] = 0;
      Acoins[i][j] = 0;
      Bcoins[i][j] = 0;
    }
  }
  cout << "Maximum amount of money if " << turn << " begins first is: " << getMaxScore() << endl;
  cout << "Game plan" << endl;
  printGame(turn,0,N-1);
  //printArrays();
  return 0;
}