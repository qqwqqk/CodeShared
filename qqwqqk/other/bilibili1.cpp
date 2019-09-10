#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

vector<int> analyzeLine(string str){
  int strSub = 0, strPos = 0;
  string cache = "";
  vector<int> result;

  for(int i = 0 ; i < str.size(); i++){
    if(str[i] == '+' || str[i] == 'i'){
      strSub = i - strPos;
      cache = str.substr(strPos, strSub);
      if(cache.size()<1){result.push_back(1);}
      else{result.push_back(stoi(cache));}
      strPos = i+1;
    }
  }

  return result;
}

int main () {
  string s1,s2;

  getline(cin,s1,'\n');
  getline(cin,s2,'\n');

  vector<int> a,b;
  a = analyzeLine(s1);
  b = analyzeLine(s2);

  int c1 = a[0] * b[0] - a[1] * b[1];
  int c2 = a[0] * b[1] + a[1] * b[0];

  cout<< c1 << '+' << c2 << 'i';

  return 0;
}