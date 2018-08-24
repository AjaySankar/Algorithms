#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define N 12
string dictionary[N] = {"i","like","sam","sung","samsung","mobile","ice","cream","icecream","man","go","mango"};
string sentence = "ilikesam";
int length = sentence.length();
bool **table = NULL;
vector<int> indexTable[8][8]; //Need to create this table dynamically depending on the length of the sentence or may
                              //be any other efficient way to store multiple values for a given substring between i and j

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
      bool alreadySplit = false;  //if we already know that the string can be split
      for(int k=i;k<i+sub_len;k++){ //Split the substrings at all possible postions
        if(k == i){
          string temp = sentence.substr(i,sub_len);
          if(IsInDictionary(temp)){ //Check if the substring alone without splitting is in the dictionary
            indexTable[i][i+sub_len-1].push_back(i);
            alreadySplit = true;
          }
        }
        else{
          bool currentSplitPossible = false;  //check if current split is possible
          currentSplitPossible = table[i][k-1] && table[k][i+sub_len-1];  //Check if after splitting both the strings are in the dictionary
          alreadySplit = currentSplitPossible && !alreadySplit ? currentSplitPossible : alreadySplit; //if current split is possible and till now we didnot find any possible split
          if(currentSplitPossible)
            indexTable[i][i+sub_len-1].push_back(k);  //store the split index
        }
      }
      table[i][i+sub_len-1] = alreadySplit; //Set the status of the substring if it can be broken into words in the dictionary
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

void printIndexTable(){
  for(int i=0;i<length;i++){
    for(int j=0;j<length;j++){
      if(indexTable[i][j].size() > 0){
        cout << "For " << i << " " << j << " Split at ==> ";
        for(int k=0;k<indexTable[i][j].size();k++){
          cout << indexTable[i][j].at(k) << " ";
        }
        cout << endl;
      }
    }
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
  //printArray();
  printIndexTable();
  for (int i = 0; i < length ; i++){
    free(table[i]);
  }
  return 0;
}
