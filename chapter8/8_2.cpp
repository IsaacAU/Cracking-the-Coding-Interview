#include<vector>

using namespace std;

int Npath(int N){
  vector<int> v(N,1);
  for(int i=1; i<N; ++i){
    for(int j=1; j<N; ++j)
      v[j]+=v[j-1];
  }
  return v.back();
}
