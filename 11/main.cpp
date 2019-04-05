#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
  
  if(argc < 2){
    cout << "Dat grid...man, I can't fucking find it!!" << endl;
    return 1;
  }
  clock_t t0 = clock();

  fstream in;
  int linecount=0;
  in.open(argv[1]);
  string line;
  while(in.good()){
    getline(in,line);
    if(line!="") linecount++;
  }
  in.close();

  cout << "File read. Turns out there are " << linecount << " lines in there. Building matrix.." << endl;

  vector<vector<int > > mat (linecount);

  int iter=0;
  in.open(argv[1]);
  while(in.good()){
    getline(in,line);
    if(line!=""){
      int buffer;
      stringstream ss(line);
      while(ss >> buffer) mat[iter].push_back(buffer);
    }
    iter++;
  }

  size_t maxpro=0;
  vector<int> numbers;
  for(int i=0;i<mat.size();i++){
    size_t trialpro = 1;
    for(int j=0;j<mat[i].size();j++){

      //vertical - down
      trialpro=1;
      if(i<mat.size()-4){
        for(int k=0;k<4;k++){
          trialpro*=mat[i+k][j];
        }
        if(trialpro > maxpro){
          maxpro = trialpro;
          numbers.clear();
          for(int k=0;k<4;k++) numbers.push_back(mat[i+k][j]);
        }
      }

      //horizontal - right
      trialpro=1;
      if(j<mat[i].size() -4) {
        for(int k=0;k<4;k++){
          trialpro*=mat[i][j+k];
        }
        if(trialpro > maxpro){
          numbers.clear();
          maxpro = trialpro;
          for(int k=0;k<4;k++) numbers.push_back(mat[i][j+k]);
        }
      }

      //diagonal - right, down
      trialpro=1;
      if(i<mat.size()-4 && j<mat[i].size()-4){
        for(int k=0;k<4;k++){
          trialpro*=mat[i+k][j+k];
        }
        if(trialpro > maxpro){
          maxpro = trialpro;
          numbers.clear();
          for(int k=0;k<4;k++) numbers.push_back(mat[i+k][j+k]);
        }
      }

      //diagonal - right, up
      trialpro=1;
      if(i>=3 && j<mat[i].size()-4){
        for(int k=0;k<4;k++){
          trialpro*=mat[i-k][j+k];
        }
        if(trialpro > maxpro){
          maxpro = trialpro;
          numbers.clear();
          for(int k=0;k<4;k++) numbers.push_back(mat[i-k][j+k]);
        }
      }
    }
  }


  cout << "All done..I think. The max product of any 4 adjacent numbers = " << maxpro << endl;
  cout << "The constituent numbers: ";
  for(int i=0;i<numbers.size();i++) cout << numbers[i] << " ";
  cout << endl;
  cout << "This took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;

  return 0;
}

