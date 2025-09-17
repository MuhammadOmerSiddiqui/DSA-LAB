#include<iostream>
using namespace std ;
struct Node
{
    int value ;
    Node* next ;
    Node* prev ;
    Node(int value)
    {
        this->value = value ;
        next = nullptr ;
        prev = nullptr ;
    }
    Node(int value , Node* next , Node* prev)
    {
        this->value = value ;
        this->next = next ;
        this->prev = prev ;
    }
} ;
Node* insert_element(Node*head , int value)
{
    if(head==nullptr) return new Node(value) ;
    if(head->next==nullptr)
    {
        Node* temp = new Node(value,nullptr,head) ;
        head->next = temp ;
        return head ;
    } 
    Node* temp = head ;
    while(temp->next!=nullptr)
    {
        temp = temp->next ;
    }
    Node* newNode = new Node(value,nullptr,temp) ;
    temp->next = newNode ;
    return head ;
}
Node* concatenate_strings(Node* L , Node* M)
{
    Node* temp = L ;
    while(temp->next!=nullptr)
    {
        temp = temp->next ;
    }
    temp->next = M ;
    M->prev = temp ;
    return L ;
}
void display(Node* head)
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
    int n1 , n2 ;
    cout<<"Enter how many elements are there in first linked list:" ; cin>>n1 ;
    cout<<"Enter how many elements are there in second linked list:" ; cin>>n2 ;
    Node* L = nullptr ; 
    Node* M = nullptr ;
    int value ;
    for(int i=0 ; i<n1 ; i++)
    {
        cout<<"Enter the "<<i+1<<" value:" ; cin>>value ;
        L = insert_element(L,value) ;
    }
    for(int i=0 ; i<n2 ; i++)
    {
        cout<<"Enter the "<<i+1<<" value:" ; cin>>value ;
        M = insert_element(M,value) ;
    }
    display(L) ;
    display(M) ;
    L = concatenate_strings(L,M) ;
    display(L) ;
    return 0 ;
}