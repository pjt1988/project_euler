#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  vector<int> fibo;
  fibo.push_back(1);
  fibo.push_back(2);

  int sum=0;

  int iter=1;
  while(fibo[iter]<4000000){
    fibo.push_back(fibo[iter]+fibo[iter-1]);
    if(fibo[iter] % 2 == 0) sum+=fibo[iter];
    iter++;
  }

  cout << "The sum of all even Fibonacci numbers below 4,000,000 is " << sum << endl;

  return 0;
}
