#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <time.h>

using namespace std;

size_t fact(size_t num){
  if(num <= 1) return 1;
  return num*fact(num-1);
}

bool is_prime(vector<size_t> primes, size_t num){
  for(int i=0; primes[i] <= sqrt(num); i++) if(num % primes[i] == 0) return false;

  return true;
}

bool is_pan(size_t num){
  return false;
}

void digitizer(vector<size_t> &digits, size_t num){
  while(num > 0){
    digits.push_back( num % 10);
    num /= 10;
  }
}

int main(int argc, char** argv){

  cout << "Usage: takes 2 paramters: 10^a to 10^b. Returns largest pandigital prime in between those. Default is a=1, b=3 " << endl;

  clock_t t0 = clock();

  int a=1;
  int b=3;

  if(argc == 3){
    a = atoi(argv[1]);
    b = atoi(argv[2]);
  }

  vector<size_t> primes;
  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(5);
  primes.push_back(7);

  if(primes.back() < sqrt(pow(10, a))){
    for(size_t i = primes.back(); primes.back() <= sqrt(pow(10,a));i+=2){
      if(is_prime(primes, i)) primes.push_back(i);
    }
    cout << "Generating the necessary primes took " << ((double) clock() - t0)/CLOCKS_PER_SEC*1000 << " ms. " << endl;
  }

  size_t max_pan = 0;

  for(size_t i=pow(10,a) + 1; i < pow(10,b); i+=2){

    if(is_prime(primes, i)){
      primes.push_back(i);

      if(is_pan(i)){
        if(i > max_pan) max_pan = i;
      }
    }
  }

  cout << "The largest pan-prime between 10^" << a << " and 10^" << b << " = " << max_pan << endl;
  cout << "This thing took " << ((double)  clock() - t0)/CLOCKS_PER_SEC*1000 << " ms " << endl;

  return 0;
}





