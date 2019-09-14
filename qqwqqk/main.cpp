#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

class treasure{
public:
  int x,h;
  int rank;
  treasure(int i=-1,int j=-1){
    x = i, h = j;
    rank = x>h?x:h;
  }
};

bool sortFun(treasure &t1, treasure &t2){
  if(t1.rank == t2.rank){
    if(t1.x == t2.x){
      return t1.h < t2.h;
    }
    return t1.x < t2.x;
  }
  return t1.rank < t2.rank;
}

int main () {
  int n;
  int x,h;
  int result=0;
  vector<treasure> lists;

  cin >> n;
  for(int i=0; i<n; i++){
    cin>>x>>h;
    treasure item(x,h);
    lists.push_back(item);
  }
  sort(lists.begin(), lists.end(), sortFun);

  int rank = -1;
  for(int i=0; i<n; i++){
    if(lists[i].x >= rank && lists[i].h >= rank){
      result++;
      rank = lists[i].rank;
    }
  }

  cout<< result <<endl;

  return 0;
}