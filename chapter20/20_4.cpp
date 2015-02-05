#include<iostream>

using namespace std;

int naiveTest2s(int n){
    int res=0, x;
    for(int i=0; i<=n; ++i){
        x=i;
        while(x){
            if(x%10==2)
                ++res;
            x/=10;
        }
    }
    return res;
}

int naiveTestKs(int n, int k){
    int res=0, x;
    for(int i=0; i<=n; ++i){
        x=i;
        do{
            if(x%10==k)
                ++res;
            x/=10;
        }while(x);
    }
    return res;
}

// count 2s
int count2(int n){
    int low=0, res=0, power=1, cur=0;
    while(n){
        int r=n%10;
        n/=10;
        if(r==2)
            cur=n*power+low+1;
        else if(r<2)
            cur=n*power;
        else
            cur=(n+1)*power;
        res+=cur;
        low+=r*power;
        power*=10;
    }
    return res;
}

// count ks (k=0,...,9)
int countK(int n, int k){
    int low=0, res=(k==0?1:0), power=1, cur=0;
    while(n){
        int r=n%10;
        n/=10;
        if(r==k)
            cur=(k==0?n-1:n)*power+low+1;
        else if(r<k)
            cur=n*power;
        else
            cur=(k==0?n:n+1)*power;
        res+=cur;
        low+=r*power;
        power*=10;
    }
    return res;
}

int main(){
    for(int i=0; i<=10000; ++i){
        for(int k=0; k<=9; ++k){
            int x=countK(i, k), y=naiveTestKs(i, k);
            if(x!=y){
                cout<<"Wrong:\t"<<i<<" "<<k<<" "<<x<<" "<<y<<endl;
                cin.get();
            }
        }
    }
}
