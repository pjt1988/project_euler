#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){

  cout <<"Takes the number-to-be-factored as input. Default n= 600851475143" << endl;

  clock_t t0 = clock();
  size_t n = 600851475143;

  if(argc == 2) n = atoi(argv[1]);

  vector<int> factors;
  vector<int> prime_factors;

  for(int i=2;i<=sqrt(n);i++){
    if(n % i == 0) factors.push_back(i);
  }

  for(int i=1;i<factors.size();i++){
    int check=0;
    for(int j=0;j<i;j++){
      if(factors[i] % factors[j] == 0) check=1;
    }
    if(check==0) prime_factors.push_back(factors[i]);
  }





  //for(int i=2;i<=600851475143;i++){
  //  if(600851475143 % i == 0) factors.push_back(i);
  //}
  
  //truncate dat thang

  cout << "The largest prime factor of n= " << n << " =  " << prime_factors[prime_factors.size()-1] << endl;

  cout << "This thing took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;

  return 0;
}
