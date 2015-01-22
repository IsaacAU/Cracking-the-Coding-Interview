#include<string>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void anaSort(vector<string> &vs){
  sort(begin(vs), end(vs), [](string s1, string s2){
        bool orig=s1<s2;
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        return s1==s2?orig:s1<s2;
        });
}

int main(){
    vector<string> vs{"cba", "weoigew", "wgoie", "bace", "aebc", "bca", "acb"};
    for(auto s:vs)
        cout<<s<<" ";
    cout<<endl;
    anaSort(vs);
    for(auto s:vs)
        cout<<s<<" ";
    cout<<endl;
}
