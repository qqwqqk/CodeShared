#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

bool includ_four(int n){
  while(n > 0){
    if(n % 10 == 4){return true;}
    n = n / 10;
  }
  return false;
}

int main () {
  int nums;
  cin>>nums;

  const int size = nums;
  int count = 0;

  int i = 1;
  while(nums > 1){
    i++;
    if(includ_four(i)){ 
      count++;
    } else {
      nums--;
    }
  }

  cout << "nums:\t" << size << endl;
  cout << "count:\t" << count <<endl;
  cout << "result:\t" << size + count<<endl;

  return 0;
}