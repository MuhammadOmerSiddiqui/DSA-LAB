#include<iostream>
using namespace std ;
struct Node
{
    int value ;
    Node* next ;
    Node(int value)
    {
        this->value = value ;
        next = nullptr ;
    }
    Node(int value , Node* next)
    {
        this->value = value ;
        this->next = next ;
    }
} ;
Node* add_a_element(Node* head , int value)
{
    if(head==nullptr)
    {
        head = new Node(value) ;
        head->next = head ;
        return head ;
    }
    Node* temp = head ;
    while(temp->next!=head)
    {
        temp = temp->next ;
    }
    Node* newNode = new Node(value,head) ;
    temp->next = newNode ;
    return head ;
}
Node* insert_at_head(Node* head , int value)
{
    if(head==nullptr)
    {
        head = new Node(value) ;
        head->next = head ;
        return head ;
    }
    Node* temp = head ;
    while(temp->next!=head)
    {
        temp = temp->next ;
    }
    Node* newNode = new Node(value,head) ;
    temp->next = newNode ;
    head = newNode ;
    return head ;
}
void display_linked_list(Node* head)
{
    if(head==nullptr) return ;
    Node* temp = head ;
    do
    {
        cout<<temp->value<<" " ;
        temp = temp->next ;
    }while(temp!=head) ;
    cout<<endl ;
}
Node* insert_at_given_position(Node* head , int position , int value)
{
    if(head==nullptr) return nullptr ;
    if(position==1)
    {
        Node* temp = head ;
        while(temp->next!=head)
        {
            temp = temp->next ;
        }
        Node* newNode = new Node(value,head) ;
        temp->next = newNode ;
        head = newNode ;
        return head ;
    }
    Node* temp = head ;
    int count = 0 ;
    while(temp!=nullptr)
    {
        count++ ;
        if(count==position-1)
        {
            break ;
        }
        temp = temp->next ;
    }
    Node* newNode = new Node(value,temp->next) ;
    temp->next = newNode ;
    return head ;
}
Node* delete_node(Node* head , int value)
{
    if(head==nullptr) return nullptr ;
    if(head->value==value)
    {
        Node* temp = head ;
        while(temp->next!=head)
        {
            temp = temp->next ;
        }
        Node* temp2 = head ;
        temp->next = head->next ;
        head = head->next ;
        temp2->next = nullptr ;
        delete temp2 ;
        return head ;
    }
    Node* temp = head ;
    while(temp!=nullptr)
    {
        if(temp->next->value==value)
        {
            break ;
        }
        temp = temp->next ;
    }
    Node* temp2 = temp->next ;
    temp->next = temp->next->next ;
    temp2->next = nullptr ;
    delete temp2 ;
    return head ;
}
int main()
{
    int n ; cout<<"Enter how many elements are there in the list:" ; cin>>n ;
    Node* head = nullptr ;
    int value ;
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the "<<i+1<<" value:" ; cin>>value ;
        head = add_a_element(head,value) ;
    }
    display_linked_list(head) ;
    head = insert_at_head(head,12) ;
    display_linked_list(head) ;
    head = insert_at_given_position(head,3,31) ;
    display_linked_list(head) ;
    head = delete_node(head,2) ;
    display_linked_list(head) ;
    return 0 ;
}