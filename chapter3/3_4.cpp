#include<stack>
#include<vector>
#include<iostream>

using namespace std;

class Hanoi{
public:
  Hanoi(int n):rods(3, stack<int>()){
    for(int i=n; i>0; --i)
      rods[0].push(i);
  }
  void move(int from, int mid, int to, int n){
    if(n==0)  return;
    if(n==1){
      rods[to].push(rods[from].top());
      rods[from].pop();
      return;
    }
    move(from, to, mid, n-1);
    rods[to].push(rods[from].top());
    rods[from].pop();
    move(mid, from, to, n-1);
  }
  void displayConfig(){
    stack<int> tmp;
    for(int i=0; i<3; ++i){
        cout<<"rod#"<<i+1<<": ";
        while(!rods[i].empty()){
            tmp.push(rods[i].top());
            rods[i].pop();
        }
        while(!tmp.empty()){
            cout<<tmp.top()<<" ";
            rods[i].push(tmp.top());
            tmp.pop();
        }
        cout<<endl;
    }
  }
private:
  vector<stack<int>> rods;
};

void testCase(){
  Hanoi h(7);
  cout<<"initial config:"<<endl;
  h.displayConfig();
  h.move(0, 1, 2, 7);
  cout<<"after move:"<<endl;
  h.displayConfig();
}

int main(){
  testCase();
}
