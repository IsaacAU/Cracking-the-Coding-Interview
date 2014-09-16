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

node* add(node *head1, node *head2){
    int num = head1->key + head2->key;
    int c = num>9?1:0;
    num = num % 10;
    node *head = new node(num);
    node *nd = head;
    head1 = head1->next;   head2 = head2->next;
    while(head1 && head2){
        num = head1->key + head2->key + c;
        c = num>9?1:0;
        num = num % 10;
        nd->next = new node(num);  nd = nd->next;
        head1 = head1->next;    head2 = head2->next;
    }
    return head;
}

int main()
{
    int arr1[] = {3,4,5,2,3,4,5,2,4,2};
    node *head1 = build(arr1, sizeof(arr1)/sizeof(*arr1));
    cout<<"First list:\t";  display(head1);
    int arr2[] = {3,5,2,4,1,3,4,5,6,6};
    node *head2 = build(arr2, sizeof(arr2)/sizeof(*arr2));
    cout<<"Second list:\t"; display(head2);
    node *head = add(head1, head2);
    cout<<"Sum list:\t";   display(head);
    destroy(head1);
    destroy(head2);
    destroy(head);
    return 0;
}
