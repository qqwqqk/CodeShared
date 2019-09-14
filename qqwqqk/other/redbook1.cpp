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
  char split = ' ';
  vector<int> result;

  for(int i = 0 ; i < str.size(); i++){
    if(str[i] == split){
      strSub = i - strPos;
      cache = str.substr(strPos, strSub);
      result.push_back(stoi(cache));
      strPos = i+1;
    }
  }
  cache = str.substr(strPos, str.size() - strPos);
  if(cache.size()>0){ result.push_back(stoi(cache)); }

  return result;
}

class people{
public:
  int id;
  bool tag;
  vector<int> friends;
  people(int i = -1){ id = i; tag = false; }
};

int getPeople(vector<people> list){
  int res = -1;
  for(int i=0; i<list.size(); i++){
    if(!list[i].tag){res = i; break;}
  }
  return res;
}

int main () {
  int n;
  string str;

  cin >> n;
  getchar();
  vector<people> lists;

  for(int i=0; i<n; i++){
    getline(cin, str,'\n');
    vector<int> cache = analyzeLine(str);
    people item(i);
    for(int j=0; j<n; j++){ if(cache[j] == 1){ item.friends.push_back(j);} }
    lists.push_back(item);
  }

  int result = 0;
  while(1){
    int userid = getPeople(lists);
    if(userid == -1){break;}
    lists[userid].tag = true;
    result++ ;
    vector<int> cache = lists[userid].friends;
    queue<int> temp;
    for(int i=0; i<cache.size(); i++){ temp.push(cache[i]); }
    while(!temp.empty()){
      int id = temp.front();
      lists[id].tag = true;
      temp.pop();
      vector<int> items = lists[id].friends;
      for(int i=0; i<items.size(); i++){ 
        if(!lists[items[i]].tag){temp.push(items[i]);}
      }
    }
  }

  cout<< result <<endl;

  return 0;
}