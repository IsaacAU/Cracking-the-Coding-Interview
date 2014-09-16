#include <iostream>
#include <set>
using namespace std;

const int M=4;
const int N=4;

void display(int mtrx[][N], int m){
    for(int i = 0; i != m; ++i){
        for(int j = 0; j != N; ++j){
            cout<<mtrx[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void fill_zeros(int mtrx[][N], int m){
    set<int> row,col;
    for(int i = 0; i != m; ++i){
        for(int j = 0; j != N; ++j){
            if(mtrx[i][j]==0){
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for(set<int>::iterator it = row.begin(); it!=row.end(); ++it){
        for(int i = 0; i != N; ++i){
            mtrx[*it][i] = 0;
        }
    }
    for(set<int>::iterator it = col.begin(); it!=col.end(); ++it){
        for(int i = 0; i != m; ++i){
            mtrx[i][*it] = 0;
        }
    }
}

int main()
{
    int mtrx[][N] = {{1,2,3,4},
                     {5,6,0,8},
                     {9,0,11,12},
                     {13,14,15,16}};
    display(mtrx,M);
    fill_zeros(mtrx,M);
    display(mtrx,M);
    return 0;
}
