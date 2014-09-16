#include <iostream>
#include <string>
using namespace std;

void remove_duplicate(string &str){
    for(string::size_type i = 0; i != str.length();){
        bool flag = false;
        for(string::size_type j = 0; j != i; ++j){
            if(str[i]==str[j]){
                flag = true;
                break;
            }
        }
        if(flag)
            str.erase(str.begin()+i);
        else
            ++i;
    }
}

void remove_duplicate2(string &str){
    for(string::iterator it = str.begin(); it != str.end(); ){
        bool flag = false;
        for(string::iterator iter = str.begin(); iter != it; ++iter){
            if(*it==*iter){
                flag = true;
                break;
            }
        }
        if(flag)
            str.erase(it);
        else
            ++it;
    }
}

int main()
{
    string s("helloowieojgw");
    cout<<s<<endl;
    remove_duplicate2(s);
    cout<<s<<endl;
    return 0;
}
