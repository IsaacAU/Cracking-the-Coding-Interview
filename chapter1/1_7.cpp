#include<iostream>
#include<vector>

using namespace std;

void fillZeros(vector<vector<int>> &matrix){
  if(matrix.empty())  return;
  const int m=matrix.size(), n=matrix[0].size();
  if(m==1 || n<=1)
    return;
  bool firstRow=false, firstCol=false;
  int i,j;
  for(j=0; j<n; ++j)
    if(matrix[0][j]==0){
      firstRow=true;
      break;
    }
  for(i=0; i<m; ++i)
    if(matrix[i][0]==0){
      firstCol=true;
      break;
    }
  for(i=1; i<m; ++i)
    for(j=1; j<n; ++j)
      if(matrix[i][j]==0){
        matrix[0][j]=0;
        matrix[i][0]=0;
      }
  for(i=1; i<m; ++i)
    for(j=1; j<n; ++j)
      if(matrix[0][j]==0 || matrix[i][0]==0)
        matrix[i][j]=0;
  if(firstRow)
    for(j=0; j<n; ++j)
      matrix[0][j]=0;
  if(firstCol)
    for(i=0; i<m; ++i)
      matrix[i][0]=0;
}

void display(vector<vector<int>> &matrix){
  for(auto v:matrix){
    for(auto i:v)
      cout<<i<<"\t";
    cout<<endl;
  }
}

void testCase(vector<vector<int>> matrix){
  cout<<"Before fill:"<<endl;
  display(matrix);
  fillZeros(matrix);
  cout<<"After fill:"<<endl;
  display(matrix);
}

int main(){
  vector<vector<int>> matrix{{1,2,0,3},
                             {2,3,2,4},
                             {0,1,2,3}};
  testCase(matrix);
}
