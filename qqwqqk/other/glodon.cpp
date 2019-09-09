#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

class point{
public:
  int x,y;
  point(int _x=0, int _y=0){
    x = _x;
    y = _y;
  }
};

vector<vector<char>> changeChess(vector<vector<char>> chess, int n = 4){
  queue<point> list;
  for(int i=0; i<n; i++){
    if(chess[0][i] == 'O'){ point item(0,i); list.push(item); }
    if(chess[i][0] == 'O'){ point item(i,0); list.push(item); }
    if(chess[n-1][i] == 'O'){ point item(n-1,i); list.push(item); }
    if(chess[i][n-1] == 'O'){ point item(i,n-1); list.push(item); }
  }

  while(!list.empty()){
    point item = list.front(); list.pop();
    chess[item.x][item.y] = '#';
    if(item.x > 0){ if(chess[item.x-1][item.y] == 'O'){ point val(item.x-1,item.y); list.push(val); }}
    if(item.y > 0){ if(chess[item.x][item.y-1] == 'O'){ point val(item.x,item.y-1); list.push(val); }}
    if(item.x < n-1){ if(chess[item.x+1][item.y] == 'O'){ point val(item.x+1,item.y); list.push(val); }}
    if(item.y < n-1){ if(chess[item.x][item.y+1] == 'O'){ point val(item.x,item.y+1); list.push(val); }}
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(chess[i][j] != '#'){chess[i][j] = 'X';}
      else {chess[i][j] = 'O';}
    }
  }
  return chess;
};

int main () {
  const int n = 4;
  vector<vector<char>> chess;
  vector<char> row1 = {'X','X','X','X'};
  vector<char> row2 = {'X','O','O','X'};
  vector<char> row3 = {'X','X','O','X'};
  vector<char> row4 = {'X','O','X','X'};

  chess.push_back(row1); chess.push_back(row2); chess.push_back(row3); chess.push_back(row4);

  chess = changeChess(chess, n);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<< chess[i][j]<<' ';
    }
    cout<<endl;
  }

  return 0;
}