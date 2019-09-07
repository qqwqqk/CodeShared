#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> result;

int findresult(vector<int> data, int end, int &count){
  for(int i=end-1; i>0; i--){
    if((end - i) == data[i]){
      count++;
      if(i>=1 && i<data.size()/2){
        count++;
        result.push_back(count);
        count-=2;
      } else {
        findresult(data,i,count);
      }
    }
  }
  return 0;
}
 
int main()
{
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
  
  int length = array.size();
  int count = 0;
  findresult(array, array.size()-1, count);
  if(result.size()==0){
    cout<<-1<<endl;
  } else {
    int min = result[0];
    for(int i=1;i<result.size(); i++){
      min = min < result[i] ? min : result[i];
    }
    cout<<min<<endl;
  }
 
	return 0;
}