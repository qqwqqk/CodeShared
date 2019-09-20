#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int sub(vector<int> &list, int x, int y){
  int x_index = -1, y_index = -1;
  const int n = list.size();
  for(int i=0; i<n; i++){
    if(list[i] == x){x_index = i; if(y_index > -1){ break; }}
    if(list[i] == y){y_index = i; if(x_index > -1){ break; }}
  }

  int sub_1=0;
  int sub_2=0;
  int sub_3=0;

  if(x_index == -1 && y_index == -1){
    return sub_1 = n;
  } else if(x_index == -1){
    sub_1 = y_index - 0;
    sub_2 = n - 1 - y_index;
  } else if(y_index == -1){
    sub_1 = x_index - 0;
    sub_2 = n - 1 - x_index;
  } else {
    sub_1 = x_index < y_index ? x_index - 0 : y_index - 0;
    sub_2 = x_index < y_index ? y_index - x_index -1 : x_index - y_index - 1;
    sub_3 = x_index < y_index ? n - y_index - 1: n - x_index - 1;
  }

  int res = 0;
  res += sub_1*(sub_1+1)/2;
  res += sub_2*(sub_2+1)/2;
  res += sub_3*(sub_3+1)/2;
  return res;
}

int main() {
  int n,m;
  int cache;
  cin>>n>>m;
  vector<int> list;
  for(int i=0; i<n; i++){
    cin>>cache;
    list.push_back(cache);
  }

  int x,y;
  int count = 0;
  for(int i=0; i<m; i++){
    cin>>x>>y;
    count += sub(list, x, y);
  }

  cout<<count<<endl;

  return 0;
}