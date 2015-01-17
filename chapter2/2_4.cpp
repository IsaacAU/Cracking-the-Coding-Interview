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

ListNode *add(ListNode *A, ListNode *B){
  ListNode dummy(-1), *nd=&dummy;
  int c=0;
  while(A!=nullptr || B!=nullptr || c){
    int x=0, y=0;
    if(A){
        x=A->val;
        A=A->next;
    }
    if(B){
        y=B->val;
        B=B->next;
    }
    nd->next=new ListNode((x+y+c)%10);
    nd=nd->next;
    c=(x+y+c)/10;
  }
  return dummy.next;
}

void testCase(vector<int> v1, vector<int> v2){
  ListNode *A=build(v1), *B=build(v2);
  cout<<"List A:\t";  display(A);
  cout<<"List B:\t";  display(B);
  ListNode *res=add(A, B);
  cout<<"result:\t";  display(res);
  clear(A);
  clear(B);
  clear(res);
}

int main(){
  testCase({}, {1,2,3});
  testCase({1,2,3}, {});
  testCase({1,7,9}, {2, 8});
  testCase({7,8,9}, {9,9,8});
}
