#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){
  
  int stop;
  int start;
  bool print = false;
  if(argc < 3){
    stop=125;
    start=1;
     }
  else {
    stop=atoi(argv[2]);
    start=atoi(argv[1]);
  }

  if((stop-start) <= 20) print=true;


  vector<string> names;

  //trivial to do without, but...the margins are too narrow.
  //Also, it'll be kinda impressive when it reads out a given number..
  names.push_back(""); //20 ain't twenty-zero
  names.push_back("one");
  names.push_back("two");
  names.push_back("three");
  names.push_back("four");
  names.push_back("five");
  names.push_back("six");
  names.push_back("seven");
  names.push_back("eight");
  names.push_back("nine");
  names.push_back("ten");
  names.push_back("eleven");
  names.push_back("twelve");
  names.push_back("thirteen");
  names.push_back("fourteen");
  names.push_back("fifteen");
  names.push_back("sixteen");
  names.push_back("seventeen");
  names.push_back("eighteen");
  names.push_back("nineteen");

  //factors of 10 now
  
  vector<string> tens;
  tens.push_back("");
  tens.push_back("ten");
  tens.push_back("twenty");
  tens.push_back("thirty");
  tens.push_back("forty");
  tens.push_back("fifty");
  tens.push_back("sixty");
  tens.push_back("seventy");
  tens.push_back("eighty");
  tens.push_back("ninety");
  
  string hundred = "hundred";
  string thousand = "thousand";
  string conj = "and"; //fuck you

  string pstring;
  string cstring;


  size_t sum=0;
  for(int i=start;i<=stop;i++){

    pstring="";
    cstring="";
    if(i<20){
      pstring.append(names[i]);
      cstring.append(names[i]);
    }
    //it occurs...this should've been functions. 
    else if(i>=20 && i < 100){
      int d10 = i % 10;
      int m10 = i / 10;
      pstring.append(tens[m10]);
      if(d10 != 0) pstring.append("-");
      pstring.append(names[d10]);

      cstring.append(tens[m10]);
      cstring.append(names[d10]);
    }

    else if(i >= 100 && i < 1000){
      int m100 = i / 100;
      int m10 = (i - m100*100) / 10;
      int d10 = (i - m100*100 - m10*10) % 10;

      pstring.append(names[m100]);
      pstring.append(" ");
      pstring.append(hundred);
      pstring.append(" ");
      if(d10 != 0 || m10 != 0) pstring.append(conj);
      pstring.append(" ");
      if(m10 < 2){
        pstring.append(names[m10*10+d10]);
      }
      else{
      pstring.append(tens[m10]);
      if(d10 != 0) pstring.append("-");
      pstring.append(names[d10]);
      }

      cstring.append(names[m100]);
      cstring.append(hundred);
      if(m10 != 0 || d10 != 0) cstring.append(conj);
      if(m10 < 2){
        cstring.append(names[m10*10+d10]);
      }
      else{
      cstring.append(tens[m10]);
      cstring.append(names[d10]);
      }

    }
    else if(i>=1000){
      int m1000 = i / 1000;
      int m100 = (i - m1000*1000) / 10;
      int m10 = (i - m1000*1000 - m100*100) / 10;
      int d10 = (i - m1000*1000 - m100*100 - m10*10) % 10;

      pstring.append(names[m1000]);
      pstring.append(" ");
      pstring.append(thousand);
      pstring.append(" ");

      pstring.append(names[m100]);
      pstring.append(" ");
      if(m100 != 0) pstring.append(hundred);
      pstring.append(" ");
      if(m10 != 0 || d10 != 0) pstring.append(conj);
      pstring.append(" ");
      if(m10 < 2){
        pstring.append(names[m10*10+d10]);
      }
      else{
      
      pstring.append(tens[m10]);
      if(d10 != 0) pstring.append("-");
      pstring.append(names[d10]);
      }

      cstring.append(names[m1000]);
      cstring.append(thousand);

      cstring.append(names[m100]);
      if(m100 != 0 ) cstring.append(hundred);
      if(m10 != 0 || d10 != 0) cstring.append(conj);
      if(m10 < 2){
        cstring.append(names[m10*10+d10]);
      }
      else{
      cstring.append(tens[m10]);
      cstring.append(names[d10]);
      }
    }
      

    if(print == true) cout << i << "= " <<  pstring << endl;

    sum+=cstring.size();
  }

  cout << "The sum of all letters used from " << start << " to " <<  stop << " = " << sum << endl;






  return 0;

}



