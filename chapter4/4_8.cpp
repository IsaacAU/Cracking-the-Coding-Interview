#include<iostream>
#include<vector>
#include"BTree.h"

using namespace std;

void print(vector<int> &path){
  for(auto p:path)
    cout<<p<<" ";
  cout<<endl;
}

void search(TreeNode *root, int sum, vector<int> &path){
  if(root==nullptr) return;
  if(sum==root->val){
    path.push_back(root->val);
    print(path);
    path.pop_back();
    return;
  }
  if(root->left!=nullptr)
    search(root->left, sum, path);
  if(root->right!=nullptr)
    search(root->right, sum, path);
  path.push_back(root->val);
  if(root->left!=nullptr)
    search(root->left, sum-root->val, path);
  if(root->right!=nullptr)
    search(root->right, sum-root->val, path);
  path.pop_back();
}

void sumPath(TreeNode *root, int sum){
  vector<int> path;
  search(root, sum, path);
}

void testCase(vector<int> v, int sum){
  int i=0;
  TreeNode *root=build(v, i);
  cout<<"original tree:"<<endl;
  display(root);    cout<<endl;
  cout<<"all the path sum to "<<sum<<":"<<endl;
  sumPath(root, sum);
  remove(root);
}


int main(){
  testCase({1,2,-1,-1,2,-1,-1}, 2);
}










