#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

void digitMaker(vector<int> &A, size_t i){
  while(i > 0){
    A.push_back(i % 10);
    i /= 10;
  }
}

int main(int argc, char** argv){
  
  clock_t t0 = clock();
  
  int n=1000;
  int p=5;
  if(argc == 2) n = atoi(argv[1]);

  if(argc == 3){
    n=atoi(argv[1]);
    p=atoi(argv[2]);
  }

  vector<size_t> digsum;
  vector<int> digits;

  for(int i=2;i<=n;i++){

    digits.clear();
    digitMaker(digits,i);
    size_t sum=0;

    for(int j=0;j<digits.size();j++) sum += pow(digits[j],p);

    if(sum == i) digsum.push_back(i);

  }

  cout << "The number of all numbers whose sum of digits^" << p << " is itself= " << digsum.size() << endl;
  cout << "Test...obviously. Only numbers between 2 and " << n << " were considered. " << endl;

  int sum=0;
  for(int i=0;i<digsum.size();i++){
    cout << digsum[i] << endl;
    sum+=digsum[i];
  }
  cout << "Their sum happens to be: " << sum << endl;



  cout << "This took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;


  return 0;
}






