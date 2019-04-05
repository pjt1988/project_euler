#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;


void sort_array( vector<size_t> &a){                                                                                                                  
  for(int i=1;i<a.size();i++){
    int j=i;
    size_t x=a[i];
    while((j > 0) && (a[j-1] > x)){
              a[j] = a[j-1];
              j--;
      }
   a[j]=x;
  }
}


bool isprime_trunc(vector<size_t> primes, size_t num){
  for(int i=0;primes[i] <= sqrt(num) && i<primes.size();i++){
    if(num % primes[i] == 0) return false;
  }
  for(size_t i = primes[primes.size()-1]; i<=sqrt(num);i+=2){
    if(num % i == 0) return false;
  }
  return true;
}

size_t renumber(vector<size_t> a){
  size_t num=0;
  for(int i=0;i<a.size();i++){
    num+=a[a.size()-1-i]*pow(10,i);
  }
  return num;
}

size_t fact(size_t num){
  if(num == 1 || num == 0) return 1;
  else return num*fact(num-1);
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

void swap(vector<vector<size_t> > &a, int index, int k, int l){
  size_t temp=a[index][k];
  a[index][k]=a[index][l];
  a[index][l]=temp;
}

void reverse(vector<vector<size_t> > &a, int index, int start, int stop){
  for(int i=0;i<a[index].size() && start+i < stop-i;i++){  
  swap(a,index,start+i,stop-i);
  }
}

void copy(vector<vector<size_t> > &a, int index){
  if(index < a.size() - 1){
  for(int i=0;i<a[index].size();i++){
      a[index+1].push_back(a[index][i]);
  }
  }
}

int findk(vector<vector<size_t> > &a, int index){
  int k=0;
  for(int i=0;i<a[index].size()-1;i++){
    if(a[index][i] < a[index][i+1] && k <= i) k=i;
  }
  return k;
}

int findl(vector<vector<size_t> > &a, int index, int k){
  int l=0;
  for(int i=0;i<a[index].size();i++){
    if(a[index][k] < a[index][i] && k <= i) l=i;
  }
  return l;
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
  for(int i=11;i<=pow(10,n);i+=2){
    if(isprime(primes,i)){
      //cout << "i= " << i << " is prime.." << endl;
      primes.push_back(i);
    
      vector<size_t> seq;
      digitizer(seq,i);

      sort_array(seq);
      //cout << "i= " << i << "   ";
      //for(int j=0;j<seq.size();j++) cout << seq[j] << " ";
      //cout << endl;
      //start from ordered sequence! 
  
      size_t num_pert = fact(seq.size());
      vector<vector<size_t> > perts(num_pert);
  
      for(int j=0;j<seq.size();j++){
        perts[0].push_back(seq[j]);
        perts[1].push_back(seq[j]); // initializes the first "true" permutation - same as lexicographically ordered 0th seq, but will get permutated in the loop
      }
  
      for(int j=1;j<perts.size();j++){
        int k=findk(perts,j);
        int l=findl(perts,j,k);
        swap(perts,j,k,l);
        reverse(perts,j,k+1,perts[j].size()-1); 
        copy(perts,j);
        }

      //cout << "i= " << i << "  ";
      bool pcheck=true;
      for(int j=0;j<perts.size();j++){
        size_t temp = renumber(perts[j]);
        pcheck = isprime(primes,temp);
        if(!pcheck) break;
        //cout << temp << " ";
        //cout << endl;
        for(int k=0;k<cyc_prime.size();k++){
          //cout << "cyc_k = " << cyc_prime[k] << "  temp= " << temp;
          if(cyc_prime[k] == temp){
           pcheck = false;
           j=perts.size();
           break;
          }
        }
        }
      if(pcheck) cyc_prime.push_back(i);
    }
  }
  for(int i=0;i<cyc_prime.size();i++) cout << cyc_prime[i] << endl;

  cout << "A total of " << cyc_prime.size() << " cyclic primes were found below " << pow(10,n) << ". Kinda skewed, cuz all primes <10 are cyclic.." << endl;
  cout << "This thing took " << ((double) clock()-t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;

  return 0;


}
