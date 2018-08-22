#include<iostream>
#include<string>
using namespace std;
#define N 12
string dictionary[N] = {"i","like","sam","sung","samsung","mobile","ice","cream","icecream","man","go","mango"};
string sentence = "ilikesam";
int length = sentence.length();
bool **table = NULL;

bool IsInDictionary(string str){
  int findIndex = -1;
  for(int j=0;j<N;j++){
    findIndex = str.compare(dictionary[j]);
    if(findIndex == 0)
      return true;
  }
  return false;
}

void BreakTheWord(){
  int sub_len = 1;
  for(int i=0;i<length;i=i+sub_len){  //check if each letter in the sentence exists in the dictionary
    string substr = sentence.substr(i,sub_len);
    if(IsInDictionary(substr))
      table[i][i] = true;
  }
  for(sub_len=2;sub_len<=length;sub_len++){ //start checking all substrings of lengths 2 to string length
    for(int i=0;i<=length-sub_len;i++){ //Iterate over all substrings of particular length 
      string substr = sentence.substr(i,sub_len);
      int index = -1;bool canSplit = false;
      for(int k=i;k<i+sub_len;k++){ //Split the substrings at all possible postions
        if(k == i){
          string temp = sentence.substr(i,sub_len);
          if(IsInDictionary(temp)){ //Check if the substring alone without splitting is in the dictionary
            index = k;
            canSplit = true;
          }
        }
        else
          canSplit = canSplit ? canSplit : table[i][k-1] && table[k][i+sub_len-1];  //Check if after splitting both the strings are in the dictionary
      }
      table[i][i+sub_len-1] = canSplit; //Set the status of the substring if it can be broken into words in the dictionary
    }
  }
}

void printArray(){
  for(int i=0;i<length;i++){
    for(int j=0;j<length;j++){
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  table = (bool **)malloc((length) * sizeof(bool *)); //rows
  for (int i=0; i<length; i++)
    table[i] = (bool *)malloc((length) * sizeof(bool));  //columns
  for (int i = 0; i <  length; i++){
    for (int j = 0; j < length; j++){
      table[i][j] = false; 
    }
  }
  BreakTheWord();
  printArray();
  for (int i = 0; i < length ; i++){
    free(table[i]);
  }
  return 0;
}
