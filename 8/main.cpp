#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){

  if(argc < 2){
    cout << "you should really supply that number in a convenient file..." << endl;
    terminate();
  }

  vector<int> digits;

  char* in_file = argv[1]; 
  ifstream input;
  input.open(in_file);



  //fuck yo shit! 
  while(input.good()){
      string line;
      getline(input,line);
      if(line != ""){

        char* dump = new char[line.size() + 1];
        copy(line.begin(),line.end(),dump);
          

        for(int i=0;i<line.size();i++){
          int dummy = dump[i] - 48;
          digits.push_back( dummy );
        }

        delete[] dump;
       
        /*
        buffer = strtol(line.c_str(), &end, 0);
        //buffer = boost::lexical_cast<int>(line);
        int temp=buffer;
        int reffub=0;

        while(reffub > 0){
          digits.push_back(reffub % 10);
          reffub = reffub / 10;
        }
        */
      }
  }

  input.close();


  for(int i=0;i<digits.size();i++) cout << digits[i] << " ";
  cout << endl;

  size_t max=0;
  int start=0;
  for(int i=0;i<digits.size()-13;i++){
    size_t product=1;
    for(int j=i;j<i+13;j++){
      product*=digits[j];
    }
    if(product > max){
      max = product;
      start=i;
    }
  }

  cout << "And the largest product of 13 adjacent digits= " << max << endl;
  
  cout << "This is the product of: ";
  for(int i=start;i<start+12;i++){
    cout << digits[i] << "*";
  }
  cout << digits[start+12] << "." << endl;





  return 0;
}

       











