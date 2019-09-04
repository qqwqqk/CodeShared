#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class version{
public:
  string ver;
  int i,j,k;
  version(string str = "0.0.0"){
    string cache = "";
    int strSize = 0, strPos = 0;
    vector<int> array;

    for(int i = 0 ; i < str.size(); i++){
      if(str[i] == '.'){
        strSize = i - strPos;
        cache = str.substr(strPos, strSize);
        array.push_back(stoi(cache));
        strPos = i+1;
      }
    }
    cache = str.substr(strPos, str.size() - strPos);
    if(cache.size()>0){ array.push_back(stoi(cache)); }

    ver = str;
    i = array[0];
    j = array[1];
    k = array.size() > 2 ? array[2] : 0;
  }
};

bool sortFun(const version &p1, const version &p2){
  if(p1.i == p2.i){
    if(p1.j == p2.j){
      return p1.k < p2.k;
    }
    return p1.j < p2.j;
  }
	return p1.i < p2.i;
}

int main(){
  string ver;

  vector<version> lists;

  cin >> ver;
  version item1(ver);
  lists.push_back(item1);

  cin >> ver;
  version item2(ver);
  lists.push_back(item2);

  sort(lists.begin(), lists.end(), sortFun);

  for(int i=0; i<lists.size(); i++){
    cout<< lists[i].ver;
    if(i+1 != lists.size()){
      cout<< ',';
    }
  }
  return 0;
}