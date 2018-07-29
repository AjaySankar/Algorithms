#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
#define N 5
int M = 10;
string paragrph[N+1] = {"dummy","Tushar", "Roy", "likes", "to" , "code"};
int cache[N+1][N+1];
int subSentenceLength[N+1][N+1];
int splitAt[N+1][N+1];

int canExistsInLine(int left, int right){
    return M-((right-left)+subSentenceLength[left][right]);
    //returns -ve value if the sentence formed by words in paragraph between left and right(inclusive both)
    //cannot fit into a sentence else returns a non negative value which is the number of extra spaces at 
    //the end of the line
}

int printParagraph(int left, int right){
    if(cache[left][right] >= 0)
        return cache[left][right];
    int extraSpaces = -1;
    if((extraSpaces = canExistsInLine(left,right)) >= 0){    //Do not split if the sentence can fit in a line
        cache[left][right] = extraSpaces*extraSpaces*extraSpaces;
        return cache[left][right];
    }
    int min = INT16_MAX;
    int index = -1;
    for(int k=left;k<right;k++){
        int currentSplit = printParagraph(left,k)+printParagraph(k+1,right);
        if(currentSplit < min){
            min = currentSplit;
            index = k;
        }
    }
    cache[left][right] = min;
    splitAt[left][right] = index;
    return min;
}

void printCache(){
    for(int i=0; i<N+1 ;i++){
        for(int j=0; j<N+1 ; j++){
            cout << splitAt[i][j] << " ";
        }
        cout << endl;
    }
}

void printToScreen(int left,int right){
    int splitIndex = splitAt[left][right];
    if(splitIndex == -1 || left == right){
        for(int i=left;i<=right;i++){
            cout << paragrph[i] << " ";
        }
        return;
    }
    printToScreen(left,splitIndex);
    cout << endl;
    printToScreen(splitIndex+1,right);
}

int main(){
    for(int i=0; i<N+1 ;i++){
        for(int j=0; j<N+1 ; j++){
            cache[i][j] = -1;
            subSentenceLength[i][j] = -1;
            splitAt[i][j] = -1;
            if(i == j && i>0){
                subSentenceLength[i][j] = paragrph[i].length();
                splitAt[i][j] = i;
            }
        }
    }
    for(int i=1; i<N+1 ;i++){
        for(int j=1; j<N+1 ; j++){
            if(i < j){
                subSentenceLength[i][j] = subSentenceLength[i][j-1]+subSentenceLength[j][j];
            }
        }
    }
    cout << "Minimal sum over all lines " << printParagraph(1,N) << endl;
    //printCache();
    printToScreen(1,N);
    return 0;
}