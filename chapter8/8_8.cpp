#include<string>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

void print(vector<int> &v){
  int n=v.size();
  for(auto i:v){
    string s(n,'.');
    s[i]='Q';
    cout<<s<<endl;
  }
  cout<<endl;
}

bool valid(vector<int> &v){
  for(int k=0; k<v.size()-1; ++k){
    if(v[k]==v.back() || abs(v.back()-v[k])==v.size()-1-k)
      return false;
  }
  return true;
}

void search(int n, vector<int> &path){
  if(path.size()==n){
    print(path);
    return;
  }
  for(int x=0; x<n; ++x){
    path.push_back(x);
    if(valid(path))
        search(n, path);
    path.pop_back();
  }
}

void Nqueen(int n){
    vector<int> path;
    search(n, path);
}


int main(){
  Nqueen(4);
}
