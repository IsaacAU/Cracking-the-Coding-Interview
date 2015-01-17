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

ListNode *findNth(ListNode *head, int n){
  if(!head) return nullptr;
  int i=n;
  ListNode *nd=head;
  while(--i){
    assert(nd!=nullptr);
    nd=nd->next;
  }
  while(nd->next){
    head=head->next;
    nd=nd->next;
  }
  return head;
}

void testCase(vector<int> v, int n){
  ListNode *head=build(v);
  cout<<"n="<<n<<endl;
  cout<<"list:";
  display(head);
  ListNode *nd=findNth(head, n);
  display(nd);
  clear(head);
}

int main(){
  testCase({1,2,3,4}, 1);
  testCase({}, 0);
  testCase({1}, 1);
  testCase({1,2,3,4,5}, 3);
}
