#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

TreeNode *build(vector<int> &v, int &i){
  if(i==v.size()) return nullptr;
  if(v[i]==-1){
    ++i;
    return nullptr;
  }
  TreeNode *nd=new TreeNode(v[i++]);
  nd->left=build(v,i);
  nd->right=build(v,i);
  return nd;
}

void remove(TreeNode *root){
  if(root==nullptr) return;
  remove(root->left);
  remove(root->right);
  delete root;
  root=nullptr;
}

void display(TreeNode *root){
  if(root==nullptr) return;
  display(root->left);
  cout<<root->val<<" ";
  display(root->right);
}
