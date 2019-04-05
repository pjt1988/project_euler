#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

size_t renumber(vector<size_t> a){
  size_t num=0;
  for(int i=0;i<a.size();i++){
    num+=a[i]*pow(10,i);
  }
  return num;
}


bool isprime(vector<size_t> primes, size_t num){
  for(int i=0;primes[i] <= sqrt(num);i++){
    if(num % primes[i] == 0) return false;
  }
  return true;
}

void digitizer(vector<size_t> &a, size_t num){
  while(num > 0){
    a.push_back(num % 10);
    num /= 10;
  }
}

int main(int argc, char** argv){
  
  cout << "Input: n - as in 10^n. Default is n=2" << endl << endl;
  
  clock_t t0 = clock();

  int n=2;


  if(argc == 2 ) n = atoi(argv[1]);


  vector<size_t> cyc_prime;
  vector<size_t> primes;

  cyc_prime.push_back(2); //gotta start somewhere..
  primes.push_back(2);

  for(int i=3;i<11;i+=2) if(isprime(primes, i)){
    cyc_prime.push_back(i);
    primes.push_back(i);
  }




  //no point in going through the permutations for n<11..
  for(size_t i=11;i<=pow(10,n);i+=2){
    if(isprime(primes,i)){
      //cout << "i= " << i << " is prime.." << endl;
      primes.push_back(i);
    
      vector<size_t> seq;
      digitizer(seq,i);

      size_t num_cyc = seq.size();
      vector<size_t> cycs;
  
      cycs.push_back(renumber(seq));
  
      for(int j=1;j<num_cyc;j++){
        size_t first = seq[0];
        seq.push_back(first);
        seq.erase(seq.begin());
        cycs.push_back(renumber(seq));
      }

      bool pcheck=true;
      for(int j=0;j<num_cyc && pcheck == true;j++){
        size_t temp = cycs[j];
        pcheck = isprime(primes,temp);
        if(!pcheck) break;
        //cout << temp << " ";
        //cout << endl;
        //for(int k=0;k<cyc_prime.size();k++){
          //cout << "cyc_k = " << cyc_prime[k] << "  temp= " << temp;
          //if(cyc_prime[k] == temp){
          // pcheck = false;
          // j=num_cyc;
          // break;
          //}
        //}
        //cout << endl;
        }
      if(pcheck) cyc_prime.push_back(i);
    }
  }
  for(int i=0;i<cyc_prime.size();i++) cout << cyc_prime[i] << endl;

  cout << "A total of " << cyc_prime.size() << " cyclic primes were found below " << pow(10,n) << ". Kinda skewed, cuz all primes <10 are cyclic.." << endl;
  cout << "This thing took " << ((double) clock()-t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;

  return 0;


}
