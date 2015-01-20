#include<iostream>
#include<bitset>
#include<string>
#include<cmath>
#include<stdlib.h>

using namespace std;

void BinPrint(string s){
  char *c='\0';
  bool neg=false;
  double num=strtod(s.c_str(), &c);
  if(num<0){
    neg=true;
    num=-num;
  }
  int digits=num;
  num-=digits;
  string res;
  while(digits){
    res=char('0'+digits%2)+res;
    digits/=2;
  }
  if(res.empty())
    res="0";
  else if(neg)
    res='-'+res;
  if(abs(num)<1e-10){
    cout<<res<<endl;
    return;
  }
  res+='.';
  cout<<num<<endl;
  while(num>0){
    if(res.length()>64){
      cout<<"ERROR"<<endl;
      return;
    }
    num*=2;
    if(num>=1){
      res+='1';
      num-=1;
    }else{
      res+='0';
    }
  }
  cout<<res<<endl;
}

int main(){
  BinPrint("-3.25");
}
