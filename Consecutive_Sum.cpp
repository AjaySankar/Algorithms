/* This program prints all the possible sequences of consecutive numbers whose sum is equal to given value N
if N=100
Sequence 1 : 9 10 11 12 13 14 15 16 
Sequence 2 : 18 19 20 21 22

Let the sequence be x , x+1 , x+2 ..... x+r and so .. x+x+1+x+2+....x+r=N and by coverting it to a 
quadratic equation as r^2+r(1+2x)+2(x-N)=0 and as 'r' is the root of the equation, and it should be r > 0 and an integer
so the determinent of the quadratic equation should be a perfect square for r > 0 and r is an integer.

So for all values of x from 1 to N find the value of r , and get the value of r which is the solution of the equation. */

#include <iostream>
#include <math.h>
using namespace std;
bool IsPerfectSquare(long input)
{
    long closestRoot = (long) sqrt(input);
    return input == closestRoot * closestRoot;
}
int main() {
    int N=100;
    for(int i=0;i<N;i++){
        int det=(1+2*i)*(1+2*i)-(8*(i-N));
        if(IsPerfectSquare(det)){
            cout << i << " to ";
            int r1=(-(1+(2*i))+(int)sqrt(det))/2;
            cout << i+r1 << endl;
        }
    }
	return 0;
}
