#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <time.h>

using namespace std;

void digitizer(vector<int> &digits, int num){
  while(num > 0){
    digits.push_back(num % 10);
    num /= 10;
  }
}

vector<int> binary_digitizer(int num){
  int n = log(num)/log(2);
  vector<int> bin(n+1);
  while(num > 0){
    if(num >= pow(2,n)){
      bin[bin.size()-1-n] = 1;
      num -= pow(2,n);
    }
    n--;
  }
  return bin;
}

bool palcheck(vector<int> digits){
  if(digits.size() == 1) return true;
  for(int i=0;i<digits.size()/2;i++){
    if(digits[i] != digits[digits.size()-1-i]) return false;
  }
  return true;
}

int main(int argc, char** argv){


  cout << "Input n - returns all palindromes (base 10 AND 2) below 10^n.." << endl << endl;

  clock_t t0=clock();

  int n=2;
  if(argc == 2) n=atoi(argv[1]);

  int palcount=0;
  size_t sum=0;

  for(int i=1;i<=pow(10,n);i++){
    vector<int> b10;
    digitizer(b10, i);
    vector<int> b2;
    if(palcheck(b10)){
      b2 = binary_digitizer(i);
      
      /*
      cout << "i= ";
      for(int k=0;k<b10.size();k++) cout << b10[k] << " ";
      cout << endl << "in binary= ";
      for(int k=0;k<b2.size();k++) cout << b2[k] << " ";
      cout << endl;
      */

      if(palcheck(b2)){
        sum+=i;
        palcount++;
      }

    }
  }

  cout << "A total of " << palcount << " palindromic numbers (base 10 AND base 2) were found below " << pow(10,n) << endl;
  cout << "Their sum= " << sum << endl;
  cout << "This thing took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms. " << endl;

  return 0;
}







