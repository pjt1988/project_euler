#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>


using namespace std;

int main(int argc, char** argv){
  int n;
  if(argc < 2) n=10;
  else n=atoi(argv[1]);

  cout << "Brute force.." << endl;

  long double num = pow(2,n);

  //long double digit = ((num/10) - floor((long double)num/10.0))*10;
  
  ostringstream ss;
  ss << setprecision(600) << num;
  string dummy = ss.str();

  cout << "Apparently this thing is " << dummy.size() << " digits long." << endl;

  char* digits = new char[dummy.size()];
  strcpy(digits,dummy.c_str());

  size_t sum=0;
  for(int i=0;i<dummy.size();i++){
    sum += ((int) digits[i] - 48);
  }

  cout << "The sum of the digits of the bigass number= " << sum << endl;

  





  return 0;
}
