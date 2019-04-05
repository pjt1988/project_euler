#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

void sort_array (vector <string> &a){    
  for(int i=1;i<a.size();i++){
    int j=i;
    string x=a[i];
    while((j > 0) && (a[j-1] > x)){
      a[j] = a[j-1];
      j--;
      }
    a[j]=x;
  }
}



int main(int argc, char** argv){

  if(argc < 2){
    cout << "You really gotta supply a file for this, dude ..." << endl;
    return 1;
  }
  char* filename = argv[1];
  ifstream input;
  input.open(filename);

  int linecount=-1;
  vector<string> names;
  string line;
  while(input.good()){
    getline(input,line);
    if(line!=""){
      string element;
      stringstream buffer(line);
      while(buffer >> element) names.push_back(element);
    }
    linecount++;
  }

  if(linecount > 1){
    cout << "More than 1 line found. File dun fucked." << endl;
    terminate();
  }

  input.close();

  cout << "File read - " << names.size() << " elements found on " << linecount << " lines" << endl;

  sort_array(names);

  size_t sum_total=0;
  for(int i=0;i<names.size();i++){
    char* dummy = new char[names[i].size() ];
    copy(names[i].begin(),names[i].end(),dummy);
    size_t sum_temp=0;
    for(int j=0;j<names[i].size();j++) sum_temp+=((int) dummy[j] - 64);
    sum_total+=(i+1)*sum_temp;
  }

  cout << "The sum of all name scores (yes, this is idiotic..) in the entire file= " << sum_total << endl;



  return 0;
}
      
