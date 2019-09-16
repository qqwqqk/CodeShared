#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

   vector<string> letterCombinations(string digits) {
        map<int,string> dictionary;
        dictionary.insert(pair<int, string> (2,"abc"));
        dictionary.insert(pair<int, string> (3,"def"));
        dictionary.insert(pair<int, string> (4,"ghi"));
        dictionary.insert(pair<int, string> (5,"jkl"));
        dictionary.insert(pair<int, string> (6,"mno"));
        dictionary.insert(pair<int, string> (7,"pqrs"));
        dictionary.insert(pair<int, string> (8,"tuv"));
        dictionary.insert(pair<int, string> (9,"wxyz"));

        queue<string> queuelist;
        queuelist.push(digits);
        while(1){
          int nums = queuelist.size();
          string str = queuelist.front();
          for(int i=0; i < str.size(); i++){
            if(str[i] > '0' && str[i] <= '9'){
              int key = str[i] - '0';
              queuelist.pop();
              string temp = dictionary[key];
              for(int j=0; j<temp.size(); j++){
                str[i] = temp[j];
                queuelist.push(str);
              }
              break;
            }
          }

          if(queuelist.size() <= nums){ break; }
        }

        vector<string> result;
        while(!queuelist.empty()){
          string item = queuelist.front();
          if(item.size() > 0){ result.push_back(item); }
          queuelist.pop();
        }

        return result;
    }

int main () {
  string str;
  getline(cin, str,'\n');

  vector<string> lists = letterCombinations(str);

  for(int i=0; i<lists.size(); i++){
    cout<< lists.front();
    if(i+1<lists.size()){cout<<',';}
  }


  return 0;
}