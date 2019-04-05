#include <iostream>
#include <time.h>

using namespace std;

int main(){

  int n=100000000;
  size_t sum_squares=0;
  size_t square_sum=0;

  cout << "Going to n=" << n << ".." << endl;
  clock_t t;
  t = clock();
 

  for(int i=1;i<=n;i++){
    sum_squares+=i*i;
    square_sum+=i;
  }

  cout << "The difference between the square of the sum, and the sum of the squares = " << square_sum*square_sum - sum_squares << endl;

  clock_t t2 = clock();
  cout << "It took " << ((double)t2-t)/CLOCKS_PER_SEC*1000.0 << " ms." << endl; 

  cout << "And the smarter way: " << endl;

  long double sum_s = (n*(n + 1)*(2*n + 1))/6;
  long double s_sum = (n*(n + 1))/2;
  clock_t t3=clock();

  cout << "The difference between the square of the sum, and the sum of the squares = " << square_sum*square_sum - sum_squares << endl;

  cout << "It took " << ((double)t3-t2)/CLOCKS_PER_SEC*1000.0 << " ms." << endl;

  
  
  return 0;
}
