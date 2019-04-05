#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <time.h>


using namespace std;

bool isprime(vector<size_t> primes, size_t num){
  if(num == 1) return false;
  for(int i=0;primes[i] <= sqrt(num);i++){
    if(num % primes[i] == 0) return false;
  }
  return true;
}

void digitizer(vector<size_t> &digits, size_t num){
  while(num > 0){
    digits.push_back(num % 10);
    num /= 10;
  }
}

size_t renumber(vector<size_t> vec){
  size_t sum=0;
  for(int i=0;i<vec.size();i++){
    sum+=vec[i]*pow(10,i);
  }
  return sum;
}

size_t rerenumber(vector<size_t> vec){
  size_t sum=0;
  for(int i=0;i<vec.size();i++) sum+= vec[vec.size() -1 -i]*pow(10,i);
  return sum;
}

int main(int argc, char** argv){

  cout << "Input n - check all truncatable primes up until (and including) 10^n. Default: n=2" << endl << endl;

  clock_t t0=clock();

  int n=2;
  if(argc==2) n=atoi(argv[1]);

  vector<size_t> truncable;
  vector<size_t> primes;

  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(5);
  primes.push_back(7); //i think i've shown these to be prime often enough..

  for(size_t i=11;i<pow(10,n) && truncable.size() <= 11;i+=2){

    bool pcheck = isprime(primes,i);

    if(pcheck == true){
      //cout << "i= " << i << " is prime! " << endl;
      primes.push_back(i);
      //vector<size_t> redig;
      //digitizer(redig,i);
      //pcheck = isprime(primes,rerenumber(redig));
      //cout << " rerenumber= " << rerenumber(redig) << " is prime= " << pcheck << endl;
    }

    if(pcheck == true){
      vector<size_t> digits;
      digitizer(digits,i);
      digits.erase(digits.begin());

      while(digits.size() > 0 && pcheck == true){
        pcheck = isprime(primes,renumber(digits));
        //cout << "i= " << i << "  renumbered= " << renumber(digits) << "  pcheck= " << (bool) pcheck << endl;
        digits.erase(digits.begin());
      }
    }

  

    if(pcheck==true){
      vector<size_t> redig;
      digitizer(redig,i);
      redig.erase(redig.begin() + redig.size() - 1);
      while(redig.size() > 0 && pcheck == true){
        pcheck = isprime(primes,renumber(redig)); 
        //cout << "i= " << i << "  rereenumbered= " << renumber(redig) << "  pcheck= " << (bool) pcheck << endl;
        redig.erase(redig.begin() + redig.size() -1 );
      }
    }
      
     if(pcheck == true) truncable.push_back(i);

  }

  size_t sum=0;
  for(int i=0;i<truncable.size();i++) sum+=truncable[i];

  for(int i=0;i<truncable.size();i++) cout << truncable[i] << endl;

  cout << "A total of " << truncable.size() << " truncatable primes were found. The sum of the first 11 = " << sum << endl;
  cout << "This thing took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms. " << endl;


  //
  //Now da smarter way...no need to use vectors
  //

  cout << endl << endl;

  truncable.clear();
  primes.clear();

  clock_t t1 = clock();

  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(5);
  primes.push_back(7);

  size_t iter=11;
  size_t max=pow(10,n);
  sum=0;
  while(truncable.size() <= 11 && iter < max){

    if(isprime(primes,iter)){

      primes.push_back(iter);
      bool pcheck = true;
      size_t from_left = iter;

      while(from_left > 0 && pcheck){
        //cout << from_left << endl;
        int deg = log(from_left)/log(10);
        //cout << deg << endl;
        from_left = from_left % (size_t) pow(10,deg);
        pcheck = isprime(primes,from_left);
      }

      if(pcheck == true){
        size_t from_right = iter;
        while(from_right > 0 && pcheck){
          from_right /= 10;
          pcheck = isprime(primes,from_right);
        }
      }

      if(pcheck){
        truncable.push_back(iter);
        sum+=iter;
      }
    }

    iter+=2;
  }

  for(int i=0;i<truncable.size();i++) cout << truncable[i] << endl;

  cout << "Da smarter way (?) There be " << truncable.size() << " bi-truncatable primes. Their sum= " << sum << endl;
  cout << "This enterprise done took me " << ((double)clock()-t1)/CLOCKS_PER_SEC*1000 << " ms." << endl;



        






  return 0;
}








