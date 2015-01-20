#include<iostream>
#include<bitset>

using namespace std;

void copy(int &N, int &M, int i, int j){
  N&=~((1<<(j-i+2)-1)<<i);
  N|=M<<i;
}

void testCase(int N, int M, int i, int j){
  cout<<"i="<<i<<"\tj="<<j<<endl;
  cout<<"N:\t"<<bitset<16>(N)<<endl;
  cout<<"M:\t"<<bitset<16>(M)<<endl;
  copy(N, M, i, j);
  cout<<"result:"<<endl;
  cout<<"N:\t"<<bitset<16>(N)<<endl;
}

int main(){
  int N=0b100000000, M=0b10101, i=2, j=6;
  testCase(N, M, i, j);
}
