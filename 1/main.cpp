#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void){

  //testing premise
  vector<int> mult_3;
  vector<int> mult_5;

  for(int i=1;i<10;i++){
    if(i % 3 == 0) mult_3.push_back(i);
    if(i % 5 == 0) mult_5.push_back(i);
  }

  int sum=0;
  for(int i=0;i<mult_3.size();i++) sum+=mult_3[i];
  for(int i=0;i<mult_5.size();i++) sum+=mult_5[i];

  cout << "The sum of all multiples of 3 or 5 less than 10 = " << sum << endl;

  //much success was had!
  
  for(int i=10;i<1000;i++){
    if(i % 3 == 0) mult_3.push_back(i);
    else if(i % 5 == 0) mult_5.push_back(i);
  }
  sum=0;
  for(int i=0;i<mult_3.size();i++) sum+=mult_3[i];
  for(int i=0;i<mult_5.size();i++) sum+=mult_5[i];
   
  cout << "The sum of all multiples of 3 or 5 less than 1000 = " << sum << endl;
  return 0;
}
