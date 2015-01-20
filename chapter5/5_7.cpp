#include<iostream>
#include<bitset>

using namespace std;

int missing(int A[], int n){
  int res=0;
  for(int i=1; i<=n; ++i)
    res^=i;
  for(int i=0; i<n; ++i)
    res^=A[i];
  return res;
}

int main(){
  int A[]={0,1,2,3,5,6,7,8,9};
  cout<<missing(A, sizeof(A)/sizeof(*A))<<endl;
}
