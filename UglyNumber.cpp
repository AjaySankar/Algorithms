//https://www.geeksforgeeks.org/ugly-numbers/
#include<iostream>
#include <map>
using namespace std;
map<int,bool> memory;
map<int,bool> table;
map<int,bool>::iterator it;

bool isUglyMem(int number){
  it = memory.find(number);
  if (it != memory.end())
    return it->second;
	if(number == 1 || number == 2 || number == 3 || number == 5){
    memory[number] = true;
		return true;
  }
	bool isDivisibleBy2 = false;
	bool isDivisibleBy3 = false;
	bool isDivisibleBy5 = false;
	isDivisibleBy2 = number%2 == 0 ? true : false;
	isDivisibleBy3 = number%3 == 0 ? true : false;
	isDivisibleBy5 = number%5 == 0 ? true : false;
	isDivisibleBy2 =  isDivisibleBy2 ? isUglyMem(number/2) : isDivisibleBy2;
	isDivisibleBy3 =  isDivisibleBy3 ? isUglyMem(number/3) : isDivisibleBy3;
	isDivisibleBy5 =  isDivisibleBy5 ? isUglyMem(number/5) : isDivisibleBy5;
  memory[number] = isDivisibleBy2 || isDivisibleBy3 || isDivisibleBy5;

	return isDivisibleBy2 || isDivisibleBy3 || isDivisibleBy5;
}

bool isUglyTab(int number){
  for(int i=1;i<=number;i++){
    if(i == 1 || i == 2 || i == 3 || i == 5){
      table[i] = true;
      continue;
    }
    bool isDivisibleBy2 = false;
    bool isDivisibleBy3 = false;
    bool isDivisibleBy5 = false;
    isDivisibleBy2 = i%2 == 0 ? true : false;
    isDivisibleBy3 = i%3 == 0 ? true : false;
    isDivisibleBy5 = i%5 == 0 ? true : false;
    isDivisibleBy2 =  isDivisibleBy2 ? table[i/2] : isDivisibleBy2;
    isDivisibleBy3 =  isDivisibleBy3 ? table[i/3] : isDivisibleBy3;
    isDivisibleBy5 =  isDivisibleBy5 ? table[i/5] : isDivisibleBy5;
    table[i] = isDivisibleBy2 || isDivisibleBy3 || isDivisibleBy5;
  }
  return table[number];
}

int main(int argc, char const *argv[]){
  int n = 150;
  int number = 1;
  int x = 1;
  //cout << isUglyTab(5832) << endl; 
  while(1){
    if(isUglyTab(number)){  //Intresting observation: Tabulation takes more time than memorization. Why???
      if(x == n){
        cout << n << "th Ugly number is " << number;
        break;
      }
      x++;
    }
    number++;
  }
  return 0;
}
