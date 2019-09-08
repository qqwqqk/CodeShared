#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int maxProduct(vector<int> nums){
    long dp_min = nums[0];
    long dp_max = nums[0];

    long res = nums[0];
    for(int i = 1; i < nums.size(); i++){
        long n = nums[i];
        long _dp_max = max(max(dp_max * n, dp_min * n), n);
        long _dp_min = min(min(dp_max * n, dp_min * n), n);
        dp_min = _dp_min;
        dp_max = _dp_max;
        res = max(res, dp_max);
    }
    return res;
}

int main(){
  string str;
  getline(cin,str,'\n');

  string cache = "";
  int strSize = 0, strPos = 0;
  vector<int> array;

  for(int i = 0 ; i < str.size(); i++){
    if(str[i] == ' '){
      strSize = i - strPos;
      cache = str.substr(strPos, strSize);
      array.push_back(stoi(cache));
      strPos = i+1;
    }
  }
  cache = str.substr(strPos, str.size() - strPos);
  if(cache.size()>0){ array.push_back(stoi(cache)); }

  int result = maxProduct(array);
  cout << result << endl;
  
  return 0;
}