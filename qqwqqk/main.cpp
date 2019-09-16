#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

vector<string> replace(string str){
  vector<string> list;
  int i;
  for(i = 0; i<str.size(); i++){
    if(str[i] >= '0' && str[i]<='9'){ break; }
  }
  if(i == str.size()){ return list;}
  if(str[i] == '2'){ 
    str[i]='a'; list.push_back(str); 
    str[i]='b'; list.push_back(str); 
    str[i]='c'; list.push_back(str);
  }
  if(str[i] == '3'){ 
    str[i]='d'; list.push_back(str); 
    str[i]='e'; list.push_back(str); 
    str[i]='f'; list.push_back(str);
  }
  if(str[i] == '4'){ 
    str[i]='g'; list.push_back(str); 
    str[i]='h'; list.push_back(str); 
    str[i]='i'; list.push_back(str);
  }
  if(str[i] == '5'){ 
    str[i]='j'; list.push_back(str); 
    str[i]='k'; list.push_back(str); 
    str[i]='l'; list.push_back(str);
  }
  if(str[i] == '6'){ 
    str[i]='m'; list.push_back(str); 
    str[i]='n'; list.push_back(str); 
    str[i]='o'; list.push_back(str);
  }
  if(str[i] == '7'){ 
    str[i]='p'; list.push_back(str); 
    str[i]='q'; list.push_back(str); 
    str[i]='r'; list.push_back(str);
    str[i]='s'; list.push_back(str);
  }
  if(str[i] == '8'){ 
    str[i]='t'; list.push_back(str); 
    str[i]='u'; list.push_back(str); 
    str[i]='v'; list.push_back(str);
  }
  if(str[i] == '9'){ 
    str[i]='w'; list.push_back(str); 
    str[i]='x'; list.push_back(str); 
    str[i]='y'; list.push_back(str);
    str[i]='z'; list.push_back(str);
  }
  return list;
}

int main () {
  string str;
  getline(cin, str,'\n');

  queue<string> lists;
  lists.push(str);
  while(1){
    str = lists.front();
    vector<string> cache = replace(str);
    if(cache.size() > 0){
      lists.pop();
      for(int i=0; i<cache.size(); i++){
        lists.push(cache[i]);
      }
    } else {
      break;
    }
  }

  while(!lists.empty()){
    cout<< lists.front();
    lists.pop();
    if(!lists.empty()){cout<<',';}
  }

  return 0;
}