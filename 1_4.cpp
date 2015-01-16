#include<string>
#include<iostream>

using namespace std;

bool anagram(const string &s1, const string &s2){
  if(s1.length()!=s2.length())  return false;
  int arr[256];
  fill_n(arr, 256, 0);
  for(int i=0; i<s1.length(); ++i){
    ++arr[unsigned(s1[i])];
    --arr[unsigned(s2[i])];
  }
  for(int i=0; i<256; ++i)
    if(arr[i]!=0)
      return false;
  return true;
}

void testCase(string s1, string s2){
  cout<<boolalpha;
  cout<<"s1:\t"<<s1<<endl;
  cout<<"s2:\t"<<s2<<endl;
  cout<<anagram(s1,s2)<<endl;
}

int main(){
  testCase("abc", "a");
  testCase("ab", "ba");
  testCase("abc", "abe");
}
