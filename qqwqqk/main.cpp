#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool sortFun(const int &p1, const int &p2){
	return p1 > p2;
}
 
int main()
{
  vector<int> prices = {4,2};
  int budget = 7;

  int result = -1;
  queue<int> lists;

  sort(prices.begin(), prices.end(), sortFun);

  int i=0;
  int j=0;

  while(1){
    if(budget >= prices[i]){
      lists.push(prices[i]);
      budget = budget - prices[i];
      if(budget == 0){ result=lists.size(); break; }
    } else {
      i++;
      if(i < prices.size()){ continue; }
      else {
        if(lists.front() > prices[j]){
          budget += lists.front();
          lists.pop();
          j++;
          i = j;
        } else { break; }
      }
    }
  }

  cout << result <<endl;
 
	return 0;
}