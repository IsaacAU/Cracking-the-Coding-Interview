#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;

class SetOfStacks{
    vector<stack<int> > svec;
    int thd;
    int idx;
public:
    SetOfStacks(int i): thd(i), idx(0) { stack<int> stk;  svec.push_back(stk);}
    void push(int val){
        if(svec[idx].size()==thd){
            stack<int> stk;
            svec.push_back(stk);
            ++idx;
        }
        svec[idx].push(val);
    }
    int pop(){
        if(svec[idx].empty()){
            if(idx==0){
                cerr<<"The stack is empty!"<<endl;
                return 0;
            }
            --idx;
        }
        int tp = svec[idx].top();
        svec[idx].pop();
        return tp;
    }
    int index() const{
        return idx;
    }
    bool empty() const{
        if(idx==0 && svec[idx].empty())
            return true;
        return false;
    }
    int popAt(int index){
        if(index>idx){
            cerr<<"Entered index out of range!"<<endl;
            return 0;
        }
        int tp = svec[index].top();
        svec[index].pop();
        return tp;
    }
};

int main()
{
    SetOfStacks sos(20);
    cout<<"Push:"<<endl;
    for(int i = 0; i != 50; ++i){
        int tmp = rand()%10;
        sos.push(tmp);
        cout<<i<<"\t"<<sos.index()<<"\t"<<tmp<<endl;
    }
    cout<<"Pop:"<<endl;
    for(int i = 0; i != 5; ++i)
        cout<<sos.index()<<"\t"<<sos.popAt(1)<<endl;
    while(!sos.empty()){
        cout<<sos.index()<<"\t"<<sos.pop()<<endl;
    }
    return 0;
}
