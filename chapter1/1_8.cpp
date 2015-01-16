#include<string>
#include<iostream>

using namespace std;

bool isSubstring(const string &s1, const string &s2){
  return s2.find(s1)!=string::npos;
}

bool isRotate(string &s1, string &s2){
  if(s1.length()!=s2.length())  return false;
  s1+=s1;
  return isSubstring(s2, s1);
}

void testCase(string s1, string s2){
  cout<<boolalpha;
  cout<<"s1:\t"<<s1<<endl;
  cout<<"S2:\t"<<s2<<endl;
  cout<<isRotate(s1,s2)<<endl;
}

int main(){
  testCase("abc", "abc");
  testCase("abc", "a");
  testCase("abcde", "deabc");
}
