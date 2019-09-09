#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

bool is_repeat(int count, int *lists, int num){
  for(int i=0; i<count; i++){
    int id = lists[i];
    if(id == num){return true;}
  }
  return false;
}

int perfectDancers(int countMorning, int countEvening, int *morningList, int *eveningList){
  int result = 0;
  for(int i=0; i<countMorning; i++){
    int id = morningList[i];
    if(!is_repeat(countEvening, eveningList, id)){ result++; }
  }
  for(int i=0; i<countEvening; i++){
    int id = eveningList[i];
    if(!is_repeat(countMorning, morningList, id)){ result++; }
  }
  return result;
}

int main () {
  int countMorning = 11; 
  int countEvening = 10;
  int morningList[] = {1,1,2,3,4,5,5,7,6,9,10};
  int eveningList[] = {11,12,13,4,5,6,7,18,19,20};

  int result = perfectDancers(countMorning, countEvening, morningList, eveningList);

  cout << result <<endl;

  return 0;
}