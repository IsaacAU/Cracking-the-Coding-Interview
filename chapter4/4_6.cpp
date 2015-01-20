#include<iostream>
#include<vector>
#include"BTree.h

using namespace std;

TreeNode *commonAncestor(TreeNode *root, TreeNode *nd1, TreeNode *nd2){
  if(root==nullptr || nd1==nullptr || nd2==nullptr) return nullptr;
  if(root==nd1 || root==nd2)  return root;
  TreeNode *left=commonAncestor(root->left, nd1, nd2), *right=commonAncestor(root->right, nd1, nd2);
  if(left!=nullptr && right!=nullptr) return root;
  return left==nullptr?right:left;
}

void testCase(vector<int> v){
  int i=0;
  TreeNode *root=build(v, i);
  cout<<"original tree:"<<endl;
  display(root);    cout<<endl;
  TreeNode *nd1=root, *nd2=root->left;
  TreeNode *res=commonAncestor(root, nd1, nd2);
  cout<<"Common ancestor of "<<nd1->val<<" and "<<nd2->val<<" is "<<res->val<<endl;
  nd1=root->left->left;   nd2=root->left->right;
  res=commonAncestor(root, nd1, nd2);
  cout<<"Common ancestor of "<<nd1->val<<" and "<<nd2->val<<" is "<<res->val<<endl;
}

int main(){
  testCase({1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1});
}

