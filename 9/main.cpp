#include <iostream>
#include <vector>

using namespace std;

int main(){


  vector<int> trip_a;
  vector<int> trip_b;
  vector<int> trip_c;
  
  for(int c=3; c<=997; c++){
    for(int b=2; b<c; b++){
      for(int a=1; a<b; a++){
        if((a*a + b*b) == (c*c)){
          trip_a.push_back(a);
          trip_b.push_back(b);
          trip_c.push_back(c);
          break;
        }
      }
    }
  }

  cout << "We found " << trip_a.size() << " Pythagorean tiplets." << endl;

  int index;
  for(int i=0;i<trip_a.size();i++){
    if((trip_a[i] + trip_b[i] + trip_c[i]) == 1000){
      index=i;
      break;
    }
  }

  cout << "The Pythagorean tiplet st. a+b+c = 1000 was found with: a= " << trip_a[index] << ", b= " << trip_b[index] << ", and c= " << trip_c[index] << endl;
  cout << "The product a*b*c = " << trip_a[index]*trip_b[index]*trip_c[index] << endl;




  return 0;
}
