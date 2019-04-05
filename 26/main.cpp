#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <limits.h>

using namespace std;

int main(int argc, char** argv){
  
  //cout << fixed << setprecision(500);
  clock_t t0 = clock();
  int num=10;
  if(argc > 1) num = atoi(argv[1]);

  vector<int> deci;
  int maxcyc=0;
  int max_top = 1; //denomonator? numerator? fuck it...i already have the degree!

  for(int i=2;i<=num;i++){
    deci.clear();
    int mod_base = 1 % i;
    deci.push_back(mod_base);
    
    bool broken = false;
    int iter=0;
    int modtemp=1;
    while(iter < i && broken == false){
    
      modtemp = deci[iter]*10;
      modtemp = modtemp % i;
      if(modtemp == 0){
        broken=true;
        break;
      }
      
      deci.push_back(modtemp);
      for(int j=0;j<deci.size()-1;j++){
        for(int k=j+1;k<deci.size();k++){
          if(deci[j] == deci[k]){
            broken = true;
            break;
          }
        }
      }
      iter++;
    }

    if(deci.size() > maxcyc){
      maxcyc = deci.size()-1;//damn code..
      max_top = i;
    }
  }

  cout << endl;
  cout << "The longest cycle occurs at 1/" << max_top << " with a length of " << maxcyc << endl;
  cout << "This took " << ((double)clock() - t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;



  return 0;
}
