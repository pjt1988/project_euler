#include <iostream>

using namespace std;

int main(){

  int max=0;
  int palin_count=0;
  for(int i=100;i<1000;i++){
    for(int j=100;j<1000;j++){
      int num=i*j;
      int temp=num;
      int mun=0; //get it? "mun"!!!
      while(temp>0){
        int digit=temp % 10;
        mun = mun*10 + digit;
        temp = temp / 10;
      }
      if(num == mun){
        palin_count++;
        if(num > max) max = num;
      }
    }
  }

  cout << "We found " << palin_count << " palindromic numbers. Of these, the largest = " << max << endl;

  return 0;
}
