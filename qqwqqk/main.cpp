#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
  int n,min;
  vector<int> list;
  cin>>n>>min;

  int temp;
  for(int i=0; i<n;i++){
    cin>>temp;
    list.push_back(temp);
  }
  sort(list.begin(), list.end());

  int res = 0;
  int i=0, j=list.size();

  while(i<j){
    if(i+j<=min){i++;j--;}else{j--;}
    res++;
  }

  cout<<res;

  return 0;
}