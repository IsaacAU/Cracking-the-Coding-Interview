#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string &big, string &small){
    return big.find(small)!=string::npos;
}

bool check_rotate(string &s1, string &s2){
    if(s1.length()!=s2.length())
        return false;
    string s = s1+s1;
    return isSubstring(s,s2);
}

int main()
{
    string s1("waterbottle"), s2("erbottlewat");
    if(check_rotate(s1,s2))
        cout<<"\""<<s2<<"\" is rotate of \""<<s1<<"\"!"<<endl;
    else
        cout<<"\""<<s2<<"\" is not rotate of \""<<s1<<"\"!"<<endl;
    return 0;
}
