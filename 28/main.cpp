#include <vector>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <cmath>

using namespace std;

void moveright(vector<vector<int> > &A, int cyc, int &row, int &col, int &index){
  //path length is not 2*cyc+1, since the first space is already occupied. just 2*cyc!
  for(int i=1;i<=cyc && index < A.size()*A.size();i++){ 
    index++;
    col+=1;
    A[row][col] = index; //please remember to initialize this properly..
  }
}

void movedown(vector<vector<int> > &A, int cyc, int &row, int &col, int &index){
  for(int i=1;i<=cyc && index < A.size()*A.size();i++){
    index++;
    row+=1;
    A[row][col] = index;
  }
}

void moveleft(vector<vector<int > > &A, int cyc, int &row, int &col, int &index){
  for(int i=1;i<=cyc && index < A.size()*A.size();i++){
    index++;
    col-=1;
    A[row][col] = index;
  }
}

void moveup(vector<vector<int> > &A, int cyc, int &row, int &col, int &index){
  for(int i=1;i<=cyc && index < A.size()*A.size();i++){
    index++;
    row-=1;
    A[row][col] = index;
  }
}

void printmat(vector<vector<int> > A){
  cout << endl;
  for(int i=0;i<A.size();i++){
    for(int j=0;j<A[i].size();j++){
      //cout << A[i][j] << " ";
      printf("%6d",A[i][j]);
    }
    cout << endl;
  }
  cout << endl;
}




int main(int argc, char** argv){

  clock_t t0 = clock();
  int n = 9;
  if(argc == 2) n = atoi(argv[1]);

  if(n % 2 == 0){
    cout << "The spiral thingy should have dim oddxodd.." << endl;
    return 1;
  }

  vector<vector<int> > spiral(n, vector<int> (n));

  int row = n / 2 ;
  int col = n / 2 ;
  int index=1;
  spiral[row][col] = index;
  int cycle=1;

  while(index <= n*n){
    moveright(spiral,cycle,row,col,index);
    movedown(spiral,cycle,row,col,index);
    if(cycle < n) cycle++;
    else break;
    moveleft(spiral,cycle,row,col,index);
    moveup(spiral,cycle,row,col,index);
    if(cycle < n) cycle++;
    else break;
  }
  if(n<22) printmat(spiral);

  size_t sum=0;
  for(int i=0;i<spiral.size();i++){
    sum+=spiral[i][i]; //top-left, bottom-right
    sum+=spiral[spiral.size()-1-i][i]; //bottom-left, top-right
  }
  sum-=1; // counted twice

  cout << "The sum of diagonal elements= " << sum << endl;
  cout << "The stupid way took " << ((double)clock()-t0)/CLOCKS_PER_SEC*1000 << " ms. " << endl;

  cout << endl << endl;

  clock_t t1=clock();
  sum=0;
  int ind=3;
  for(int i=1;i<=n/2;i++){
    sum+=pow(ind,2); //from center to top-right; sum of odd squares
    ind+=2;
  }
  ind=2;
  for(int i=1;i<=n/2;i++){
    sum+=pow(ind,2)+1; //from center to bottom-right; sum of even squares+1
    ind+=2;
  }
  ind=2;
  for(int i=1;i<=n/2;i++){
    sum+=2*pow(ind,2)+2;
    ind+=2;
  }
  sum++;//get dat central 1

  cout << "The smarter way. Sum= " << sum << endl;
  cout << "The more intelligent approach took " << ((double)clock()-t1)/CLOCKS_PER_SEC*1000 << " ms." << endl;

  





  return 0;
}











