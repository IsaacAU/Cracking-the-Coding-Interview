#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
    stack<int> A, B;
    void AtoB(){
        while(!A.empty()){
            B.push(A.top());
            A.pop();
        }
    }
    void BtoA(){
        while(!B.empty()){
            A.push(B.top());
            B.pop();
        }
    }
public:
    void push(int num){
        BtoA();
        A.push(num);
    }
    void pop(){
        AtoB();
        if(B.empty()){
            cerr<<"The Queue is empty!"<<endl;
            return;
        }
        B.pop();
    }
    int front(){
        AtoB();
        if(B.empty()){
            cerr<<"The Queue is empty!"<<endl;
            return 0;
        }else
            return B.top();
    }
    int back(){
        BtoA();
        if(A.empty()){
            cerr<<"The Queue is empty!"<<endl;
            return 0;
        }else
            return A.top();
    }
    bool empty(){
        if(A.empty() && B.empty())
            return true;
        return false;
    }
};

int main(){
    MyQueue q;
    for(int i = 0; i != 10; ++i){
        q.push(i);
        cout<<"front:"<<q.front()<<"\t"<<"back:"<<q.back()<<endl;
    }
    while(!q.empty()){
        cout<<"front:"<<q.front()<<"\t"<<"back:"<<q.back()<<endl;
        q.pop();
    }
    return 0;
}
