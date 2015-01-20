#include<vector>
#include<iostream>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left, *right, *parent;
  TreeNode(int x):val(x), left(nullptr), right(nullptr), parent(nullptr){}
};

TreeNode *build(vector<int> &v, int &i){
  if(i==v.size()) return nullptr;
  if(v[i]==-1){
    ++i;
    return nullptr;
  }
  TreeNode *root=new TreeNode(v[i++]);
  root->left=build(v, i);
  if(root->left!=nullptr)
    root->left->parent=root;
  root->right=build(v, i);
  if(root->right!=nullptr)
    root->right->parent=root;
  return root;
}

void display(TreeNode *root){
  if(root==nullptr) return;
  display(root->left);
  cout<<root->val<<" ";
  display(root->right);
}

void remove(TreeNode *root){
  if(root==nullptr) return;
  remove(root->left);
  remove(root->right);
  delete root;
  root=nullptr;
}
