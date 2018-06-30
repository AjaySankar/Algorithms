#include<iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]){
    int n = 6;
    int e1 = 2,e2=4,x1=3,x2=2;  //entry and exit costs
    int a1[n] = {7,9,3,4,8,4};  //cost at each station of line1
    int a2[n] = {8,5,6,4,5,7};  //cost at each station of line2
    int t1[n-1] = {2,3,1,3,4};  //time taken at jth station in line1 to go to line2's j+1 station
    int t2[n-1] = {2,1,2,2,1};  //time taken at jth station in line2 to go to line1's j+1 station
    int f1[n] = {}; //fastest possible time taken for at a station in line1
    int f2[n] = {}; //fastest possible time taken for at a station in line2
    int line1[n] = {};
    int line2[n] = {};
    int L = 0;  //last level
    f1[0] = e1+a1[0];
    f2[0] = e2+a2[0];
    for(int i=1 ; i<n ; i++){
        if(f1[i-1]+a1[i] <= f2[i-1]+a1[i]+t2[i-1]){
            f1[i] = f1[i-1]+a1[i];
            line1[i] = 1;
        }
        else{
            f1[i] = f2[i-1]+a1[i]+t2[i-1];
            line1[i] = 2;
        }
        if(f2[i-1]+a2[i] <= f1[i-1]+a2[i]+t1[i-1]){
            f2[i] = f2[i-1]+a2[i];
            line2[i] = 2;
        }
        else{
            f2[i] = f1[i-1]+a2[i]+t1[i-1];
            line2[i] = 1;
        }
    }
    cout << "Total minimum cost " << std::min(f1[n-1]+x1,f2[n-1]+x2) << endl;
    if(f1[n-1]+x1 <= f2[n-1]+x2)
        L = 1;
    else
        L = 2;
    cout << "station " << n << " " << "line " << L << endl;
    int temp = L;
    for(int i=n-1 ; i>0 ;i--){
        int prevLine = temp == 1 ? line1[i] : line2[i];
        cout << "station " << i << " " << "line " << prevLine << endl;
        temp = prevLine;
    }
    return 0;
}
