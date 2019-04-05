#include <cmath>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <iomanip>
#include <stdarg.h>
#include <gmp.h>

using namespace std;

long double fact(long double num){
  if(num == 1 || num == 0) return 1;
  else return num*fact(num-1);
}





int main(int argc, char** argv){

  clock_t t0 = clock();
  int num = 10;
  if(argc > 1) num = atoi(argv[1]);

  long double pro = 1;
  int deccount=0;
  for(long double i=2; i<=num; i+=1){
    long double mult;
    if((int) i % 100 == 0){
      mult= (long double) i/100.0;
      pro = (long double) pro*mult;
      deccount+=2;
    }
    else if((int) i % 10 == 0){
      mult=(long double) i/10.0;
      pro = (long double) pro*mult;
      deccount++;
    }
    else pro = (long double) pro*i;
  }




  ostringstream ss;                                                                                                                                                 
  ss << setprecision(600) << pro;
  string dummy = ss.str();
  long double dec = pow(10, deccount);
  //cout << setprecision(600) << pro << endl;
 
  cout << "Apparently this thing is " << dummy.size() << " digits long." << endl;
  char* digits = new char[dummy.size()];
  strcpy(digits,dummy.c_str());
  size_t sum=0;
  cout << endl;
  for(int i=0;i<dummy.size();i++){
      sum += ((int) digits[i] - 48);
      cout << digits[i];
    }

  cout << endl;
  cout << "The sum of digits= " << sum << endl;
  cout << "This thing took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;

  pro=0;
  dummy.clear();
  ss.str("");
  ss.clear();



  cout << endl << endl << "OK, my factorial function is fine, but machien precision..gamma function then. " << endl;
  pro = round(tgamma(num+1));
  ss << setprecision(600) << pro;
  dummy = ss.str();
  //cout << setprecision(600) << pro << endl;
 
  cout << "Apparently this thing is " << dummy.size() << " digits long." << endl;
  char* digits2 = new char[dummy.size()];
  strcpy(digits2,dummy.c_str());
  sum=0;
  cout << endl;
  for(int i=0;i<dummy.size();i++){
      sum += ((int) digits2[i] - 48);
      cout << digits2[i];
    }
  cout << endl;
  cout << "The sum of digits= " << sum << endl;
  cout << "This thing took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;

  pro=0;
  ss.str("");
  ss.clear();
  dummy.clear();
  
  cout << endl << endl << "Fuck you!!! Recursive factorial! "<< endl;
  pro = fact(num);
 
  ss << setprecision(600) << pro;
  dummy = ss.str();
 
  cout << "Apparently this thing is " << dummy.size() << " digits long." << endl;
  char* digits4 = new char[dummy.size()];
  strcpy(digits4,dummy.c_str());
  sum=0;
  cout << endl;
  for(int i=0;i<dummy.size();i++){
      sum += ((int) digits4[i] - 48);
      cout << digits4[i];
    }
  cout << endl;
  cout << "The sum of digits= " << sum << endl;
  cout << "This thing took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;

  cout << endl << endl << endl;
  cout << "k...gmp library. I will solve this fucker proper like! " << endl;

  mpz_t n;
  mpz_t n2;

  mpz_init(n);
  mpz_set_ui(n,100);













  return 0;

}
