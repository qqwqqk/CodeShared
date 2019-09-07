#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

//huawei 2 timeout

bool is_repeat(vector<int> cache, set<queue<int>> lists, int m){
    queue<int> list1, list2;
    for(int i=0; i<m; i++){
      list1.push(cache[i]);
      list2.push(cache[m-1-i]);
    }
    for(int i=0; i<=m; i++){
      if(lists.count(list1) > 0){return true;}
      if(lists.count(list2) > 0){return true;}
      int item1 = list1.front();
      int item2 = list2.front();
      list1.pop(); list2.pop();
      list1.push(item1);
      list2.push(item2);
    }

  return false;
};

vector<int> add(vector<int> cache, int n){
  int i=0;
  while(1){
    cache[i] = cache[i] + 1;
    if(cache[i] <= n){ break; }
    else {cache[i] = 1; i++; }
  }
  return cache;
}
 
int main()
{
  set<queue<int>> lists;
  int n = 3,m =3;
  int result = 0;
  vector<int> cache;
  queue<int> list;

  
  cin >> n >>m;
  for(int i=0; i<=m; i++){ cache.push_back(1); }

  while(1){
    if(!is_repeat(cache, lists, m)){ 
      while(!list.empty()){list.pop();}
      for(int i=0; i<m; i++){ list.push(cache[i]); }
      lists.insert(list);
      result++; 
    }
    
    cache = add(cache, n);

    if(cache[m] > 1){ break; }
  }


  result = result % 1000000007;
  cout << result <<endl;
 
	return 0;
}