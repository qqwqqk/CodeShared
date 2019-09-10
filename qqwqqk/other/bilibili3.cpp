#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

vector<int> analyzeLine(string str){
  int strSub = 0, strPos = 0;
  string cache = "";
  char split = ' ';
  vector<int> result;

  for(int i = 0 ; i < str.size(); i++){
    if(str[i] == '#'){break;}
    if(str[i] == split){
      strSub = i - strPos;
      cache = str.substr(strPos, strSub);
      result.push_back(stoi(cache));
      strPos = i+1;
    }
  }

  return result;
}

int main () {
  string str;
  vector<int> list;
  int num;

  getline(cin,str,'\n');
  cin >> num;

  list = analyzeLine(str);

  int pos = 0;
  stack<int> sta;

  while(pos < list.size()){
    pos += num;
    if(pos < list.size()){
      for(int i=0; i<num; i++){
        sta.push(list[pos -num + i]);
      }
      while(!sta.empty()){
        int n = sta.top();
        cout<< n<<"->";
        sta.pop();
      }
    } else {
      for(int i=pos-num; i<list.size(); i++){
        cout<< list[i];
        if(i+1<list.size()){cout << "->";}
      }
    }
  }
  
  return 0;
}