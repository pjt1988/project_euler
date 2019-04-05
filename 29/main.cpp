#include <vector>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

void cull(vector<long double> &A){
  for(int i=0;i<A.size()-1;i++){
    for(int j=i+1;j<A.size();j++){
      if(A[i] == A[j]){
        A.erase(A.begin()+j);
      }
    }
  }
}

int main(int argc, char** argv){

  clock_t t0 = clock();

  int a=5;
  int b=5;

  if(argc == 3){
    a = atoi(argv[1]);
    b = atoi(argv[2]);
  }

  vector<long double> powers;
  for(int i=2;i<=a;i++){
    for(int j=2;j<=b;j++){
      powers.push_back(pow(i,j));
    }
  }

  cout << "Number of all powers prior to culling: " << powers.size() << endl;
  cull(powers);
  cout << "Number of all powers AFTER culling: " << powers.size() << endl;

  cout << "This took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;

  return 0;
}

  





