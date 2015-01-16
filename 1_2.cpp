#include<iostream>
#include<cstring>

using namespace std;

void reverse(char *str){
  int i=0, j=strlen(str)-1;
  while(i<j)
    swap(str[i++], str[j--]);
}

int main(){
  char str1[]="";
  cout<<"Case1:"<<endl;
  cout<<"Before reverse:\t"<<str1<<endl;
  reverse(str1);
  cout<<"After reverse:\t"<<str1<<endl;

  char str2[]="a";
  cout<<"Case2:"<<endl;
  cout<<"Before reverse:\t"<<str2<<endl;
  reverse(str2);
  cout<<"After reverse:\t"<<str2<<endl;

  char str3[]="abcd";
  cout<<"Case3:"<<endl;
  cout<<"Before reverse:\t"<<str3<<endl;
  reverse(str3);
  cout<<"After reverse:\t"<<str3<<endl;
}
