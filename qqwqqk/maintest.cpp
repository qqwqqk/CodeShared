//#include <gtest/gtest.h>
#include "_method.h"
using namespace std; 

int main(){
  /*
  bool result = true;
  string str = "1 2 3 4";
  vector<int> line = analyzeLine(str);

  cout << "analyze line" << endl;
  for(int i=0; i<line.size(); i++){ cout<<line[i]<<' '; }

  cout << "\nanalyze premutation" << endl;
  vector<vector<int>> premutation = analyzePermutation(line);
  for(int i=0; i<premutation.size(); i++){
    for(int j=0; j<premutation[j].size(); j++){ cout<<premutation[i][j]<<' '; } 
    if(i<premutation.size()) {cout<<endl;}
  }
  cout << "premutation number: " << premutation.size();

  cout<<"\nFibonacci"<<endl;
  for(int i=1; i<=10; i++){ 
    cout<< getFibonacci(i)<<" "; 
    if(i%5==0){ cout<<endl; }
  }

  cout<<"\nFactorial"<<endl;
  for(int i=1; i<=10; i++){ 
    cout<< getFactorial(i)<<" "; 
    if(i%5==0){ cout<<endl; }
  }

  cout<<"\nPrime"<<endl;
  int count = 0;
  for(int i=1; i<=100; i++){ 
    if(is_prime(i)){
      cout<< i <<" "; 
      count = count + 1;
    if(count%5 == 0){ cout<<endl; }
    }
  }
  */

  vector<int> list = {0,0,0};
  int n = 4;

  while(list.size()){
    for(int j=0; j<list.size(); j++){ cout<<list[list.size() - 1 - j]; }
    cout<<endl;
    list = decimalcarry(list,n);
  }

  cout << endl;
  return 0;
}
