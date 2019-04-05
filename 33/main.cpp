#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

size_t gcd_finder(int a, int b){
  int div = b;
  int mod = b;
  while(div > 0){
    mod = a % div;
    if(mod!=0) div = a % mod;
    else div = mod;
  }
  if(mod != 0)  return mod;
  else return 1;
}



void elim(vector<int> &a){
  for(int i=0;i<a.size()-1;i++){
    for(int j=i+1;j<a.size();j++){
      if(a[i] == a[j]) a.erase(a.begin() + j);
    }
  }
}

void elim_dupes(vector<int> &a, vector<int> &b){
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      if(a[i] == b[j]){
        a.erase(a.begin()+i);
        b.erase(b.begin()+j);
        break;
      }
    }
  }
}

int renumber(vector<int> a){
  int num = 0;
  for(int i=0;i<a.size();i++){
    //num += a[a.size()-1-i]*pow(10,i);
    num += a[i]*pow(10,i);
  }
  return num;
}


bool contain_dupe(vector<int> a, vector<int> b){
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      if(a[i] == b[j] && b[j] != 0 && a[i] != 0){
        return true;
      }
    }
  }
  return false;
}

void digitizer(vector<int> &digit, int num){
  while(num > 0){
    digit.push_back(num % 10);
    num = num / 10;
  }
}

int main(int argc, char** argv){

  clock_t t0 = clock();

  int n=2;
  if(argc==2) n=atoi(argv[1]);

  vector<int> numer;
  vector<int> denom;
  cout << "Brute force.." << endl;

  for(int i=11;i<pow(10,n);i++){
    for(int j=i+1;j<=pow(10,n);j++){

      vector<int> top;
      vector<int> bottom;

      digitizer(top, i);
      digitizer(bottom, j);
      //cout << "Digitized.." << endl;
      bool check = contain_dupe(top, bottom);

      if(check == true){
        //cout << "i= " << i << "  j= " << j << "true check.." << endl;
        elim_dupes(top, bottom);
        //cout << "i= " << i << "  j= " << j << " dupes gone.." << endl;
        int top_red = renumber(top);
        int bottom_red = renumber(bottom);

        //cout << "topred= " << top_red << "  bottomred= " << bottom_red << endl;
        if(((double) top_red / bottom_red) == ((double) i/j )){
          //cout << "check true" << endl;
          numer.push_back(i);
          denom.push_back(j);
          cout << i << "/" << j << endl;
        }
      }
    }
  }

  //elim(numer);
  //elim(denom);


  cout << "after loop " << endl;

  long double tpro=1;
  long double bpro=1;
  for(int i=0;i<denom.size();i++){
    tpro *= numer[i];
    bpro *= denom[i];
  }

  size_t gcd = gcd_finder(tpro,bpro);
  tpro = (long double) tpro / gcd;
  bpro = (long double) bpro / gcd;

  cout << "There are " << numer.size() << " stupidly reducable fractions. " << endl;
  cout << "The (lowest common term) product of denums = " << bpro << endl;
  cout << "This took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;


  return 0;
}



