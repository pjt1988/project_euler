#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <list>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){

  int n=1000;
  if(argc == 2) n= atoi(argv[1]);
  
  cout << "The retarded way: unoptimized trial division - full loops only!" << endl;

  clock_t t_1 = clock();
  vector<int> primes2;
  primes2.push_back(2);

  /*

  for(int i=3;i<=n;i++){
    int check=0;
    for(int j=2;j<n;j++){
      if(i!=j && i % j == 0){
        check = 1;
        break;
      }
    }
    if(check == 0) primes2.push_back(i);
  }
  
  cout << "Apparently there are " << primes2.size() << " primes below " << n << ". Their sum happens to be: ";

  size_t sum=0;
  for(int i=0;i<primes2.size();i++) sum+=primes2[i];

  cout << sum << endl;

  
  cout << "This took " << ((double)clock()-t_1)/CLOCKS_PER_SEC*1000 << " ms" << endl;


  
  cout << endl << "The stupid way: unoptimized trial division" << endl;
  
  clock_t t0 = clock();
  vector<int> primes;
  primes.push_back(2);

  for(int i=3;i<=n;i++){
    int check=0;
    for(int j=2;j<=sqrt(i)+1;j++){
      if(i % j == 0){
        check=1;
        break;
      }
    }
    if(check == 0) primes.push_back(i);
  }
  
  cout << "Apparently there are " << primes.size() << " primes below " << n << ". Their sum happens to be: ";

  sum=0;
  for(int i=0;i<primes.size();i++) sum+=primes[i];

  cout << sum << endl;

  
  cout << "This took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;


*/


  size_t sum=0;


  cout << endl << "The simple and elegant way; truncated trial division by all found primes" << endl;
  clock_t t=clock();
  vector<int> primes;
  primes.clear();
  primes.push_back(2);


  for(int i=3;i<=n;i+=2){
    int iter=0;
    int check=0;
    while((primes[iter] <= sqrt(i)) ){
      if(i % primes[iter] == 0){
        check=1;
        break;
      }
      iter++;
    }
    if(check == 0) primes.push_back(i);
  }
 
  cout << "Apparently there are " << primes.size() << " primes below " << n << ". Their sum happens to be: ";

  sum=0;
  for(int i=0;i<primes.size();i++) sum+=primes[i];

  cout << sum << endl;

  
  cout << "This took " << ((double)clock()-t)/CLOCKS_PER_SEC*1000 << " ms" << endl;

  //
  //
  //


  /*
  cout << endl << "Explicit sieve w/ erasing: " << endl;
  clock_t t2=clock();
  vector<int> trial;
  for(int i=2;i<n;i++){
    trial.push_back(i);
  }

  for(int j=0;j<trial.size() && trial[j] < sqrt(trial[trial.size()-1])+1;j++){
    for(int i=(j+1);i<trial.size();i++) if(trial[i] % trial[j] == 0) trial.erase(trial.begin()+i);
  }



  sum=0;
  for(int i=0;i<trial.size();i++){
      sum+=trial[i];
  }

  cout << "Apparently there are " << trial.size() << " primes below " << n <<". The sum of primes= " << sum << endl;
  cout << "This approach took " << ((double)clock()-t2)/CLOCKS_PER_SEC*1000 << " ms" << endl;
  
  */

  cout << endl << "Explicit sieve no erasing " << endl;

  clock_t t3 = clock();

  vector<int> trial2;
  for(int i=2;i<n;i++){
    trial2.push_back(i);
  }


  for(int i=0;trial2[i]<=sqrt(n);i++){
    //cout << "i= " << i << " trial2[i]= " << trial2[i] << endl;
    int k=0;
    for(int l=i;l<trial2.size();l++){
      if(trial2[l] == trial2[i]*trial2[i]){
        k=l;
       break;
      }
    }
    if(trial2[i] > 0){
      for(int j=k;j<=trial2.size();j+=sqrt(k)+1){
        //cout << "j= " << j << " trial2[j]= " << trial2[j] << endl;
        if(trial2[j] % trial2[i] == 0 ) trial2[j]=0;
        //if(i==0) j+=2; //stupid implementation..
      }
    }
  }

  sum=0;
  int p_count=0;
  for(int i=0;i<trial2.size();i++){
    if(trial2[i] != 0){
      sum+=trial2[i];
      p_count++;
    }
  }

  cout << "Apparently there are " << p_count << " primes below " << n << ". The sum of primes= " << sum << endl;
  cout << "This approach took " << ((double)clock()-t3)/CLOCKS_PER_SEC*1000 << " ms" << endl; 



  

  


  return 0;
}

