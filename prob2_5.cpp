#include <iostream>

using namespace std;

struct node{
    int key;
    node *next;
    node(int i): key(i), next(0) {}
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
    node *nd1=head, *nd2=head;
    for(int i = 0; i != n; ++i) nd2 = nd2->next;
    while(nd2){
        nd1 = nd1->next;
        nd2 = nd2->next;
    }
    return nd1;
}

void connect(node *head, node *nd, int arr[], int n){
    while(head->next) head = head->next;
    for(int i = 0; i != n; ++i){
        head->next = new node(arr[i]);
        head = head->next;
    }
    head->next = nd;
}

node* loop_start(node *head){
    node *nd = head;
    int i = 0;
    nd = nd->next;
    while(nd){
        ++i;
        int j = 0;
        node *start = head;
        while(start!=nd){
            ++j;
            start = start->next;
        }
        if(i!=j){
            return nd;
        }
        nd = nd->next;
    }
    return 0;
}

void display2(node *head){
    cout<<head->key;
    node *nd = head;
    nd = nd->next;
    int i = 0;
    while(nd){
        ++i;
        node *start = head;
        int j = 0;
        while(start!=nd){
            ++j;
            start = start->next;
        }void destroy_node(node *&nd){
    if(nd->next)
        destroy_node(nd->next);
    else
        delete nd;
}
        if(i!=j){
            cout<<" loop back to "<<nd->key<<endl;
            return;
        }else{
            cout<<"->"<<nd->key;
            nd = nd->next;
        }
    }
}

// to do : break list and destroy!

int main()
{
    int arr[] = {3,5,5,2,4,6,3,4};
    node *head = build(arr, sizeof(arr)/sizeof(*arr));
    cout<<"Original list:\t";    display(head);
    int n = 5;
    node *nd = find_n(head, n);
    cout<<"Last "<<n<<" elements:\t";  display(nd);
    int arr2[] = {0,1,2,3};
    connect(head, nd, arr2, sizeof(arr2)/sizeof(*arr2));
    cout<<"Loop list:\t";   display2(head);
    node *nd2 = loop_start(head);
    cout<<"Break point:\t"<<nd2->key<<endl;
    return 0;
}
