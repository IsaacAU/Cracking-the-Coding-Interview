#include<vector>

using namespace std;

vector<vector<int>> subset(vector<int> &set){
  vector<vector<int>> res;
  if(set.empty()) return res;
  res.push_back(vector<int>());
  for(int i=0; i<set.size(); ++i){
    int n=res.size();
    for(int j=0; j<n; ++j){
      vector<int> tmp=res[j];
      tmp.push_back(set[i]);
      res.push_back(tmp);
    }
  }
  return res;
}
