#include<stack>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sort(stack<int> &s){
  int sz=s.size();
  if(sz<2)  return;
  stack<int> t1,t2;
  while(!s.empty()){
    t1.push(s.top());
    s.pop();
    if(s.empty()) break;
    t2.push(s.top());
    s.pop();
  }
  sort(t1);   sort(t2);
  stack<int> rvs;
  while(!t1.empty() && !t2.empty()){
    if(t1.top()<t2.top()){
      rvs.push(t1.top());
      t1.pop();
    }else{
      rvs.push(t2.top());
      t2.pop();
    }
  }
  while(!t1.empty()){
    rvs.push(t1.top());
    t1.pop();
  }
  while(!t2.empty()){
    rvs.push(t2.top());
    t2.pop();
  }
  while(!rvs.empty()){
    s.push(rvs.top());
    rvs.pop();
  }
}

void displayStack(stack<int> &s){
  stack<int> t;
  while(!s.empty()){
    t.push(s.top());
    s.pop();
  }
  while(!t.empty()){
    cout<<t.top()<<" ";
    s.push(t.top());
    t.pop();
  }
  cout<<endl;
}

void testCase(int n){
  vector<int> v;
  for(int i=1; i<=n; ++i)
    v.push_back(i);
  random_shuffle(begin(v), end(v));
  stack<int> s;
  for(auto num:v)
    s.push(num);
  displayStack(s);
  sort(s);
  displayStack(s);
}

int main(){
  testCase(1);
  testCase(5);
  testCase(10);
}

