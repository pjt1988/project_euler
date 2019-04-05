#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv){

  int p=100;
  cout << "Takes p as paramter - the perimeter. Default is " << p << endl;

  clock_t t0 = clock();
  if(argc==2) p=atoi(argv[1]);

  int maxsol=0;
  int maxp=0;
  int numsol;

  for(int i=3;i<=p;++i){
    numsol=0;
    for(int a=1;a<=p-2;++a){
      for(int b=a+1;a+b+sqrt(a*a+b*b) <= i; ++b){
        if(a+b+sqrt(a*a+b*b) == i){
          numsol++;
        }
      }
    }
    if(numsol > maxsol){
      maxsol = numsol;
      maxp = i;
    }
  }

  cout << "The maximum number of right triangles, " << maxsol << ", is found with perimeter p= " << maxp << endl;
  cout << "This thing took " << (double)(clock()-t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;

  return 0;
}


