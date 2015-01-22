#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> permute(string &s){
  vector<string> res;
  if(s.empty()) return res;
  sort(begin(s), end(s));
  do{
    res.push_back(s);
  }while(next_permutation(begin(s), end(s)));
  return res;
}
