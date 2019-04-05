#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

size_t div_sum(size_t num){
  size_t sum=0;
  for(int i=1;i<=num/2;i++){
    if(num % i == 0) sum+=i;
  }
  return sum;
}

bool sumcheck(size_t num, vector<size_t> abundant){
  for(int j=0;abundant[j]<num && j<abundant.size();j++){
    for(int k=j;abundant[k]<num && k<abundant.size();k++){
      if(abundant[j]+abundant[k] == num){
        return true;
      }
    }
  }
  return false;
}



int main(int argc, char** argv){
  clock_t t0 = clock();
  int num=20;
  if(argc > 1) num = atoi(argv[1]);

  vector<size_t> abundant;
  for(int i=2;i<num;i++) if(div_sum(i) > i) abundant.push_back(i);

  cout << "A total of " << abundant.size() << " abundant numbers were found below " << num << endl;

  //i presume all numbers below the smallest abundant number count towards the sum..
  
  size_t sum = 0;
  vector<size_t> unsum_ints;
  vector<size_t> summed(num,1);
  size_t unsummable=0;

  for(int i=0;i<abundant.size();i++){
    for(int j=i;j<abundant.size()-1;j++){
      if(abundant[j]+abundant[i] <= num) summed[abundant[i]+abundant[j]] = 0;
    }
  }

  //for(int i=1;i<num;i++){
  //  if(sumcheck(i,abundant) == false) unsum_ints.push_back(i);
  //}

  //for(int i=0;i<unsum_ints.size();i++){
    //cout << unsum_ints[i] << endl;
   // sum+=unsum_ints[i];
  //}
  
  for(int i=1;i<summed.size();i++){
    if(summed[i] > 0) sum+= i;
    else unsummable++;
  }

  cout << "The sum of all " << unsummable << " unsummable integers = " << sum << endl;
  cout << "Brute force. This took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000.0 << " ms" << endl;




  return 0;
}



