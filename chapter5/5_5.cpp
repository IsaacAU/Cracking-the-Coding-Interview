#include<iostream>
#include<bitset>

using namespace std;

int convert(int A, int B){
  int nor=A^B, res=0;
  while(nor){
    nor&=(nor-1);
    ++res;
  }
  return res;
}

int main(){
  int A,B;
  A=31;
  B=14;
  cout<<bitset<32>(A)<<endl;
  cout<<bitset<32>(B)<<endl;
  cout<<convert(A,B)<<endl;
}
