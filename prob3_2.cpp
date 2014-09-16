#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 99999;

class stack{
    int *arr;
    int Max;
    int pos;
    int Min;
    int MinPos;
public:
    stack(int mx): arr(new int[mx]), Max(mx), pos(0), Min(MAX), MinPos(0) {}
    bool empty(){
        if(pos==0)
            return true;
        return false;
    }
    bool full(){
        if(pos==Max+1)
            return true;
        return false;
    }
    void push(int val){
        if(!full()){
            arr[pos++] = val;
            if(val<Min){
                Min = val;
                MinPos = pos;
            }
        }
    }
    int top(){
        return arr[pos-1];
    }
    void pop(){
        if(!empty()){
            --pos;
            if(Min==arr[pos]){
                Min = MAX;
                for(int i = 0; i < pos; ++i)
                    if(arr[i]<Min){
                        Min = arr[i];
                        MinPos = i;
                    }
            }
        }
    }
    void print(){
        for(int i = 0; i != pos; ++i)
            cout<<arr[i]<<"\t";
        cout<<"; Min="<<Min<<endl;
    }
    ~stack(){ delete[] arr; }
};

int main()
{
    stack stk(100);
    cout<<"push:"<<endl;
    for(int i = 0; i != 20; ++i){
        stk.push(rand()%20);
        stk.print();
    }
    cout<<"pop:"<<endl;
    while(!stk.empty()){
        stk.print();
        stk.pop();
    }
    return 0;
}
