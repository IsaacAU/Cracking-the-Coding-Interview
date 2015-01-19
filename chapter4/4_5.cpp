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
