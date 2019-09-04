#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int splitArray(vector<int>& nums, int m) {
    int len = nums.size();
    vector<vector<long>> dp(len + 1,vector<long>(m + 1,INT_MAX));
    dp[1][1] = nums[0];
    for(int i = 2 ; i <= len;++i)
        dp[i][1] = dp[i-1][1] + nums[i-1];
    
    for(int j = 2 ; j <= m ; ++j){
        for(int k = j ; k <= len ; ++k){
            long tmp = 0;
            for(int l = k - 1; l >= j - 1 ;--l){
                tmp = max(dp[l][j-1],dp[k][1] - dp[l][1]);
                dp[k][j] = min(dp[k][j],tmp);
            }
        }
    }
    return dp[len][m];
}
 
int main()
{
  vector<int> num;
  int n,m;
  cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
    int temp;
    cin >> temp;
    num.push_back(temp);
	}
  int result = splitArray(num,n);
  cout << result <<endl;
 
	return 0;
}