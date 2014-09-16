#include <iostream>
#include <string>
using namespace std;

void replace_space(string &str){
    for(string::size_type i = 0; i != str.length(); ){
        if(str[i]==' '){
            str.replace(i, 1, "%20");
            i += 3;
        }else{
            ++i;
        }
    }
}

void replace_space2(string &str){
    for(string::size_type i = 0; i != str.length(); ){
        if(str[i]==' '){
            str = string(str.begin(), str.begin()+i) + "%20" + string(str.begin()+i+1, str.end());
            i += 3;
        }else
            ++i;
    }
}

int main()
{
    string s("a b c d e f g");
    cout<<s<<endl;
    replace_space2(s);
    cout<<s<<endl;
    return 0;
}
