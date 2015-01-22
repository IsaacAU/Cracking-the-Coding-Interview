#include<string>
#include<vector>

using namespace std;

void search(int left, int n, string &path, vector<string> &res){
  if(path.length()==2*n){
    res.push_back(path);
    return;
  }
  if(left<n){
    path.push_back('(');
    search(left+1, n, path, res);
    path.pop_back();
  }
  if(left>path.length()-left){
    path.push_back(')');
    search(left, n, path, res);
    path.pop_back();
  }
}

vector<string> allParentheses(int n){
  vector<string> res;
  string path;
  search(0, n, path, res);
  return res;
}
