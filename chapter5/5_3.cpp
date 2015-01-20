#include<iostream>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;

void binPermute(int x){
  string s;
  while(x){
    s=char('0'+x%2)+s;
    x/=2;
  }
  string small(s);
  if(prev_permutation(begin(small), end(small)))
    cout<<"next smallest:\t"<<small<<endl;
  else
    cout<<"next smallest doesn't exist!"<<endl;
  string largest(s);
  if(next_permutation(begin(largest), end(largest)))
    cout<<"next largest:\t"<<largest<<endl;
  else
    cout<<"next largest doesn't exist!"<<endl;
}

int main(){
  int x=10;
  cout<<"original number:\t"<<bitset<32>(x)<<endl;
  binPermute(x);
}
