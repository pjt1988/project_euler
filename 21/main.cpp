#include <stdlib.h>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

size_t sum_div(size_t num){
  vector<size_t> div;
  for(int i=1;i<num;i++){
    if(num % i == 0) div.push_back(i);
  }

  size_t sum=0;
  for(int i=0;i<div.size();i++) sum+=div[i];
  return sum;
}

int main(int argc, char** argv){
  int num = 10;
  if(argc > 1) num = atoi(argv[1]);

  vector<size_t> amic;

  for(int i=2;i<=num;i++){
    size_t sum1 = sum_div(i);
    size_t sum2 = sum_div(sum1);
    //cout << "i= " << i << "  sum1= " << sum1 << "  sum2= " << sum2 << endl;
    if(sum2 == i && i != sum1 ){
      amic.push_back(i);
      cout << "Amicable number found: " << i << endl;
    }
  }

  size_t sum=0;
  for(int i=0;i<amic.size();i++) sum+=amic[i];

  cout << "The sum of all " << amic.size() << " amicable numbers = " << sum << endl;



  return 0;
}

