#include<iostream>
#include<stack>
using namespace std ;
template<class T>
struct Node
{
    T value ;
    Node* next ;
    Node(T value)
    {
        this->value = value ;
        this->next = nullptr ;
    }
    Node(T value , Node* next)
    {
        this->value = value ;
        this->next = next ;
    }
} ;
template<class T>
Node<T>* add_a_element(Node<T>* head , T value)
{
    if(head==nullptr) return new Node<T>(value) ;
    Node<T>* temp = head ;
    while(temp->next!=nullptr)
    {
        temp = temp->next ;
    }
    Node<T>* newNode = new Node<T>(value) ;
    temp->next = newNode ;
    return head ;
}
template<class T>
bool palindrome_check(Node<T>* head , int n)
{
    Node<T>* temp = head ;
    stack<T> st ;
    while(temp!=nullptr)
    {
        st.push(temp->value) ;
        temp = temp->next ;
    }
    Node<T>* head2 = nullptr ;
    for(int i=0 ; i<n ; i++)
    {
        head2 = add_a_element(head2,st.top()) ;
        st.pop() ;
    }
    Node<T>* temp2 = head ;
    int count = 0 ;
    while(temp2!=nullptr)
    {
        if(temp2->value==head2->value)
        {
            count++ ;
        }
        temp2 = temp2->next ;
        head2 = head2->next ;
    }
    if(count==n) return true ;
    else return false ;
}
template<class T>
void display_linked_list(Node<T>* head)
{
    Node<T>* temp = head ;
    while(temp!=nullptr)
    {
        cout<<temp->value<<" " ;
        temp = temp->next ;
    }
    cout<<endl ;
}
int main()
{
    int n , linked_list_type ;
    cout<<"Enter the number of elements in the linked list:" ;
    cin>>n ;
    cout<<"Is the linked list character type or int type?? Please enter 1 for character type and 2 for int type:" ;
    cin>>linked_list_type ;
    if(linked_list_type==1)
    {
        Node<char>* head = nullptr ;
        char value ;
        for(int i=0 ; i<n ; i++)
        {
            cout<<"Enter the "<<i+1<<" value:" ;
            cin>>value ;
            head = add_a_element(head,value) ;
        }
        display_linked_list(head) ;
        if(palindrome_check(head,n))
        {
            cout<<"Linked List is a palindrome"<<endl ;
        }
        else cout<<"Linked List is not a palindrome"<<endl ;
    }
    else
    {
        Node<int>* head = nullptr ;
        int value ;
        for(int i=0 ; i<n ; i++)
        {
            cout<<"Enter the "<<i+1<<" value:" ;
            cin>>value ;
            head = add_a_element(head,value) ;
        }
        display_linked_list(head) ;
        if(palindrome_check(head,n))
        {
            cout<<"Linked List is a palindrome"<<endl ;
        }
        else cout<<"Linked List is not a palindrome"<<endl ;
    }
    return 0 ;
}