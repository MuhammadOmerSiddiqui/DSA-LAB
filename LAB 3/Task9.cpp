#include<iostream>
#include<vector>
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
Node* add_element(Node* head , int value)
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
Node* modify(Node* head)
{
    vector<int> array ;
    Node* temp = head->next ;
    while(temp!=nullptr)
    {
        array.emplace_back(temp->value) ;
        if(temp->next!=nullptr) temp = temp->next->next ;
        else break ;
    }
    Node* head2 = nullptr ;
    Node* temp2 = head ;
    while(temp2!=nullptr)
    {
        head2 = add_element(head2,temp2->value) ;
        if(temp2->next!=nullptr) temp2 = temp2->next->next ;
        else break ;
    }
    for(int i=array.size()-1 ; i>=0 ; i--)
    {
        head2 = add_element(head2,array[i]) ;
    }
    return head2 ;
}
int main()
{
    int n ;
    cout<<"Enter how many elements are there in linked list:" ; cin>>n ;
    Node* head = nullptr ;
    int value ;
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the "<<i+1<<" value:" ; cin>>value ;
        head = add_element(head,value) ;
    }
    display(head) ;
    head = modify(head) ;
    display(head) ;
    return 0 ;
}