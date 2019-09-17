#include <iostream>
using namespace std;

int main() {
 long n,m,k;
 cin>>n>>m>>k;
 int a,b;
 a = 0;
 b = 0;
 while((n-a)*(m-b) > k) {
  if(m == n) {
   a++;
   b++;
  }else if(m > n) {
   a++;
  }else {
   b++;
  } 
 }
 cout<<a+b<<endl;
 return 0;
}