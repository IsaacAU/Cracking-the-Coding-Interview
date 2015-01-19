#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

TreeNode *build(vector<int> &v, int &i){
  if(i>=v.size()) return nullptr;
  if(v[i]==-1){
    ++i;
    return nullptr;
  }
  TreeNode *nd=new TreeNode(v[i++]);
  nd->left=build(v, i);
  nd->right=build(v, i);
  return nd;
}

int helper(TreeNode *root){
  if(!root) return 0;
  int left=helper(root->left), right=helper(root->right);
  if(left==-1 || right==-1 || abs(left-right)>1) return -1;
  return 1+max(left, right);
}

bool balance(TreeNode *root){
  return helper(root)!=-1;
}

void remove(TreeNode *nd){
  if(nd==nullptr) return;
  remove(nd->left);
  remove(nd->right);
  delete nd;
  nd=nullptr;
}

void testCase(vector<int> v){
  int i=0;
  cout<<"Test Tree:\t";
  for(auto num:v)
    cout<<num<<" ";
  cout<<endl;
  TreeNode *root=build(v, i);
  if(balance(root))
    cout<<"It's balanced tree!"<<endl;
  else
    cout<<"It's not balanced tree!"<<endl;
  remove(root);
}

int main(){
  testCase({});
  testCase({1});
  testCase({1,2,-1,-1,3,-1,-1});
  testCase({1,2,3,-1,-1,-1,4,-1,-1});
  testCase({1,2,3,-1,-1,-1,-1});
}
