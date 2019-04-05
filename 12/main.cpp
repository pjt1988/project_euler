#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main(){

  size_t max_div=0;
  size_t iter=500;
  size_t sum = iter*(iter+1)/2;
  clock_t t = clock();

  while(max_div < 500){
    ++iter;
    sum+=iter;

    size_t ssum = sqrt(sum);
    size_t div_count=2; //1 and sum itself
    for(int i=2;i<=sqrt(sum);i++){
      if(sum % i == 0) div_count+=2;
      }
    if(ssum*ssum == sum) div_count--;
    if(div_count > max_div) max_div = div_count;
    //cout << "iter= " << iter << "    sum= " << sum << "     div_count= " << div_count << "      sqrt(sum)= " << sqrt(sum) << endl;
  }

  clock_t t2 = clock();
  cout << "The first triangle number with " << max_div << " divisors = " << sum << endl;

  cout << "It took " << ((double)t2-t)/CLOCKS_PER_SEC*1000 << "ms." << endl;




  return 0;
}
  

