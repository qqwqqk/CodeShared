#include<map>
#include<vector>
#include<iostream>
using namespace std;

class kid{
public:
  int id;
  bool tag;
  vector<int> dislike;
  kid(int _id = -1, int unlike = -1){
    id = _id;
    tag = true;
    dislike.push_back(unlike);
  }
  void marktag(){tag = false;}
};

int main(){
  int count;
  int n;
  int id_1, id_2;

  map<int,kid> lists;
  map<int,kid>::iterator iter;

  cin>>count>>n;
  for(int i=0; i<n;i++){
    cin>>id_1>>id_2;
    iter = lists.find(id_1);
    if(iter == lists.end()){
      kid item(id_1,id_2);
      lists.insert(pair<int,kid> (id_1,item));
    } else {
      iter->second.dislike.push_back(id_2);
    }
  }

  map<int, kid> classA, classB;

  iter = lists.begin();
  classA.insert(pair<int,kid> (iter->first, iter->second));

  while(1){
    int nums = classA.size();

    for(iter = classA.begin(); iter != classA.end(); iter++){
      if(iter->second.tag){
        vector<int> cache = iter->second.dislike;
        for(int i=0; i<cache.size(); i++){
          int id = cache[i];
          if(classA.find(id) != classA.end()){ cout<< 0 <<endl; return 0; }
          if(classB.find(id) != classB.end()){ cout<< 0 <<endl; return 0; }
          classB.insert(pair<int,kid> (id, lists[id]));
        }
        iter->second.marktag();
      }
    }

    for(iter = classB.begin(); iter != classB.end(); iter++){
      if(iter->second.tag){
        vector<int> cache = iter->second.dislike;
        for(int i=0; i<cache.size(); i++){
          int id = cache[i];
          if(classA.find(id) != classA.end()){ cout<< 0 <<endl; return 0; }
          if(classB.find(id) != classB.end()){ cout<< 0 <<endl; return 0; }
          classA.insert(pair<int,kid> (id, lists[id]));
        }
        iter->second.marktag();
      }
    }
    
    if(classA.size() >= nums){ break;}
  }

  cout << 1 <<endl;
  return 0;
}