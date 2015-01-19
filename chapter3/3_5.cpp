#include<stack>
#include<iostream>

using namespace std;

class myQueue{
public:
  void push(int val){
    stkIn.push(val);
  }
  void pop(){
    if(empty()) return;
    if(stkOut.empty())
      in2out();
    stkOut.pop();
  }
  int front(){
    if(empty()) return -1;
    if(stkOut.empty())
      in2out();
    return stkOut.top();
  }
  int back(){
    if(empty()) return -1;
    if(stkIn.empty())
      out2in();
    return stkIn.top();
  }
  bool empty(){
    return stkIn.empty() && stkOut.empty();
  }
private:
  stack<int> stkIn, stkOut;
  void in2out(){
    while(!stkIn.empty()){
        stkOut.push(stkIn.top());
        stkIn.pop();
    }
  }
  void out2in(){
    while(!stkOut.empty()){
        stkIn.push(stkOut.top());
        stkOut.pop();
    }
  }
};

void testCase(){
  myQueue q;
  for(int i=1; i<=20; ++i){
    q.push(i);
    cout<<"myQueue push "<<q.back()<<endl;
  }
  while(!q.empty()){
    cout<<"myQueue pop "<<q.front()<<endl;
    q.pop();
  }
}

int main(){
  testCase();
}
