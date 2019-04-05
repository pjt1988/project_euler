#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include <sstream>

using namespace std;

int main(int argc, char** argv){

  cout << "Usage: takes max_digit as paramter - up to which digit the product is evaluated. Default: 1000000 "<< endl;

  clock_t t0 = clock();
  int max_digit = 1000000;

  if(argc == 2) max_digit = atoi(argv[1]);
  int max_deg = log10(max_digit) ;

  int deg = 0;
  while(max_digit > 0){
    max_digit -= 9*pow(10,deg);
    ++deg;
  }
  deg--;

  string digits;

  for(int i=1;i<=pow(10,deg);++i){
    stringstream conv;
    conv << i;
    string temp = conv.str();
    digits.append(temp);
    
  }

  if(digits.size() < 100) cout << digits << endl;
  
  size_t pro=1;
  for(int i=0;i<=max_deg;++i){
    int pos = pow(10,i) - 1;
    cout << digits[pos] << endl;

    pro *= ((size_t)digits[pos] -48 );
  }

  cout << "The product of all digits from 10^0 to 10^" << max_deg << " = " << pro << endl;
  cout << "This thing took " << ((double) clock() - t0)/CLOCKS_PER_SEC*1000 << " ms. " << endl;

  return 0;
}
