#include<iostream>
#include<vector>
#include<functional>

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

ListNode *removeDuplicate(ListNode *head){
  if(!head || !head->next)  return head;
  ListNode *prev=head, *cur=head->next, *nd;
  while(cur){
    nd=head;
    while(nd!=cur){
      if(nd->val==cur->val)
        break;
      nd=nd->next;
    }
    if(nd==cur){
      prev=cur;
      cur=cur->next;
    }else{
      prev->next=cur->next;
      delete cur;
      cur=prev->next;
    }
  }
  return head;
}

void testCase(vector<int> v){
  ListNode *head=build(v);
  cout<<"Before remove:"<<endl;
  display(head);
  cout<<"After remove:"<<endl;
  head=removeDuplicate(head);
  display(head);
  clear(head);
}

int main(){
  testCase({});
  testCase({1});
  testCase({1,1,1});
  testCase({1,2,1});
}
