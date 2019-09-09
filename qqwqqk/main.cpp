#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

void changeboard(vector<vector<char>>& board){

  class point{
  public:
    int x,y;
    point(int _x=0, int _y=0){ x = _x; y = _y; }
  };

  queue<point> list;
  const int row = board.size();
  if(row < 1) { return ; }
  const int col = board[0].size();

  for(int i=0; i<col; i++){
    if(board[0][i] == 'O'){ point item(0,i); list.push(item); }
    if(board[row-1][i] == 'O'){ point item(row-1,i); list.push(item); }
  }
  for(int i=0; i<row; i++){
    if(board[i][0] == 'O'){ point item(i,0); list.push(item); }
    if(board[i][col-1] == 'O'){ point item(i,col-1); list.push(item); }
  }

  while(!list.empty()){
    point item = list.front(); list.pop();
    board[item.x][item.y] = '#';
    if(item.x > 0){ if(board[item.x-1][item.y] == 'O'){ point val(item.x-1,item.y); list.push(val); }}
    if(item.y > 0){ if(board[item.x][item.y-1] == 'O'){ point val(item.x,item.y-1); list.push(val); }}
    if(item.x < row-1){ if(board[item.x+1][item.y] == 'O'){ point val(item.x+1,item.y); list.push(val); }}
    if(item.y < col-1){ if(board[item.x][item.y+1] == 'O'){ point val(item.x,item.y+1); list.push(val); }}
  }

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(board[i][j] != '#'){board[i][j] = 'X';}
      else {board[i][j] = 'O';}
    }
  }
};

int main () {
  vector<vector<char>> board;
  vector<char> row1 = {'X','X','X','X','X','X','X','X'};
  vector<char> row2 = {'X','O','O','X','X','O','X','X'};
  vector<char> row3 = {'X','X','O','X','X','X','O','O'};
  vector<char> row4 = {'X','O','X','X','X','X','X','X'};

  board.push_back(row1); board.push_back(row2); board.push_back(row3); board.push_back(row4);

  changeboard(board);

  const int row = board.size();
  const int col = board[0].size();

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cout<< board[i][j]<<' ';
    }
    cout<<endl;
  }

  return 0;
}