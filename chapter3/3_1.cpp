#include<vector>
#include<iostream>
#include<cassert>

using namespace std;

class stack3{
public:
  stack3(int x):v(3*x, 0), eachCap(x), pos{0,x,2*x}{}
  bool empty(int stkNo){
    assert(stkNo>=0 && stkNo<3);
    return pos[stkNo]==stkNo*eachCap;
  }
  bool push(int stkNo, int val){
    assert(stkNo>=0 && stkNo<3);
    if(pos[stkNo]==(stkNo+1)*eachCap)
      return false;
    else{
      v[pos[stkNo]++]=val;
      return true;
    }
  }
  bool pop(int stkNo){
    assert(stkNo>=0 && stkNo<3);
    if(pos[stkNo]==stkNo*eachCap)
      return false;
    else{
      --pos[stkNo];
      return true;
    }
  }
  int top(int stkNo){
    assert(stkNo>=0 && stkNo<3);
    if(pos[stkNo]==stkNo*eachCap)
      return -1;
    else
      return v[pos[stkNo]-1];
  }

private:
  vector<int> v;
  int eachCap;
  vector<int> pos;
};

void testCase(){
  stack3 s(100);
  for(int stkNo=0; stkNo<3; ++stkNo)
    for(int i=1; i<10; ++i){
      s.push(stkNo, i);
      cout<<"#"<<stkNo+1<<" stack push "<<i<<endl;
    }
  for(int stkNo=0; stkNo<3; ++stkNo)
    while(!s.empty(stkNo)){
      int val=s.top(stkNo);
      s.pop(stkNo);
      cout<<"#"<<stkNo+1<<" stack pop value "<<val<<endl;
    }
}

int main(){
  testCase();
}
