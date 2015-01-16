#include<vector>
#include<iostream>
#include<random>

using namespace std;

void rotate(vector<vector<int>> &matrix){
  const int n=matrix.size();
  // clockwise
  for(int i=1; i<n; ++i)
    for(int j=0; j<i; ++j)
      swap(matrix[i][j], matrix[j][i]);
  for(int i=0; i<n; ++i)
    for(int j=0; j<n/2; ++j)
      swap(matrix[i][j], matrix[i][n-1-j]);
}

void display(vector<vector<int>> &matrix){
  for(auto v:matrix){
    for(auto i:v)
      cout<<i<<"\t";
    cout<<endl;
  }
}

void testCase(vector<vector<int>> matrix){
  cout<<"Before rotate:"<<endl;
  display(matrix);
  rotate(matrix);
  cout<<"After rotate:"<<endl;
  display(matrix);
}

int main(){
  vector<vector<int>> matrix{{1,2,3,4},
                             {5,6,7,8},
                             {9,10,11,12},
                             {13,14,15,16}};
  testCase(matrix);
}
