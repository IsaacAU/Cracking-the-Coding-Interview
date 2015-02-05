// using random_shuffle
vector<int> randPick(vector<int> &arr, int m){
    const int n=arr.size();
    vector<int> idx(n, 0);
    for(int i=0; i<m; ++i)
        idx[i]=1;
    random_shuffle(begin(idx), end(idx));
    vector<int> res;
    for(int i=0; i<n; ++i)
        if(idx[i])
            res.push_back(arr[i]);
    return res;
}

// straightforward
vector<int> randPick2(vector<int> &arr, int m){
    const int n=arr.size();
    for(int i=0; i<m; ++i){
        int idx=int(rand()/RAND_MAX*(n-i))+i;
        swap(arr[i], arr[idx]);
    }
    return vector<int>(arr.begin(), arr.begin()+m);
}
