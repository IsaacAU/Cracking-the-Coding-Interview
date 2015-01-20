#include<vector>
#include<iostream>
#include"BTreeP.h"

using namespace std;

TreeNode *next(TreeNode *nd){
  if(nd==nullptr) return nullptr;
  if(nd->right){
    TreeNode *right=nd->right;
    while(right->left)
      right=right->left;
    return right;
  }else{
    while(nd->parent && nd->parent->right==nd)
        nd=nd->parent;
    return nd->parent;
  }
}

void testCase(vector<int> v){
  int i=0;
  TreeNode *root=build(v,i);
  cout<<"original tree inorder:"<<endl;
  display(root);  cout<<endl;
  TreeNode *nd=root;
  while(nd->left)
    nd=nd->left;
  cout<<"using next to traverse:"<<endl;
  while(nd){
    cout<<nd->val<<" ";
    nd=next(nd);
  }
  cout<<endl<<endl;
  remove(root);
}

int main(){
  testCase({4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1});
  testCase({3,2,1,-1,-1,-1,5,4,-1,-1,-1});
}
