#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool is_conform(vector<int> rule, vector<int> str){
    for(int i=0; i<rule.size(); i++){
      if(rule[i] == 1){
        if(str[i] < str[i+1]){ return false;}
      } else {
        if(str[i] > str[i+1]){ return false;}
      }
    }
    return true;
}

int main () {
  int n = 4;

  cin >> n;
  cin.get();

  int *lists = new int[n];
  for(int i=0; i<n; i++){ lists[i] = n-i; }

  string str;
  getline(cin,str,'\n');

  string cache = "";
  int strSize = 0, strPos = 0;
  vector<int> array;

  for(int i = 0 ; i < str.size(); i++){
    if(str[i] == ' '){
      strSize = i - strPos;
      cache = str.substr(strPos, strSize);
      array.push_back(stoi(cache));
      strPos = i+1;
    }
  }
  cache = str.substr(strPos, str.size() - strPos);
  if(cache.size()>0){ array.push_back(stoi(cache)); }

  vector<int> temp;
  int result = 0;

  do {
    temp.clear();
    for(int i=0; i<n; i++){
      // cout<< lists[i]<<' ';
      temp.push_back(lists[i]);
    }
    if(is_conform(array,temp)){result++;}
    // cout<<endl;
  } while ( prev_permutation(lists,lists+n) );

  cout << result <<endl;

  return 0;
}