#include<vector>
#include<iostream>

using namespace std;

struct Color{
  int r,g,b;
  Color(int x=0, int y=0, int z=0):r(x), g(y), b(z){}
  Color(const Color &c):r(c.r), g(c.g), b(c.b){}
  Color& operator=(const Color &c){
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

ostream& operator<<(ostream &os, Color &c){
  os<<"("<<c.r<<","<<c.g<<","<<c.b<<")";
  return os;
}

ostream& operator<<(ostream &os,vector<vector<Color>> &board){
  for(auto vc:board){
    for(auto c:vc)
      os<<c<<" ";
    os<<endl;
  }
  return os;
}

int main(){
  vector<vector<Color>> board{{{0,1,0},{1,0,1},{1,1,0}},
                              {{1,2,1},{1,2,2},{1,0,1}},
                              {{1,4,4},{1,3,0},{1,3,1}}};
  cout<<board<<endl;
  Color c{1,0,1};
  paint(board, 0, 0, c);
  cout<<board<<endl;
}
