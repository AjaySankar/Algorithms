#include<iostream>
#include<math.h>
//nth fibonacci number in log(n) time
using namespace std;
float power(float x,int y){
    if(y==0)
        return 1;
    if(y==1)
        return x;
    else{
        if(y%2==0){
            float prod=power(x,y/2);
            return prod*prod;
        }
        else{
            float prod=power(x,(y-1)/2);
            return prod*prod*x;
        }
    }
}
int get_Nth_Fibonacci(int n){
    float phi=1.618033;
    return round(power(phi,n)/2.23606);
}
int main(){
    int n;
    cin >> n;
    cout << get_Nth_Fibonacci(n) << " ";
    return 0;
}
