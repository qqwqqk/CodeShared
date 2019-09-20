#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

bool isHave(vector<vector<int>> &vv,vector<int> &v,int x,int y){
  for(int i=0;i<vv.size();i++){
    int flag=0;
    for(int j=x;j<=y;j++){
      if(vv[i][0]==v[j]){
        flag++;
        break;
      }
    }
    for(int j=x;j<=y;j++){
      if(vv[i][1]==v[j]){
        flag++;
        break;
      }
    }
    if(flag==2){
      return true;
    }else{
      flag==0;
    }
  }
  return false;
}

int main(){
  int n,m;
  string strTemp;
  stringstream ss;
  int i=0;
  vector<int> v;
  vector<vector<int>> vv;
  getline(cin,strTemp);
  ss<<strTemp;
  ss>>n>>m;
  ss.clear();
  getline(cin,strTemp);
  int temp;
  while(ss>>temp){
    v.push_back(temp);
  }
  ss.clear();
  for(int i=0;i<m;++i){
    vector<int> vtemp;
    getline(cin,strTemp);
    ss<<strTemp;
    int temp1,temp2;
    ss>>temp1>>temp2;
    vtemp.push_back(temp1);
    vtemp.push_back(temp2);
    sort(vtemp.begin(),vtemp.end());
    vv.push_back(vtemp);
    ss.clear();
  }

  int count=0;
  for(int i=0;i<n;++i){
    for(int j=i;j<n;j++){
      if(i==j){
        count++;
      }else{
        bool is=isHave(vv,v,i,j);
        if(!is){
          count++;
        }
      }
    }
  }
  cout<<count<<endl;
  return 0;
}