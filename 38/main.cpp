#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <cmath>

using namespace std;

size_t fact(size_t num){
  if(num < 2) return 1;
  return num*fact(num-1);
}

void digitizer(vector<size_t> &a, size_t num){
  while(num > 0){
    a.push_back(num % 10);
    num /= 10;
  }
}

bool ispan(vector<size_t> a, size_t n){
  vector<size_t> digits(n+1);
  for(int i=0;i<a.size();i++){
    for(size_t j=1;j<=n;j++){
      if(a[i] == j) digits[j]+=1;
    }
  }
  for(int i=1;i<=n;i++){
    if(digits[i] != 1) return false;
  }
  return true;
}


int main(int argc, char** argv){
  
  clock_t t0 = clock();

  cout << "Usage: takes n as paramter - as in how many digits to check." << endl << endl;
  
  size_t n=4;
  if(argc==2) n=atoi(argv[1]);


  vector<size_t> concact;
  concact.push_back(1);
  size_t maxpan=0;

  for(size_t i = 2;i<=n;i++){
    concact.push_back(i);
    int size = concact.size();
    size_t min = (double) pow(10, (((n - 1 ) - size*log10(fact(size)))/size));
    size_t max = (double) pow(10, (((n ) - size*log10(fact(size)))/size));

    //min=1;
    //max=10;

    //for(int k=0; k<concact.size();k++) cout << concact[k] << " ";
    //cout << "  ";
    //cout << "size_concact= " << concact.size() << " min= " << min << " max= " << max << " c_pro= ";

    for(size_t j=min;j<max;j++){
      int deg=0;
      size_t c_pro=0;
      for(int k=concact.size()-1;k>=0;k--){
        size_t temp=concact[k]*j;
        c_pro += pow(10,deg)*temp;
        deg += log10(temp)+1;
      }
      //cout << c_pro << endl;

      if(c_pro > pow(10,n-1) && c_pro < pow(10,n)){
        vector<size_t> digits;
        digitizer(digits,c_pro);
        if(ispan(digits,n)){
          if(c_pro > maxpan) maxpan = c_pro;
        }
      }
    }
  }

  cout << "The largest n=" << n << " digit pandigit number formable= " << maxpan << endl;
  cout << "This thing took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;





















  return 0;
}

