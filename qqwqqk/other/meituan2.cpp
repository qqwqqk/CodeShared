#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int combinationSum(vector<int>& candidates, int target) {
  map<int, set<vector<int>>>dict;
	for (int i = 1; i <= target; i++){
    for (int it : candidates) {
      if (i == it) {dict[i].insert(vector<int>{it});}
      else if (i > it){
        for (auto ivec : dict[i - it]) {
          ivec.push_back(it);
          sort(ivec.begin(), ivec.end());
          if(dict[i].count(ivec)==0){ dict[i].insert(ivec); }
        }
      }
    }
  }
	int min = INT_MAX;
	for (auto it : dict[target]) { 
    // ans.push_back(it);
    min = min < it.size() ? min : it.size();
  }
  return min;
}

int main() {
  int target;
  int n;
  int price;
  vector<int> lists;

  cin>>target;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>price;
    lists.push_back(price);
  }

  cout << combinationSum(lists, target) <<endl;

  return 0;
}