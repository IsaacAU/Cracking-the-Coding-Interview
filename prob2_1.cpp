#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int key;
    node *next;
    node(int i): key(i), next(0){}
};

node* build(int arr[], int n){
    if(n==0)
        return 0;
    node *head = new node(arr[0]);
    node *nd = head;
    for(int i = 1; i != n; ++i){
        nd->next = new node(arr[i]);
        nd = nd->next;
    }
    return head;
}

void display(node *head){
    cout<<head->key;
    head = head->next;
    while(head){
        cout<<"->"<<head->key;
        head = head->next;
    }
    cout<<endl;
}

void destroy_node(node *&nd){
    if(nd->next)
        destroy_node(nd->next);
    else
        delete nd;
}

void destroy(node *head){
    destroy_node(head);
}

void remove_duplicate(node *head){
    node *nd = head->next;
    node *pre = head;
    while(nd){
        node *start = head;
        for(; start!=nd && start->key != nd->key; start=start->next);
        if(start!=nd){
            pre->next = nd->next;
            delete nd;
            nd = pre->next;
        }else{
            pre = nd;
            nd = nd->next;
        }
    }
}

void remove_duplicate2(node *head){
    vector<int> store;
    store.push_back(head->key);
    node *prev = head;
    head = head->next;
    while(head){
        if(find(store.begin(), store.end(), head->key)!=store.end()){
            prev->next = head->next;
            delete head;
            head = prev->next;
        }else{
            store.push_back(head->key);
            prev = head;
            head = head->next;
        }
    }
}

int main()
{
    int arr[] = {1,3,3,5,3,2,3,4};
    node *head = build(arr,sizeof(arr)/sizeof(*arr));
    cout<<"Before remove:\t"; display(head);
    remove_duplicate2(head);
    cout<<"After remove:\t"; display(head);
    destroy(head);  cout<<"List destroyed!"<<endl;
    return 0;
}
