#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){
  int n;
  if(argc < 2) n=2;
  else n=atoi(argv[1]);

  cout << "Paths along the grid - " << n << "x" << n << endl;

  size_t path_count=1; //ignoring the right edge

  for(int i=0;i<n;i++){
    path_count *= (2*n) - i;
    path_count = path_count / (i+1);
  }

  cout << "There are " << path_count << " paths along this grid. " << endl;



  return 0;
}
