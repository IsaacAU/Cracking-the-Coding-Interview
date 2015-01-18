#include<stack>
#include<iostream>
#include<vector>

using namespace std;

class minStack{
public:
  bool empty(){
    return Stk.empty();
  }
  void push(int val){
    Stk.push(val);
    if(mStk.empty() || val<=mStk.top())
      mStk.push(val);
  }
  int top(){
    return Stk.top();
  }
  void pop(){
    if(Stk.empty()) return;
    if(Stk.top()==mStk.top())
      mStk.pop();
    Stk.pop();
  }
  int min(){
    if(mStk.empty())
      return -1;
    else
      return mStk.top();
  }
private:
  stack<int> Stk;
  stack<int> mStk;
};

void testCase(){
  minStack s;
  vector<int> v{1,1,1,2,3,2,1,2,3,4,3,2,4,5,6};
  for(auto num:v){
    s.push(num);
    cout<<"Stack push "<<num<<", min value="<<s.min()<<endl;
  }
  while(!s.empty()){
    int val=s.top();
    s.pop();
    cout<<"Stack pop "<<val<<", min value="<<s.min()<<endl;
  }
}

int main(){
  testCase();
}
