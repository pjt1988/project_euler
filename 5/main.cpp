#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main(){

  int smallest;
  int ops_count=0;
  for(size_t i=9699690;i<numeric_limits<size_t>::max();i+=9699690){ //there is no such thing as overkill!
    ops_count++;
    int check=0;
    for(int j=2;j<=20;j++){
      ops_count++;
      if(i % j != 0){
        check=1;
        break;
      }
    }
    if(check==0){
      smallest=i;
      break;
    }
  }

  cout << "The smallest positive number evenly divisible by all numbers from 1..20 = " << smallest << endl;

  cout << "This thing went over " << ops_count << " combinations to reach the answer " << endl;

  return 0;
}


