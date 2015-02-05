// sort
vector<int> findKlarge1(vector<int> &big, int k){
    sort(begin(big), end(big));
    return vector<int>(big.end()-k, big.end());
}

// max heap
vector<int> findKlarge2(vector<int> &big, int k){
    make_heap(begin(big), end(big));
    vector<int> res;
    for(int i=0; i<k; ++i){
        pop_heap(begin(big), end(big)-i);
        res.push_back(big[big.size()-1-i]);

    }
    return res;
}

// use nth_element
vector<int> findKlarge3(vector<int> &big, int k){
    auto it=next(begin(big), k);
    nth_element(begin(big), it, end(big), greater<int>());
    return vector<int>(begin(big), it);
}
