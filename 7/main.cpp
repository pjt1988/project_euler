#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){

  clock_t t0 = clock();

  int num_primes=1;
  int max_prime=2;
  int iter=3;
  while(num_primes < 10001){
    int check=0;
    for(int i=2;i<iter;i++){
      if(iter % i == 0){
        check=1;
        break;
      }
    }
    if(check==0){
      num_primes++;
      max_prime=iter;
    }
      
    iter+=2;
  }

  cout << "And the " << num_primes << "st prime number = " << max_prime << endl;
  cout << "The slow way took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms." << endl << endl;


  //
  //that was one way
  //
  //this is another! instead of running the inner loop over all numbers, just check for other prime divisors...


  clock_t t1 = clock();

  vector<int> primes;
  primes.push_back(2);
  iter=3;

  while(primes.size() < 10001){
    int check=0;
    for(int i=0;i<primes.size()-1;i++){
      if(iter % primes[i] == 0){
        check=1;
        break;
      }
    }
    if(check == 0) primes.push_back(iter);
    iter+=2;
  }

  cout << "And the " << primes.size() << "st/nd/rd/th prime = ";
  cout << primes[primes.size()-1] << endl;
  cout << "The smarter way took " << ((double) clock()-t1)/CLOCKS_PER_SEC*1000 << " ms " << endl;

  return 0;

}


