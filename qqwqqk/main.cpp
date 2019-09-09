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
  int nums ;

  cin>>nums;
  int count = 0;

  for(int i=1; i<=nums; i++){
    if(includ_four(i)){ 
      // cout << i<<' ';
      count++;
      // if(count % 10 == 0){cout<<endl;}
    }
  }

  cout << endl << nums + count <<endl;

  return 0;
}