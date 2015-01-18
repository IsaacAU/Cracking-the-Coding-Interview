#include<iostream>

using namespace std;

class SetOfStacks{
public:
  SetOfStacks(int x, int y):capacity(x), Nstacks(y), curSet(0), curPos(0){
    arr = new int*[Nstacks];
    arr[0]=new int[x];
  }
  ~SetOfStacks(){
    for(int i=0; i<=curSet; ++i){
      delete []arr[i];
    }
    delete []arr;
  }
  void push(int val){
    if(curSet==Nstacks-1 && curPos==capacity)   return;
    arr[curSet][curPos++]=val;
    if(curPos==capacity && curSet<Nstacks-1){
      arr[++curSet]=new int[capacity];
      curPos=0;
    }
  }
  void pop(){
    if(empty())  return;
    --curPos;
    if(curPos<0){
      delete arr[curSet];
      --curSet;
      curPos=capacity-1;
    }
  }
  int top(){
    if(empty())  return -1;
    if(curPos>0)
      return arr[curSet][curPos-1];
    else
      return arr[curSet-1][capacity-1];
  }
  bool empty(){
    return curSet==0 && curPos==0;
  }
private:
  int **arr;
  int capacity, Nstacks;
  int curSet, curPos;
};

void testCase(){
  SetOfStacks ss(10, 10);
  for(int i=1; i<=105; ++i){
    ss.push(i);
    cout<<"SetOfStacks push "<<ss.top()<<endl;
  }
  while(!ss.empty()){
    cout<<"SetOfStacks pop "<<ss.top()<<endl;
    ss.pop();
  }
}

int main(){
  testCase();
}
