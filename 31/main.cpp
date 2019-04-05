#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv){

  clock_t t0 = clock();
  int total = 200;
  if(argc == 2) total = atol(argv[1]);

  int p1=1;
  int p2=2;
  int p5=5;
  int p10=10;
  int p20=20;
  int p50=50;
  int l1=100;
  int l2=200;

  int max_p1=total/p1;
  int max_p2=total/p2;
  int max_p5=total/p5;
  int max_p10=total/p10;
  int max_p20=total/p20;
  int max_p50=total/p50;
  int max_l1=total/l1;
  int max_l2=total/l2;


  int combinations=0;

  for(int i1=0;i1<=max_p1;i1++){
    int t=0;
    for(int i2=0;i2<=max_p2;i2++){
      for(int i3=0;i3<=max_p5;i3++){
        for(int i4=0;i4<=max_p10;i4++){
          for(int i5=0;i5<=max_p20;i5++){
            for(int i6=0;i6<=max_p50;i6++){
              for(int i7=0;i7<=max_l1;i7++){
                for(int i8=0;i8<=max_l2;i8++){
                  t=i1*p1 + i2*p2 + i3*p5 + i4*p10 + i5*p20 + i6*p50 + i7*l1 + i8*l2;
                  if(t==total){
                    cout << "combination found! " << i1 << " 1p, " << i2 << " 2p " << i3 << " 5p " << i4 << " 10p " << i5 << " 20p " << i6 << " 50p " << i7 << " 1# " << i8 << " 2# " << endl;
                    combinations++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  cout << "In total, " << combinations << " were found." << endl;
  cout << "This took " << ((double) clock() - t0)/CLOCKS_PER_SEC*1000 << " ms." << endl;


  return 0;
}
