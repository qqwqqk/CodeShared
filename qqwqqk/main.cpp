#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

int main() {
  int N;
  int n;
  int num;
  int count;
  bool result = true;
  set<int> list;

  cin >> N;

  for(int i=0; i<N; i++){
    cin >> num;
    if(num != 0){
      if(list.count(num) > 0){ result = false; } 
      else { list.insert(num); }
    } else {
      n++;
    }
  }

  set<int>::iterator iter = list.begin();
  int font, next;
  while(1){
    font = *iter;
    iter++;
    if(iter == list.end()){ break; }
    next = *iter;
    if(next - font > 1){
      count += next - font - 1;
    }
  }

  if(count <= n && result){
    cout << "YES+"<<n;
  } else {
    cout << "NO+"<<n;
  }

  return 0;
}