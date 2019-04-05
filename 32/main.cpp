#include <vector>
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

void elim(vector<size_t> &digits){
  for(int i=0;i<digits.size()-1;i++){
    for(int j=i+1;j<digits.size();j++){
      if(digits[i] == digits[j]) digits.erase(digits.begin() + j);
    }
  }
}


void elim_dupes(vector<size_t> &counter){
  for(int i=1;i<counter.size();i++){
      if(counter[i] != 1) counter.erase(counter.begin() + i);
    }
}



void digitizer(vector<size_t> &digits, size_t num){
  while(num > 0){
    size_t digit = num % 10;
    num = num / 10;
    digits.push_back(digit);
  }
}

bool panchecker(vector<size_t> num, int n){
  
  vector<size_t> check(n+1);
  for(int i=0;i<num.size();i++){
    for(int j=0;j<=n;j++){
      if(num[i] == j){
        check[j] += 1;
      }
    }
  }
  elim_dupes(check);
  if(check[0] == 0 && check.size() == n+1) return true;
  else return false;
}


int main(){
  clock_t t0 = clock();
  int n=9;

  vector<size_t> digits;

  vector<size_t> pan;

  for(int i=1;i<pow(10,2);i++){
    //for(int j=pow(10,4); i*j*i*j < pow(10,n+1) && i*j*i*j > pow(10,n-1); j--){
    for(int j=pow(10,4);j>pow(10,2);j--){
          digits.clear();
          size_t pro = i*j;
          digitizer(digits, i);
          digitizer(digits, j);
          digitizer(digits, pro);

          if(panchecker(digits, n) == true){
            cout << "i= " << i << " j= " << j << "  i*j= " << pro << endl;
            pan.push_back(pro);
          }
    }
  }


  elim(pan);

  size_t sum=0;
  for(int i=0;i<pan.size();i++){
    sum+=pan[i];
  }

  cout << "A total of " << pan.size() << " pandigital numbers were found." << endl;
  cout << "Their sum happens to be " << sum << endl;
  cout << "This spiel took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms. " << endl;

  return 0;
}

