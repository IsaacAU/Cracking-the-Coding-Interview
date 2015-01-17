#include<iostream>
#include<vector>
#include<functional>
#include<cassert>

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(nullptr){}
};

void display(ListNode *head){
  while(head){
    cout<<head->val<<"->";
    head=head->next;
  }
  cout<<endl;
}

ListNode *build(vector<int> &v){
  if(v.empty()) return nullptr;
  ListNode *head=new ListNode(v[0]), *nd=head;
  int i=1;
  while(i<v.size()){
    nd->next=new ListNode(v[i]);
    nd=nd->next;
    ++i;
  }
  return head;
}

void clear(ListNode *head){
  while(head){
    ListNode *nd=head->next;
    delete head;
    head=nd;
  }
}

void remove(ListNode *&mid){
  if(!mid)  return;
  if(!mid->next){
    //delete mid;  //  not working !!!!!!
  }else{
    ListNode *nd=mid->next;
    mid->val=nd->val;
    mid->next=nd->next;
    delete nd;
  }
}

void testCase(vector<int> v, int n){
  ListNode *head=build(v), *nd=head;
  while(--n && nd)
    nd=nd->next;
  cout<<"Before removal:\t";
  display(head);
  cout<<nd->val<<" will be removed!"<<endl;
  remove(nd);
  cout<<"After removal:\t";
  display(head);
  clear(head);
}

int main(){
  testCase({1,2,3,4}, 2);
  testCase({1,2,3}, 1);
  testCase({1}, 1);
  testCase({1,2}, 2);
}
