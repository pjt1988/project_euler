#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){

  int n;
  if(argc > 1) n = atoi(argv[1]);
  else n=1000000;

  cout << "The stupid way: straightup chain up to n= " << n << endl;
  clock_t t0 = clock();

  int maxlength=1;
  int largest_collatz=2;

  for(int i=2;i<=n;i++){

    size_t num=i;
    int s_length=1;
    while(num>1){
      if(num % 2 == 0){
        num=num/2;
        s_length++;
      }
      else{
        num=3*num + 1;
        s_length++;
      }
    }
    if(s_length > maxlength){
      maxlength=s_length;
      largest_collatz=i;
    }
  }

  cout << "The longest Collatz chain corresponds to a starting value of " << largest_collatz << ". It has a length of " << maxlength << endl;

  cout << "This thing took: " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms " << endl;


  //
  //
  //
  
  
  cout << "Smarter way: keeping track of sequences " << endl;

  clock_t t1 = clock();
  maxlength=1;
  largest_collatz=2;

  vector<int> sequences(n+2); //initialized at 0 - no need to alter
  sequences[1]=1;

  for(int i=2;i<=n;i++){
    size_t num=i;
    int s_length=1;

    while(num > 1){

      //cout << "num= " << num << "   s_length= " << s_length << endl; 

      if(num < n+2 && sequences[num] > 0){
        s_length+=sequences[num]-1;
        break;
      }
      else if(num % 2 == 0){
        num = num/2;
        s_length++;
      }
      else{
        num = 3*num +1;
        s_length++;
      }
    }
    sequences[i]=s_length;
    if(s_length > maxlength){
    maxlength=s_length;
    largest_collatz=i;
    }
  }

  cout << "The longest Collatz chain corresponds to a starting value of " << largest_collatz << ". It has a length of " << maxlength << endl;

  cout << "This thing took: " << ((double)clock()-t1)/CLOCKS_PER_SEC*1000 << " ms " << endl;




  



  return 0;
       
}
