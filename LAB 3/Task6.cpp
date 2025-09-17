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
    if(head==nullptr) return new Node(value) ;
    Node* temp = head ;
    while(temp->next!=nullptr)
    {
        temp = temp->next ;
    }
    Node* newNode = new Node(value) ;
    temp->next = newNode ;
    return head ;
}
Node* delete_a_value(Node* head , int value)
{
    if(head==nullptr) return nullptr ;
    if(head->value==value)
    {
        Node* temp = head ;
        head = head->next ;
        delete temp ;
        cout<<"Element deleted"<<endl ;
        return head ;
    }
    Node* temp = head ;
    Node* prev = nullptr ;
    while(temp!=nullptr)
    {
        if(temp->value==value)
        {
            prev->next = temp->next ;
            temp->next = nullptr ;
            delete temp ;
            cout<<"Element deleted"<<endl ;
            break ;
        }
        else if(temp->next==nullptr)
        {
            cout<<"Element not present in the list"<<endl ;
        }
        prev = temp ;
        temp = temp->next ;
    }
    return head ;
}
void display_linked_list(Node* head)
{
    Node* temp = head ;
    while(temp!=nullptr)
    {
        cout<<temp->value<<" " ;
        temp = temp->next ;
    }
    cout<<endl ;
}
int main()
{
    int n ; cout<<"Enter how many elements are there in the linked list:" ; cin>>n ;
    Node* head = nullptr ;
    int value , delete_value ;
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the "<<i+1<<" value:" ; cin>>value ;
        head = add_a_element(head,value) ;
    }
    display_linked_list(head) ;
    cout<<"Enter the value which you want to delete:" ;
    cin>>delete_value ;
    head = delete_a_value(head,delete_value) ;
    display_linked_list(head) ;
    return 0 ;
}