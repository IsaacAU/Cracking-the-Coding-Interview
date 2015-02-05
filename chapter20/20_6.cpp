vector<int> findKlarge(vector<int> &big, int k){
    auto it=next(begin(big), k);
    nth_element(begin(big), it, end(big), greater<int>());
    return vector<int>(begin(big), it);
}
