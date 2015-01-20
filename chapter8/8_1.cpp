#include<iostream>

using namespace std;

long fib(int n){
  if(n<=2)  return 1;
  long a=1,b=2;
  for(int i=0; i<n-3; ++i){
    swap(a,b);
    b+=a;
  }
  return b;
}


int main(){
  for(int i=1; i<20; ++i){
    cout<<fib(i)<<endl;
  }
}
