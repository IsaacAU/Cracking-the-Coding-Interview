#include <iostream>
#include <stack>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

class Hanoi{
    stack<int> A;
    stack<int> B;
    stack<int> C;
    int n;
public:
    Hanoi(int i): n(i){
        while(!A.empty()) A.pop();
        while(!B.empty()) B.pop();
        while(!C.empty()) C.pop();
        for(int j=n; j != 0; --j)
            A.push(j);
    }
    bool movable(char from, char to){
        if(from==to)
            return false;
        if((from != 'A' && from != 'B' && from != 'C') || (to != 'A' && to != 'B' && to != 'C'))
            return false;
        int tmp;
        switch(from){
            case 'A':
                if(A.empty())  return false;
                tmp = A.top(); break;
            case 'B':
                if(B.empty())  return false;
                tmp = B.top(); break;
            case 'C':
                if(C.empty())  return false;
                tmp = C.top(); break;
        }
        switch(to){
            case 'A':
                if(!A.empty() && A.top()<=tmp)   return false;
                break;
            case 'B':
                if(!B.empty() && B.top()<=tmp)   return false;
                break;
            case 'C':
                if(!C.empty() && C.top()<=tmp)   return false;
                break;
        }
        return true;
    }
        bool push(char ch, int num){
        if(ch!='A' && ch!='B' && ch!='C'){
            return false;
        }
        switch(ch){
            case 'A':
                if(!A.empty() && A.top()<=num)
                    return false;
                A.push(num);
                break;
            case 'B':
                if(!B.empty() && B.top()<=num)
                    return false;
                B.push(num);
                break;
            case 'C':
                if(!C.empty() && C.top()<=num)
                    return false;
                C.push(num);
                break;
        }
        return true;
    }
    int top(char ch){
        switch(ch){
            case 'A':
                return A.top();
            case 'B':
                return B.top();
            case 'C':
                return C.top();
            default:
                return -1;
        }
    }
    bool pop(char ch){
        if(ch!='A' && ch!='B' && ch!='C'){
            return false;
        }
        switch(ch){
            case 'A':
                if(A.empty()) return false;
                A.pop();   break;
            case 'B':
                if(B.empty()) return false;
                B.pop();   break;
            case 'C':
                if(C.empty()) return false;
                C.pop();   break;
        }
        return true;
    }
    bool empty(char ch){
        if(ch!='A' && ch!='B' && ch!='C'){
            cerr<<"Character incorrect!"<<endl;
            return false;
        }
        switch(ch){
            case 'A':
                return A.empty();
            case 'B':
                return B.empty();
            case 'C':
                return C.empty();
        }
    }
    bool move(char from, char to){
        if(!movable(from,to))
            return false;
        int tmp = top(from);
        pop(from);
        push(to,tmp);
        return true;
    }
    void display(char symbol='*'){
        system("cls");
        cout<<endl<<endl<<endl;
        stack<int> At, Bt, Ct;
        for(int i = 0; i != n+1; ++i){
            cout<<"\t";
            int numA, numB, numC;
            bool reachA = (n+1-i==A.size());
            bool reachB = (n+1-i==B.size());
            bool reachC = (n+1-i==C.size());
            if(reachA){
                numA = A.top();
                A.pop();
                At.push(numA);
                cout<<setw(n+2-numA);
                for(int i = 0; i != numA; ++i) cout<<symbol;
                cout<<'|';
                for(int i = 0; i != numA; ++i) cout<<symbol;
                cout<<setw(n+2-numA);
            }else{
                cout<<setw(n+2)<<'|'<<setw(n+2);
            }
            cout<<' '<<'x'<<' ';
            if(reachB){
                numB = B.top();
                B.pop();
                Bt.push(numB);
                cout<<setw(n+2-numB);
                for(int i = 0; i != numB; ++i) cout<<symbol;
                cout<<'|';
                for(int i = 0; i != numB; ++i) cout<<symbol;
                cout<<setw(n+2-numB);
            }else{
                cout<<setw(n+2)<<'|'<<setw(n+2);
            }
            cout<<' '<<'x'<<' ';
            if(reachC){
                numC = C.top();
                C.pop();
                Ct.push(numC);
                cout<<setw(n+2-numC);
                for(int i = 0; i != numC; ++i) cout<<symbol;
                cout<<'|';
                for(int i = 0; i != numC; ++i) cout<<symbol;
            }else{
                cout<<setw(n+2)<<'|';
            }
            cout<<endl;
        }
        cout<<"\t";
        for(int j = 0; j != 3; ++j){
            cout<<setw(1);
            for(int i = 0; i != n+1; ++i) cout<<'-';
            cout<<'|';
            for(int i = 0; i != n+1; ++i) cout<<'-';
            cout<<setw(1);
            if(j!=2)
                cout<<' '<<'x'<<' ';
            else
                cout<<endl;
        }
        cout<<"\t"<<setw(n+2)<<'A'<<setw(2*n+6)<<'B'<<setw(2*n+6)<<'C'<<endl;
        while(!At.empty()) { A.push(At.top()); At.pop(); }
        while(!Bt.empty()) { B.push(Bt.top()); Bt.pop(); }
        while(!Ct.empty()) { C.push(Ct.top()); Ct.pop(); }
    }
    void display_float(int num, bool flt, char cur, char symbol='*'){
        system("cls");
        cout<<endl<<endl;
        cout<<"\t";
        if(!flt)
            cout<<setw(n+2)<<(cur=='A'?'V':' ')<<setw(2*n+6)<<(cur=='B'?'V':' ')<<setw(2*n+6)<<(cur=='C'?'V':' ')<<endl;
        else{
            char ch[] = {'A', 'B', 'C'};
            for(int i = 0; i != 3; ++i){
                if(cur==ch[i]){
                    cout<<setw(n+2-num);
                    for(int j = 0; j != num; ++j) cout<<symbol;
                    cout<<' ';
                    for(int j = 0; j != num; ++j) cout<<symbol;
                    if(i!=2)
                        cout<<setw(n+2-num);
                }else{
                    cout<<setw(n+2)<<' ';
                    if(i!=2)
                        cout<<setw(n+2);
                }
                if(i!=2)
                    cout<<' '<<' '<<' ';
                else
                    cout<<endl;
            }
        }
        stack<int> At, Bt, Ct;
        for(int i = 0; i != n+1; ++i){
            cout<<"\t";
            int numA, numB, numC;
            bool reachA = (n+1-i==A.size());
            bool reachB = (n+1-i==B.size());
            bool reachC = (n+1-i==C.size());
            if(reachA){
                numA = A.top();
                A.pop();
                At.push(numA);
                cout<<setw(n+2-numA);
                for(int i = 0; i != numA; ++i) cout<<symbol;
                cout<<'|';
                for(int i = 0; i != numA; ++i) cout<<symbol;
                cout<<setw(n+2-numA);
            }else{
                cout<<setw(n+2)<<'|'<<setw(n+2);
            }
            cout<<' '<<'x'<<' ';
            if(reachB){
                numB = B.top();
                B.pop();
                Bt.push(numB);
                cout<<setw(n+2-numB);
                for(int i = 0; i != numB; ++i) cout<<symbol;
                cout<<'|';
                for(int i = 0; i != numB; ++i) cout<<symbol;
                cout<<setw(n+2-numB);
            }else{
                cout<<setw(n+2)<<'|'<<setw(n+2);
            }
            cout<<' '<<'x'<<' ';
            if(reachC){
                numC = C.top();
                C.pop();
                Ct.push(numC);
                cout<<setw(n+2-numC);
                for(int i = 0; i != numC; ++i) cout<<symbol;
                cout<<'|';
                for(int i = 0; i != numC; ++i) cout<<symbol;
            }else{
                cout<<setw(n+2)<<'|';
            }
            cout<<endl;
        }
        cout<<"\t";
        for(int j = 0; j != 3; ++j){
            cout<<setw(1);
            for(int i = 0; i != n+1; ++i) cout<<'-';
            cout<<'|';
            for(int i = 0; i != n+1; ++i) cout<<'-';
            cout<<setw(1);
            if(j!=2)
                cout<<' '<<'x'<<' ';
            else
                cout<<endl;
        }
        cout<<"\t"<<setw(n+2)<<'A'<<setw(2*n+6)<<'B'<<setw(2*n+6)<<'C'<<endl;
        while(!At.empty()) { A.push(At.top()); At.pop(); }
        while(!Bt.empty()) { B.push(Bt.top()); Bt.pop(); }
        while(!Ct.empty()) { C.push(Ct.top()); Ct.pop(); }
    }
    void moveAll(int n, char from, char to, char mid){
        Sleep(100);
        if(n==1){
            move(from, to);  display();
        }
        else{
            moveAll(n-1, from, mid, to);
            move(from, to);  display();
            moveAll(n-1, mid, to, from);
        }
    }
};

int main()
{
    int n = 8;
    Hanoi h(n);
    //h.moveAll(n, 'A', 'C', 'B');

    bool flt = false;
    char cur = 'A';
    int flt_val = 0;
    while(1){
        h.display_float(flt_val, flt, cur);
        int c = getch();
        if(c==27)   // esc key
            break;
        if(c==224){
            switch(getch()){
                case 75:   // left key
                    if(cur=='B')  cur = 'A';
                    else if(cur=='C')  cur = 'B';
                    break;
                case 77:   // right key
                    if(cur=='A')  cur = 'B';
                    else if(cur=='B')  cur = 'C';
                    break;
                case 72:   // up key
                    if(!flt && !h.empty(cur)){
                        flt = true;
                        flt_val = h.top(cur);
                        h.pop(cur);
                    }
                    break;
                case 80:   // down key
                    if(flt){
                        if(h.empty(cur) || h.top(cur)>flt_val){
                            flt = false;
                            h.push(cur, flt_val);
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}
