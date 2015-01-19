#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr){}
};

TreeNode *build(vector<int> &v, int &i){
  if(i==v.size()) return nullptr;
  if(v[i]==-1){
    ++i;
    return nullptr;
  }
  TreeNode *nd=new TreeNode(v[i++]);
  nd->left=build(v, i);
  nd->right=build(v, i);
  return nd;
}

void removeTree(TreeNode *root){
  if(root==nullptr) return;
  removeTree(root->left);
  removeTree(root->right);
  delete(root);
  root=nullptr;
}

void displayTree(TreeNode *root){
  if(root==nullptr) return;
  cout<<root->val<<" ";
  displayTree(root->left);
  displayTree(root->right);
}

void displayList(ListNode *head){
  while(head){
    cout<<head->val<<"->";
    head=head->next;
  }
}

void removeList(ListNode *head){
  while(head){
    ListNode *nd=head->next;
    delete head;
    head=nd;
  }
}

vector<ListNode*> Tree2List(TreeNode *root){
  vector<ListNode*> res;
  if(root==nullptr) return res;
  queue<TreeNode*> q;
  q.push(root);
  int cur=1, next=0;
  ListNode *lst_nd=nullptr;
  while(!q.empty()){
    TreeNode *tr_nd=q.front();  q.pop();
    if(lst_nd==nullptr){
      lst_nd=new ListNode(tr_nd->val);
      res.push_back(lst_nd);
    }else{
      lst_nd->next = new ListNode(tr_nd->val);
      lst_nd=lst_nd->next;
    }
    if(tr_nd->left!=nullptr){
      q.push(tr_nd->left);
      ++next;
    }
    if(tr_nd->right!=nullptr){
      q.push(tr_nd->right);
      ++next;
    }
    if(--cur==0){
      swap(cur, next);
      lst_nd=nullptr;
    }
  }
  return res;
}

void testCase(vector<int> v){
  int i=0;
  TreeNode *root=build(v, i);
  cout<<"original tree:"<<endl;
  displayTree(root);  cout<<endl;
  vector<ListNode*> res=Tree2List(root);
  cout<<"level by leve list:"<<endl;
  for(auto head:res){
    displayList(head);
    cout<<endl;
  }
  removeTree(root);
  for(auto head:res)
    removeList(head);
}

int main(){
  testCase({1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1});
}




