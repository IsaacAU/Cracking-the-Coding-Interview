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

ListNode *cycle(ListNode *head){
  if(!head || !head->next)  return nullptr;
  ListNode *slow=head->next, *fast=head->next->next;
  while(!fast && slow!=fast){
    slow=slow->next;
    if(!fast->next) return nullptr;
    fast=fast->next->next;
  }
  if(!fast) return nullptr;
  fast=head;
  while(slow!=fast){
    slow=slow->next;
    fast=fast->next;
  }
  return fast;
}

void testCase(vector<int> v, int n){
  ListNode *head=build(v), *nd, *end=head;
  while(end->next){
    if(--n==0)  nd=end;
    end=end->next;
  }
  if(n) nd=end;
  display(head);
  end->next=nd;
  ListNode *nd1=cycle(head);
  assert(nd==nd1);
  end->next=nullptr;
  clear(head);
  cout<<"pass!"<<endl;
}

int main(){
  testCase({1,2,3}, 3);
  testCase({1,3,4,5,6}, 3);
  testCase({1}, 1);
}
