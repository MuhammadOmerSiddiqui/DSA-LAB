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
void print_array(int array[] , int size)
{
    for(int i=0 ; i<size ; i++)
    {
        cout<<array[i]<<" " ;
    }
    cout<<endl ;
}
Node* add_front(Node* head , int value)
{
    return new Node(value,head) ;
}
Node* array_to_linked_list(int array[] , int size)
{
    Node* head = new Node(array[0]) ;
    Node* temp = head ;
    for(int i=1 ; i<size ; i++)
    {
        temp->next = new Node(array[i]) ;
        temp = temp->next ;
    }
    return head ;
}
void print_linked_list(Node* head)
{
    Node* temp = head ;
    while(temp!=NULL)
    {
        cout<<temp->data<<" " ; 
        temp = temp->next ;
    }
    cout<<endl ;
}
Node* add_tail(Node* head , int value)
{
    Node* temp = head ;
    while(temp!=NULL)
    {
        if(temp->next->next==nullptr)
        {
            temp->next->next = new Node(value) ;
            break ;
        }
        temp = temp->next ;
    }
    return head ;
}
Node* insert_at_k_position(Node* head , int k , int value)
{
    if(head==NULL)
    {
        return nullptr ;
    }
    if(k==1)
    {
        return new Node(value,head) ;
    }
    Node* temp = head ;
    int count = 0 ;
    while(temp!=NULL)
    {
        count++ ;
        if(count==k-1) break ;
        temp = temp->next ;
    }
    // 4 3 1 2 5 8 9 
    Node* new_value = new Node(value,temp->next) ;
    temp->next = new_value ;
    return head ;
}
Node* delete_node(Node* head , int value)
{
    if(head==nullptr) return head ;
    if(head->data==value)
    {
        Node* temp = head ;
        head = head->next ;
        delete temp ;
        return head ;
    }
    Node* temp = head ;
    Node* previous = nullptr ;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            previous->next = temp->next ;
            delete temp ;
            break ;
        }
        previous = temp ;
        temp = temp->next ;
    }
    return head ;
}
int main()
{
    int array[] = {3,1,2,5,8} ;
    print_array(array,5) ;
    Node* head = array_to_linked_list(array,5) ;
    print_linked_list(head) ;
    add_tail(head,9) ;
    print_linked_list(head) ;
    head = insert_at_k_position(head,3,11) ;
    print_linked_list(head) ;
    head = add_front(head,4) ;
    print_linked_list(head) ;
    head = delete_node(head,1) ;
    head = delete_node(head,2) ;
    head = delete_node(head,5) ;
    print_linked_list(head) ;
    return 0 ;
}
