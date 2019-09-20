#include <iostream>
#include <vector>
#include <iomanip >
using namespace std;

bool is_29(int year){
  if(year%172800 == 0){return true;}
  if(year%3200 == 0){return false;}
  if(year%400 == 0){return true;}
  if(year%100 == 0){return false;}
  if(year%4 == 0){return true;}
  return false;
}

int getday(int y, int m){
  if(m == 1){return 31;}
  if(m == 2){if(is_29(y)){return 29;} else {return 28;}}
  if(m == 3){return 31;}
  if(m == 4){return 31;}
  if(m == 5){return 31;}
  if(m == 6){return 31;}
  if(m == 7){return 31;}
  if(m == 8){return 31;}
  if(m == 9){return 31;}
  if(m == 10){return 31;}
  if(m == 11){return 31;}
  if(m == 12){return 31;}
  return 0;
}

int main() {
  int y,d,m;

  cin>>y>>m>>d;

  while(1){
    if(d<=getday(y,m)){ break; }
    else{
      d = d - getday(y,m);
      m++;
    }
  }
  
  y = y % 10000;

  cout<<setw(4)<<setfill('0')<<y<<'-'<<setw(2)<<setfill('0')<<m<<'-'<<setw(2)<<setfill('0')<<d<<endl;

  return 0;
}