#include <iostream>
#include <queue>
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
    cout<<"List destroyed!"<<endl;
}

node* find_n(node *head, int n){
    queue<node*> que;
    while(head){
        if(que.size()==n)
            que.pop();
        que.push(head);
        head = head->next;
    }
    return que.front();
}

node* find_n2(node *head, int n){
    node *nd1=head, *nd2=head;
    for(int i = 0; i != n; ++i)
        nd2 = nd2->next;
    while(nd2){
        nd1=nd1->next;
        nd2=nd2->next;
    }
    return nd1;
}

int main()
{
    int arr[] = {1,3,4,2,3,4,5};
    node *head = build(arr,sizeof(arr)/sizeof(*arr));
    cout<<"Whole list:\t";  display(head);
    int n = 4;
    node *nd = find_n2(head,n);
    cout<<"Last "<<n<<" elements:\t";  display(nd);
    destroy(head);
    return 0;
}
