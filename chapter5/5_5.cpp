#include<iostream>
#include<bitset>

using namespace std;

int convert(int A, int B){
  int res=A^B, n=0;
  while(res){
    if(res%2)
      ++n;
    res/=2;
  }
  return n;
}

int main(){
  int A,B;
  A=31;
  B=14;
  cout<<bitset<32>(A)<<endl;
  cout<<bitset<32>(B)<<endl;
  cout<<convert(A,B)<<endl;
}
