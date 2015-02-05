int shortest(vector<string> &vs, string &word1, string &word2){
    unordered_map<string, vector<int>> m;
    for(int i=0; i<vs.size(); ++i)
        m[vs[i]].push_back(i);
    int res=INT_MAX;
    for(int x:m[word1]){
        vector<int> &v=m[word2];
        int i=0, j=v.size()-1;
        while(i<j){
            int mid=(i+j)/2;
            if(v[mid]>x)
                j=mid-1;
            else
                i=mid+1;
        }
        if(v[i]<x){
            res=min(res, x-v[i]);
            if(i<v.size()-1)
                res=min(res, v[i+1]-x);
        }else{
            res=min(res, v[i]-x);
            if(i>0)
                res=min(res, x-v[i-1]);
        }
    }
    return res;
}
