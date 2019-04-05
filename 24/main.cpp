#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

size_t fact(size_t num){
  if(num == 0 || num == 1) return 1;
  else return num*fact(num-1);
}

//needed for lexcicographical permutations...shamelessly copypasta'd from problem 24. 
void swap(vector<vector<size_t> > &a, int index, int k, int l){
  size_t temp=a[index][k];
  a[index][k]=a[index][l];
  a[index][l]=temp;
}

void reverse(vector<vector<size_t> > &a, int index, int start, int stop){
  for(int i=0;i<a[index].size() && start+i < stop-i;i++){  
  swap(a,index,start+i,stop-i);
  }
}

void copy(vector<vector<size_t> > &a, int index){
  if(index < a.size() - 1){
  for(int i=0;i<a[index].size();i++){
      a[index+1].push_back(a[index][i]);
  }
  }
}

int findk(vector<vector<size_t> > &a, int index){
  int k=0;
  for(int i=0;i<a[index].size()-1;i++){
    if(a[index][i] < a[index][i+1] && k <= i) k=i;
  }
  return k;
}

int findl(vector<vector<size_t> > &a, int index, int k){
  int l=0;
  for(int i=0;i<a[index].size();i++){
    if(a[index][k] < a[index][i] && k <= i) l=i;
  }
  return l;
}


int main(int argc, char** argv){
  clock_t t0 = clock();
  int n=2;

  if(argc == 2 ) n = atoi(argv[1]);

  vector<size_t> cyc_primes;
  for(int i=start;i<=stop;i++) seq.push_back(i);
  //start from ordered sequence! 

  size_t num_pert = fact(seq.size());
  cout << "Sequence length = " << seq.size() << ". This means " << num_pert << " number of perturbations! " << endl;

  vector<vector<size_t> > perts(num_pert);

  for(int i=0;i<seq.size();i++){
    perts[0].push_back(seq[i]);
    perts[1].push_back(seq[i]); // initializes the first "true" permutation - same as lexicographically ordered 0th seq, but will get permutated in the loop
  }

  //for(int i=0;i<perts[0].size();i++) cout << perts[0][i] << " " << endl;


  for(int i=1;i<perts.size();i++){
    int k=findk(perts,i);
    int l=findl(perts,i,k);
    //cout << "Iter " << i << " k= " << k << " l= " << l << endl;
    swap(perts,i,k,l);
    reverse(perts,i,k+1,perts[i].size()-1);
    copy(perts,i);
  }

  if(stop-start < 5){
    for(int i=0;i<perts.size();i++){
      cout << endl;
      for(int j=0;j<perts[i].size();j++){
        cout << perts[i][j] << " ";
      }
    }
    cout << endl;
  }

  if(perts.size() >= 1000000){
    cout << "The millionth permutation of the sequence is: ";
    for(int i=0;i<perts[999999].size();i++) cout << perts[999999][i];
    //millionth as in the true millionth permutation, or also counting the base sequence? prompt was not clear!
    cout << endl;
  }

  cout << "This thing took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms" << endl;











  return 0;
}

