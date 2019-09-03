#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;

class kid{
public:
  int id;
  int classtag;
  vector<int> dislike;
  kid(int _id = -1, int unlike = -1){
    id = _id;
    classtag = -1;
    if(unlike != -1){ dislike.push_back(unlike); }
  }
  bool setclass(int tag = -1){
    if(classtag < 0){ classtag = tag; return true; }
    if(classtag == tag) {return true;} else {return false;}
  }
};

int getseed(map<int,kid> lists){
  for(map<int,kid>::iterator iter = lists.begin(); iter!= lists.end(); iter++){
    if(iter->second.classtag < 0){ return iter->first;}
  }
  return -1;
};

int main(){
  int count;
  int n;
  int id_1, id_2;

  map<int,kid> lists;
  map<int,kid>::iterator iter;

  cin >> count >> n;
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

  set<int> setA, setB;
  set<int>::iterator iterset;

  while(1){
    int seed = getseed(lists);
    if(seed == -1){break;}

    setA.insert(seed);

    while(1){
      int nums = setA.size();

      for(iterset = setA.begin(); iterset != setA.end(); iterset++){
        int tag = lists[*iterset].classtag;
        if(tag < 0){
          lists[*iterset].setclass(1);
          vector<int> cache = lists[*iterset].dislike;
          for(int i=0; i<cache.size(); i++){
          int id = cache[i];
          if(setA.count(id) > 0){ cout << 0 << endl; return 0; }
          setB.insert(id);
          }
        }
      }

      for(iterset = setB.begin(); iterset != setB.end(); iterset++){
        int tag = lists[*iterset].classtag;
        if(tag < 0){
          lists[*iterset].setclass(1);
          vector<int> cache = lists[*iterset].dislike;
          for(int i=0; i<cache.size(); i++){
          int id = cache[i];
          if(setB.count(id) > 0){ cout << 0 << endl; return 0; }
          setA.insert(id);
          }
        }
      }

      if(setA.size() >= nums){ break;}
    }
  }

  cout << 1 <<endl;
  return 0;
}