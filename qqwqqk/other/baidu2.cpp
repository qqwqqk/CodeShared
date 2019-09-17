#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class item{
public:
  int cost;
  int time;
  item(int c=0,int t=0){
    cost = c;
    time = t;
  }
};

bool sortFun(item &x, item &y){
  if(x.time == y.time){
    return x.cost < y.cost;
  }
  return x.time < y.time;
}

bool works(vector<item> list){
  int timecost = 0;
  const int n = list.size();
  sort(list.begin(),list.end(),sortFun);
  for(int i=0; i<n; i++){
    if(list[i].time - timecost >= 0){
      timecost += list[i].cost;
    } else {
      return false;
    }
  }
  return true;
}

int main () {
  int n = 0;
  int m = 0;
  int a = 0, b = 0;
  vector<item> list;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> m;
    list.clear();
    for(int j=0; j<m; j++){
      cin>>a>>b;
      item val(a,b);
      list.push_back(val);
    }
    int res = works(list);
    if(res){ cout<< "Yes" << endl; } else { cout<< "No" <<endl; }
  }

  return 0;
}