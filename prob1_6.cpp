#include <iostream>

using namespace std;

const int DIM=4;

void rotate_matrix(int mtrx[][DIM], int d){
    // diagonal swap
    for(int i = 0; i != d; ++i){
        for(int j = 0; j != i; ++j){
            int tmp = mtrx[i][j];
            mtrx[i][j] = mtrx[j][i];
            mtrx[j][i] = tmp;
        }
    }
    // left and right swap
    for(int i = 0; i != d; ++i){
        for(int j = 0; j != DIM/2; ++j){
            int tmp = mtrx[i][j];
            mtrx[i][j] = mtrx[i][DIM-j-1];
            mtrx[i][DIM-j-1] = tmp;
        }
    }
}

void display(int mtrx[][DIM], int d){
    for(int i = 0; i != d; ++i){
        for(int j = 0; j != DIM; ++j)
            cout<<mtrx[i][j]<<"\t";
        cout<<endl;
    }
}

int main()
{
    int mtrx[][DIM] = {{1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12},
                       {13,14,15,16}};
    display(mtrx,4);
    rotate_matrix(mtrx,4);
    cout<<endl;
    display(mtrx,4);
    return 0;
}
