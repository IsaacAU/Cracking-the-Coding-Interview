#include<string>
#include<vector>

using namespace std;

int search(vector<string> &vs, string &s){
  int i=0, j=vs.size()-1;
  while(i<=j){
    int m=(i+j)/2;
    int x=m;
    while(x<j && vs[x]=="") ++x;
    if(x==j)
      j=m-1;
    else{
      if(vs[x]==s)  return x;
      if(vs[x]<s)
        j=m-1;
      else
        i=x+1;
    }
  }
  return -1;
}
