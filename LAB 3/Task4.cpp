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
Node* modify_linked_list(Node* head)
{
    vector<int> array_even ;
    vector<int> array_odd ;
    Node* temp = head ;
    while(temp!=nullptr)
    {
        if(temp->value%2==0)
        {
            array_even.emplace_back(temp->value) ;
        }
        else array_odd.emplace_back(temp->value) ;
        temp = temp->next ;
    }
    Node* head2 = nullptr ;
    for(int i=0 ; i<array_even.size() ; i++)
    {
        head2 = add_a_element(head2,array_even[i]) ;
    }
    for(int i=0 ; i<array_odd.size() ; i++)
    {
        head2 = add_a_element(head2,array_odd[i]) ;
    }
    return head2 ;
}
int main()
{
    Node* head = nullptr ;
    int n ;
    cout<<"Enter number of elements:" ;
    cin>>n ;
    for(int i=0 ; i<n ; i++)
    {
        int value = 0 ;
        cout<<"Enter the value to add:" ;
        cin>>value ;
        head = add_a_element(head,value) ;
    }
    display_linked_list(head) ;
    head = modify_linked_list(head) ;
    display_linked_list(head) ;
    return 0 ;
}