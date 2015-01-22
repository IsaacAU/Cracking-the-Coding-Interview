#include<vector>

using namespace std;

struct Color{
  int r,g,b;
  Color& opeartor=(const Color &c){
    r=c.r;
    g=c.g;
    b=c.b;
    return *this;
  }
};

bool operator==(const Color& c1, const Color &c2){
  return c1.r==c2.r && c1.g==c2.g && c1.b==c2.b;
}

void paint(vector<vector<Color>> &board, int x, int y, Color c){
  const int m=board.size(), n=board[0].size();
  if(x<0 || x>=m || y<0 || y>=n || board[x][y]==c)  return;
  board[x][y]=c;
  paint(board, x-1, y, c);
  paint(board, x+1, y, c);
  paint(board, x, y-1, c);
  paint(board, x, y+1, c);
}

