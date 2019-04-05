#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main(int argc, char** argv){

  if(argc < 2){
    cout << "gotta gib dat big triangle. shuttin down" << endl;
    return 0;
  }
  
  fstream input;
  string line;

  int row = -1;
  input.open(argv[1]);
  while(input.good()){
    getline(input,line);
    row++;
  }
  input.close();

  cout << "File opened. We have " << row << " number of rows. Parsing.." << endl;

  vector< vector<int> > trimat (row);

  input.open(argv[1]);
  int iter=0;
  int num=0;
  for(int i=0;i<row;i++){
    vector<int> buffer;
    int temp;
    getline(input,line);
    char* end;
    stringstream in(line);
    while(in >> temp) buffer.push_back(temp);

    for(int i = 0;i<buffer.size(); i++){
      trimat[iter].push_back(buffer[i]);
      num++;
    }
    iter++;
  }

  input.close();

  cout << "Parsed all " << num << " elements. Doing math.." << endl;
  /*

  for(int i=0;i<row;i++){
    cout << endl;
    for(int j=0;j<trimat[i].size();j++){
      cout << trimat[i][j] << " ";
    }
  }
  cout << endl;
  
  */

  clock_t t0 = clock();
  cout << "Brute force approach..this might just take a while.." << endl;



  clock_t t2 = clock();
  int max_row = trimat.size()-1;
  vector<int> temp;
  vector<int> temp2;

  //possible to do without, but that would destroy the trimat..
  for(int i=0;i<trimat[max_row].size();i++) temp.push_back(trimat[max_row][i]);
  


  for(int i=max_row-1;i>=0;i--){
    for(int j=0;j<trimat[i].size();j++){
      int s1 = trimat[i][j] + temp[j];
      int s2 = trimat[i][j] + temp[j+1];
      if(s1 >= s2) temp2.push_back(s1);
      else temp2.push_back(s2);
    }
    temp.clear();
    for(int j=0;j<temp2.size();j++) temp.push_back(temp2[j]);
    temp2.clear();
  }

  cout << "Done .. hopefully. The sum = ";

  cout << temp[0] << " " << endl;;

  cout << endl << "This took: " << ((double) (clock() - t2) )/CLOCKS_PER_SEC*1000 << " ms. " << endl;



















  return 0;
}




