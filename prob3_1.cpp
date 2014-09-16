#include <iostream>

using namespace std;

class stack3{
    int *arr;
    int oneMax;
    int cur1, cur2, cur3;
    bool checkStackNum(int i){
        if(i!=0 && i!=1 && i!=2)
            return false;
        return true;
    }
public:
    stack3(int mx): arr(new int[3*mx]), oneMax(mx), cur1(0), cur2(mx), cur3(2*mx){}
    void push(int stackNum, int val){
        if(!checkStackNum(stackNum)){
            cerr<<"StackNum has to be 0 or 1 or 2!"<<endl;
            return;
        }
        switch(stackNum){
        case 0:
            arr[cur1++] = val;
            break;
        case 1:
            arr[cur2++] = val;
            break;
        default:
            arr[cur3++] = val;
            break;
        }
    }
    bool empty(int stackNum){
        if(!checkStackNum(stackNum)){
            cerr<<"StackNum has to be 0 or 1 or 2!"<<endl;
            return 0;
        }
        bool ret = true;
        switch(stackNum){
        case 0:
            ret = cur1==0;
            break;
        case 1:
            ret = cur2==oneMax;
            break;
        case 2:
            ret = cur3==2*oneMax;
            break;
        }
        return ret;
    }
    int top(int stackNum){
        if(!checkStackNum(stackNum)){
            cerr<<"StackNum has to be 0 or 1 or 2!"<<endl;
            return 0;
        }
        int ret = 0;
        if(!empty(stackNum)){
            switch(stackNum){
            case 0:
                ret = arr[cur1-1];
                break;
            case 1:
                ret = arr[cur2-1];
                break;
            case 2:
                ret = arr[cur3-1];
                break;
            }
            return ret;
        }else{
            cerr<<"Stack number "<<stackNum<<" is empty!"<<endl;
            return 0;
        }

    }
    void pop(int stackNum){
        if(!checkStackNum(stackNum)){
            cerr<<"StackNum has to be 0 or 1 or 2!"<<endl;
            return;
        }
        if(!empty(stackNum)){
            switch(stackNum){
            case 0:
                --cur1;
                break;
            case 1:
                --cur2;
                break;
            case 2:
                --cur3;
                break;
            }
        }
    }
    ~stack3(){ delete [] arr; }
};

int main()
{
    stack3 stk(100);
    for(int i = 0; i != 20; ++i)
        for(int j = 0; j != 3; ++j)
            stk.push(j,i+j);

    int stkNum = 0;
    // pop stack 1
    while(!stk.empty(stkNum)){
        cout<<stk.top(stkNum)<<"\t";
        stk.pop(stkNum);
    }
    cout<<endl;

    // pop stack 2
    stkNum = 1;
    while(!stk.empty(stkNum)){
        cout<<stk.top(stkNum)<<"\t";
        stk.pop(stkNum);
    }
    cout<<endl;

    // pop stack 3
    stkNum = 2;
    while(!stk.empty(stkNum)){
        cout<<stk.top(stkNum)<<"\t";
        stk.pop(stkNum);
    }
    cout<<endl;
    return 0;
}
