#include<iostream>
#include<string>

using namespace std;

int remove(string &s){
  if(s.length()<2)  return s.length();
  int pos=1, i=1;
  bool exist;
  for(; i<s.length(); ++i){
    exist=false;
    for(int j=0; j<pos; ++j){
      if(s[j]==s[i]){
        exist=true;
        break;
      }
    }
    if(!exist){
      if(pos!=i)
        s[pos]=s[i];
      ++pos;
    }
  }
  return pos;
}

void testCase(string s){
  cout<<"Before remove:\t"<<s<<endl;
  int n=remove(s);
  cout<<"After remove:\t"<<s.substr(0,n)<<endl;
}

int main(){
  cout<<"Case1:"<<endl;
  testCase("");

  cout<<"Case2:"<<endl;
  testCase("a");

  cout<<"Case3:"<<endl;
  testCase("abc");

  cout<<"Case4:"<<endl;
  testCase("aab");

  cout<<"Case5:"<<endl;
  testCase("abcabcadecb");
}
