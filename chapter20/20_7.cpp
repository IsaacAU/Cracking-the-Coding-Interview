// method 1: hash set
bool exist(unordered_set<string> &uset, string s){
    const int n=s.length();
    for(int i=1; i<n; ++i)
        if(uset.count(s.substr(0,i)))
            if(uset.count(s.substr(i, n-i)) || exist(uset, s.substr(i, n-i)))
                return true;
    return false;
}

string longest(vector<string> &vs){
    sort(begin(vs), end(vs), [](const string &s1, const string &s2){ return s1.length()>s2.length(); });
    unordered_set<string> uset;
    for(auto &s:vs)
        uset.insert(s);
    for(auto &s:vs)
        if(exist(uset, s))
            return s;
    return string();
}

// trie
