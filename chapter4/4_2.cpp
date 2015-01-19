#include<iostream>
#include<vector>

using namespace std;

void display(vector<vector<int>> &graph){
  for(auto row:graph){
    for(auto x:row)
      cout<<x<<" ";
    cout<<endl;
  }
}

bool existRoute(vector<vector<int>> &graph, int i, int j){
  if(graph[i][j])
    return true;
  else{
    bool res=false;
    for(auto k=0; k<graph[i].size(); ++k)
      if(k!=i && graph[i][k] && existRoute(graph, k, j)){
        res=true;
        break;
      }
    return res;
  }
}

void testCase(vector<vector<int>> graph){
  cout<<"test Graph:"<<endl;
  display(graph);
  int n=graph.size();
  for(auto i=0; i<n; ++i){
    for(auto j=i; j<n; ++j){
      if(existRoute(graph, i, j))
        cout<<i+1<<" and "<<j+1<<" have connecting route!"<<endl;
      else
        cout<<i+1<<" and "<<j+1<<" don't have connecting route!"<<endl;
    }
  }
}


int main(){
  testCase({{0,1,1},
            {0,0,0},
            {0,1,0}});
}
