#include<vector>
#include<algorithm>

using namespace std;

struct People{
  int height, weight;
};

int highTower(vector<People> &vp){
  sort(begin(vp), end(vp), [](People &p1, People &p2){  return p1.height<p2.height || p1.height==p2.height && p1.weight<p2.weight; }
  int res=0, inc=1;
  for(int i=1; i<vp.size(); ++i){
    if(vp[i].weight>=vp[i-1].weight)
      ++inc;
    else
      inc=1;
    res=max(res, inc);
  }
  return res;
}
