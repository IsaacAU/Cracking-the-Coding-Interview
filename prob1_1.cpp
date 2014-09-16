#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool unique1(string &str){
    for(string::size_type i = 0; i != str.length(); ++i)
        for(string::size_type j = 0; j != i; ++j)
            if(str.at(j)==str.at(i))
                return false;
    return true;
}

bool unique1(const char *arr){
    for(size_t i = 0; i != strlen(arr); ++i)
        for(size_t j = 0; j != i; ++j)
            if(arr[i]==arr[j])
                return false;
    return true;
}

const int MAX=256;
bool flag[MAX];

bool unique2(string &s){
    memset(flag, 0, sizeof(flag)/sizeof(bool));
    for(string::size_type i = 0; i != s.length(); ++i)
        if(flag[s[i]])
            return false;
        else{
            flag[s[i]] = true;
        }
    return true;
}

int main()
{
    string s("hello");
    cout<<s<<": unique1()\t"<<unique1(s)<<endl;
    cout<<s<<": unique2()\t"<<unique2(s)<<endl;
    const char *arr = "helo";
    cout<<arr<<":\t"<<unique1(arr)<<endl;

    return 0;
}
