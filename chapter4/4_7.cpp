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

bool subtreeSameRoot(TreeNode *T1, TreeNode *T2){
  if(T2==nullptr) return true;
  if(T1==nullptr) return false;
  if(T1->val==T2->val)
    return subtreeSameRoot(T1->left, T2->left) && subtreeSameRoot(T1->right, T2->right);
  else
    return false;
}

bool subtree(TreeNode *T1, TreeNode *T2){
  if(T2==nullptr) return true;
  if(T1==nullptr) return false;
  if(T1->val==T2->val)
    if(subtreeSameRoot(T1->left, T2->left) && subtreeSameRoot(T1->right, T2->right))
      return true;
  return subtree(T1->left, T2) || subtree(T1->right, T2);
}

void testCase(vector<int> v1, vector<int> v2){
  int i=0;
  TreeNode *T1=build(v1, i);
  i=0;
  TreeNode *T2=build(v2, i);
  cout<<"big tree T1:"<<endl;
  display(T1);   cout<<endl;
  cout<<"small tree T2:"<<endl;
  display(T2);   cout<<endl;
  if(subtree(T1, T2))
    cout<<"T2 is subtree of T1!"<<endl;
  else
    cout<<"T2 is not subtree of T1!"<<endl;
  remove(T1);
  remove(T2);
}

int main(){
  testCase({1,1,2,-1,-1,3,-1,-1,3,-1,-1}, {1,2,-1,-1,3,-1,-1});
}





