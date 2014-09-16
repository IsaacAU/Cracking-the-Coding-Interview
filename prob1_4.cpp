#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

bool anagram(string str1, string str2){
    if(str1.length()!=str2.length())
        return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if(str1==str2)
        return true;
    else
        return false;
}

const int MAX=256;
int cnt[MAX];

bool anagram2(string &str1, string &str2){
    if(str1.length()!=str2.length())
        return false;
    memset(cnt, 0, sizeof(cnt)/sizeof(int));
    for(int i = 0; i != str1.length(); ++i){
        ++cnt[str1[i]];
        --cnt[str2[i]];
    }
    for(int i = 0; i != MAX; ++i)
        if(cnt[i])
            return false;
    return true;
}

int main()
{
    string s1("hello"), s2("llhho");
    cout<<s1<<" and "<<s2<<(anagram2(s1,s2)?" are anagram!":" aren't anagram!")<<endl;
    return 0;
}
