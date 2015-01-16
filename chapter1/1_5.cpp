#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void replace(string &s){
  int i=0;
  while(i<s.length()){
    if(isspace(s[i])){
      // erase and insert
      //s.erase(i, 1);
      //s.insert(i, "%20");
      // replace
      s.replace(i, 1, "%20");
      i+=2;
    }else
      ++i;
  }
}

void testCase(string s){
  cout<<"Before replace:\t"<<s<<endl;
  replace(s);
  cout<<"After replace:\t"<<s<<endl;
}

int main(){
  testCase("");
  testCase(" ");
  testCase("   ");
  testCase("abc");
  testCase(" a b c");
}
