#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <time.h>


using namespace std;

void digitizer(vector<size_t> &digit, size_t num){
  while(num > 0){
    digit.push_back(num % 10);
    num /= 10;
  }
}

long double fact(size_t num){
  if(num == 1 || num == 0) return 1;
  else return num*fact(num-1);
}


int main(int argc, char** argv){
  
  clock_t t0 = clock();
  
  int n=5;

  if(argc == 2) n=atoi(argv[1]);

  /*
  vector<size_t> digit_facts;
  long double facts[] = {1,1,2,6,24,120,720,5040,40320,362880};

  for(size_t i = 3; i<pow(10,n); i++){
    vector<size_t> digits;
    digitizer(digits,i);
    long double sum =0;
    for(int j=0;j<digits.size();j++) sum += facts[digits[j]];

    if(sum == i){
      cout << "found one! " << i << endl;
      digit_facts.push_back(i);
    }

  }

  size_t sum = 0;
  for(int i=0;i<digit_facts.size();i++) sum += digit_facts[i];

  cout << "A total of " << digit_facts.size() << " digit factorials (?) were found. Their sum= " << sum << endl;
  cout << "This thing took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;

  */

  size_t sumt = 0;
  int count = 0;
  size_t facts[] = {1,1,2,6,24,120,720,5040,40320,362880};

  for(size_t i = 11; i<pow(10,n); i++){
    size_t sum =0;
    int num = i;
    while(num > 0){
      sum+= facts[num % 10];
      num /= 10;
    }
    
    if(sum == i){
      cout << "found one! " << i << endl;
      sumt += sum;
      count++;
    }

  }


  cout << "A total of " << count << " digit factorials (?) were found. Their sum= " << sumt << endl;
  cout << "This thing took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;


  return 0;
}

