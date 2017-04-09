#include<iostream>
using namespace std;
int power(int x,int y){
    if(y==1)
        return x;
    else{
        if(y%2==0){
            int prod=power(x,y/2);
            return prod*prod;
        }
        else{
            int prod=power(x,(y-1)/2);
            return prod*prod*x;
        }
    }
}
int main(){
    int x=2;
    int y=8;
    cout << power(x,y);
    return 0;
}
