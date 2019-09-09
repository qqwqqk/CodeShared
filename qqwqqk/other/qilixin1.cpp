#include<iostream>
#include<vector>
using namespace std;

int main () {
  int nums ;

  cin>>nums;

  vector<int> lists(nums);

  int pos=0, curr=0, count = 0;
  while(1){
    if(lists[curr] == 0){ pos++; }
    if(pos == 5){ 
      count++; 
      lists[curr]=count; 
      pos = 0; 
    }
    curr = curr + 1 == nums ? 0 : curr + 1;
    if(lists[nums-1] != 0){ break; }
  }

  cout << count<<endl;

  return 0;
}