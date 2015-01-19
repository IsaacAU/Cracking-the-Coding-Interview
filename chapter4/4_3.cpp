#include<vector>
#include<iostream>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

void inorder(TreeNode *nd){
  if(nd==nullptr) return;
  inorder(nd->left);
  cout<<nd->val<<" ";
  inorder(nd->right);
}

TreeNode *createIter(vector<int>::iterator b, vector<int>::iterator e){
  if(b==e)  return nullptr;
  auto m=next(b, distance(b,e)/2);
  TreeNode *root=new TreeNode(*m);
  root->left=createIter(b, m);
  root->right=createIter(next(m), e);
  return root;
}

TreeNode *create(vector<int> &v){
  return createIter(begin(v), end(v));
}

void remove(TreeNode *nd){
  if(nd==nullptr) return;
  remove(nd->left);
  remove(nd->right);
  delete(nd);
  nd=nullptr;
}

void testCase(vector<int> v){
  cout<<"original vector:"<<endl;
  for(auto x:v)
    cout<<x<<" ";
  cout<<endl;
  TreeNode *root=create(v);
  inorder(root);  cout<<endl;
  remove(root);
}

int main(){
  testCase({1,2,3,4,5,6,7});
}


