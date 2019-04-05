#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

using namespace std;

void elimdupes(vector<int> &seq){
  for(int i=0;i<seq.size()-1;i++){
    for(int j=i+1;j<seq.size();j++){
      if(seq[i] == seq[j]) seq.erase(seq.begin()+j);
    }
  }
}

bool isprime(int n){
  if(n % 2 == 0) return false;
  for(int i=3;i<=sqrt(n);i+=2){
    if(n % i == 0) return false;
  }
  return true;
}

int main(int argc, char** argv){

  clock_t t0 = clock();

  int a = 10;
  int b = 50;
  if(argc > 2){
    a = atoi(argv[1]);
    b = atoi(argv[2]);
  }

  cout << "Brute force.." << endl;

  vector<int> primes;
  int maxsize=0;
  int max_a = 0;
  int max_b = 0;

  for(int i=-1*a;i<=a;i++){
    for(int j=-1*b;j<=b;j++){

      bool seq = true;
      int iter = 0;
      primes.clear();
      while(seq == true && iter < INT_MAX){
        int num = (iter*iter) + (i*iter) + j;
        //cout << "iter= " << iter << " num= " << num << endl;
        if(isprime(abs(num)) == true){
          primes.push_back(num);
        }
        else{
          seq=false;
        }
        iter++;
      }
      if(primes.size() >= maxsize){

        //elimdupes(primes);
        //cout << endl;
        //for(int m=0;m<primes.size();m++) cout << primes[m] << " " ;

        maxsize = primes.size();
        max_a= i;
        max_b= j;
      }
    }
  }

  cout << endl;

  cout << "Done..apparently. The longest sequence of consequetive primes obtained from n*n + an + b has a length of " << maxsize << ". The coefs are: a= " << max_a << ", max_b = " << max_b << ". The product= " << max_a*max_b << endl;
  cout << "The brute force approach took  " <<  ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;

  return 0;

}





