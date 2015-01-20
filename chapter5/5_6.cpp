#include<iostream>
#include<bitset>

using namespace std;

int swap(int x){
  return (x & 0x55555555)<<1 | (x>>1) & 0x55555555;
}

int main(){
  int x=100;
  cout<<bitset<32>(x)<<endl;
  cout<<bitset<32>(swap(x))<<endl;
}
