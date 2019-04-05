#include <iostream>
#include <vector>

using namespace std;



int main(){

  vector <vector <vector <int> > > ymd (101, vector<vector<int> >(12, vector<int> (31))); 

  //there is absolutely no need to store anything, but i like having my own calender

  int daycount = 0;
  int day=1; //0-sun, 1-mon, 2-tue, etc
  for(int i=0;i<ymd.size();i++){
    for(int j=0;j<12;j++){

      int k;
      if(j==0) k=31;
      else if(j==1 && i > 0 && i % 4 == 0) k=29;
      else if(j==1 ) k=28;
      else if(j==2) k=31;
      else if(j==3) k=30;
      else if(j==4) k=31;
      else if(j==5) k=30;
      else if(j==6) k=31;
      else if(j==7) k=31;
      else if(j==8) k=30;
      else if(j==9) k=31;
      else if(j==10) k=30;
      else if(j==11) k=31;

      //vector<int> days(k);
      //ymd[i][j].push_back(days);
      
      ymd[i][j].resize(k);

      for(int l=0;l<k;l++){
        if(day > 6) day = 0;
        ymd[i][j][l] = day;
        daycount++;
        //cout << "(i,j,l) = " << i << " , " <<  j  << " , " << l << "   = " << ymd[i][j][l] << endl;
        //years[i].md[j].push_back(day);
        day++;
      }
    }
  }

  cout << "Finished generating " << daycount << " days. Analyzing.." << endl;

  int suncount = 0;
  for(int i=1;i<=100;i++){
    for(int j=0;j<ymd[i].size();j++){
      if(ymd[i][j][0] == 0) suncount++;
    }
  }

  cout << "There were " << suncount << " Sundays on the first ov each month during the 20th century." << endl;



  return 0;
}



