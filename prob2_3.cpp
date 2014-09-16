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
    for(int i = 0; i != n; ++i){
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
    for(int i = 0; i != n; ++i)  nd2 = nd2->next;
    while(nd2){
        nd1=nd1->next;
        nd2=nd2->next;
    }
    return nd1;
}

void remove_node(node *head, node *nd){
    if(head==nd){
        head->key = head->next->key;
        node *tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return;
    }
    node *prev = head;
    head = head->next;
    while(head){
        if(head==nd){
            prev->next = head->next;
            delete head;
            return;
        }else{
            prev = head;
            head = head->next;
        }
    }
}

int main()
{
    int arr[] = {3,3,4,5,3,2,5,7,4,5,6};
    node *head = build(arr,sizeof(arr)/sizeof(*arr));
    cout<<"Whole list:\t";    display(head);
    int n = 7;
    node *nd = find_n(head, n);
    cout<<"Last "<<n<<" elements:\t";  display(nd);
    remove_node(head, nd);
    cout<<"After delete:\t";   display(head);
    destroy(head);
    return 0;
}
