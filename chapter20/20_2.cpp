void shuffle(vector<int> &deck){
    const int n=deck.size();
    for(int i=0; i<n; ++i){
        int idx=int(rand()/RAND_MAX*(n-i))+i;
        swap(deck[i], deck[idx]);
    }
}
