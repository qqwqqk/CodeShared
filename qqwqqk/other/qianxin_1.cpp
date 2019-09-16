#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

int find(vector<string> article, int n, string x, string y){
  int xi = -1;
  int yi = -1;
  int abs = 0;
  int length = 1000;
  for(int i=0; i<n; i++){
    if(article[i] == x){
      xi = i;
      if(yi != -1){
        abs = xi - yi > 0 ? xi - yi : yi - xi;
        length = length < abs ? length : abs;
      }
    }
    if(article[i] == y){
      yi = i;
      if(xi != -1){
        abs = xi - yi > 0 ? xi - yi : yi - xi;
        length = length < abs ? length : abs;
      }
    }
  }
  return length;
}

int main () {
  vector<string> lists = {"my","name","is","tom","you","and","name","tom"};
  int n = lists.size();

  int res = find( lists, n, "name", "and");
  cout<< res <<endl;

  return 0;
}