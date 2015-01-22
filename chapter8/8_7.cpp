#include<iostream>
#include<vector>

using namespace std;

void search(vector<int> &cents, int i, int n, int &res){
  if(n==0){
    ++res;
    return;
  }
  if(i==cents.size()) return;
  for(int k=0; k<=n/cents[i]; ++k){
    search(cents, i+1, n-k*cents[i], res);
  }
}

int Nways(int n){
  vector<int> cents{25,10,5,1};
  int res=0;
  search(cents, 0, n, res);
  return res;
}
