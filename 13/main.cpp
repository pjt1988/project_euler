#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(int argc, char** argv){
  if(argc == 1){
    cerr << "Gotta supply da number, brah! "<< endl;
    terminate;
  }
  
  vector<double> bigass_num;
  ifstream input;
  input.open(argv[1]);

  string line;
  char* end;
  while(input.good()){
    getline(input, line);
    if(line!=""){
      double dummy = strtold(line.c_str(), &end);
      bigass_num.push_back(dummy);
    }
  }

  cout << "File apparently read. Found: " << bigass_num.size() << " entries." << endl;

  double sum=0;
  for(int i=0;i<bigass_num.size();i++){
    sum+=bigass_num[i];
  }

  cout << "Sum of bigass numbers = " << setprecision(52) << sum << endl;



  
  
  return 0;
}
