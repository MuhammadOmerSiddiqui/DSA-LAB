#include<iostream>
using namespace std ;
struct Node
{
    int data ;
    Node* next ;
    Node(int data)
    {
        this->data = data ;
        next = nullptr ;
    }
    Node(int data , Node* next)
    {
        this->data = data ;
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
    Node* new_value = new Node(value) ;
    temp->next = new_value ;
    return head ;
}
void print_linked_list(Node* head)
{
    Node* temp = head ;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" " ;
        temp = temp->next ;
    }
    cout<<endl ;
}
// Rotation value will be between 1 to length-1 of the linked list
Node* rotate_linked_list(Node* head , int rotation_value)
{
    for(int i=0 ; i<rotation_value ; i++)
    {
        Node* temp = head ;
        while(temp->next!=nullptr)
        {
            temp = temp->next ;
        }
        Node* temp2 = new Node(head->data) ;
        temp->next = temp2 ;
        head = head->next ;
    }
    return head ;
}
int main()
{
    Node* head = add_element(nullptr,5) ;
    head = add_element(head,3) ;
    head = add_element(head,1) ;
    head = add_element(head,8) ;
    head = add_element(head,6) ;
    head = add_element(head,4) ;
    head = add_element(head,2) ;
    print_linked_list(head) ;
    int no_of_elements_to_move ;
    cout<<"Enter how many elements do you want to move:" ;
    cin>>no_of_elements_to_move ;
    head = rotate_linked_list(head,no_of_elements_to_move) ;
    print_linked_list(head) ;
    return 0 ;
}