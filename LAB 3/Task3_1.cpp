#include<iostream>
using namespace std ;

struct Passenger
{
    string name ;
    Passenger* next ;
    Passenger(string name)
    {
        this->name = name ;
        next = nullptr ;
    }
} ;

struct Flight
{
    int flightId ;
    Passenger* passengers ;
    Flight* next ;
    Flight(int id)
    {
        flightId = id ;
        passengers = nullptr ;
        next = nullptr ;
    }
} ;

Flight* add_a_flight(Flight* head , int id)
{
    if(head==nullptr) return new Flight(id) ;
    Flight* temp = head ;
    while(temp->next!=nullptr)
    {
        temp = temp->next ;
    }
    Flight* newNode = new Flight(id) ;
    temp->next = newNode ;
    return head ;
}

Flight* find_flight(Flight* head , int id)
{
    Flight* temp = head ;
    while(temp!=nullptr)
    {
        if(temp->flightId==id) return temp ;
        temp = temp->next ;
    }
    return nullptr ;
}

Passenger* reserve_a_ticket(Passenger* head , string name)
{
    if(head==nullptr) return new Passenger(name) ;
    Passenger* temp = head ;
    while(temp->next!=nullptr)
    {
        temp = temp->next ;
    }
    Passenger* newNode = new Passenger(name) ;
    temp->next = newNode ;
    return head ;
}

Passenger* cancel_a_reservation(Passenger* head , string name)
{
    if(head==nullptr) return head ;
    if(head->name==name)
    {
        Passenger* temp = head ;
        head = head->next ;
        delete temp ;
        return head ;
    }
    Passenger* temp = head ;
    Passenger* prev = nullptr ;
    while(temp!=nullptr)
    {
        if(temp->name==name)
        {
            prev->next = prev->next->next ;
            delete temp ;
            break ;
        }
        prev = temp ;
        temp = temp->next ;
    }
    return head ;
}

bool check_for_a_reserved_ticket(Passenger* head , string name)
{
    Passenger* temp = head ;
    while(temp!=nullptr)
    {
        if(temp->name==name) return true ;
        temp = temp->next ;
    }
    return false ;
}

void display_passengers(Passenger* head)
{
    if(head==nullptr)
    {
        cout<<"No Passengers"<<endl ;
        return ;
    }
    Passenger* temp = head ;
    cout<<"The Passengers are: ";
    while(temp!=nullptr)
    {
        cout<<temp->name<<" ";
        temp = temp->next ;
    }
    cout<<endl ;
}

void display_flights(Flight* head)
{
    if(head==nullptr)
    {
        cout<<"No Flights available"<<endl ;
        return ;
    }
    cout<<"Available Flights: ";
    Flight* temp = head ;
    while(temp!=nullptr)
    {
        cout<<temp->flightId<<" ";
        temp = temp->next ;
    }
    cout<<endl ;
}

int main()
{
    Flight* flights = nullptr ;
    int choice = 0 ;
    do
    {
        cout<<"\nAirline Ticket Reservation System"<<endl ;
        cout<<"1. Add a Flight"<<endl ;
        cout<<"2. Reserve a ticket"<<endl ;
        cout<<"3. Cancel a Reservation"<<endl ;
        cout<<"4. Check Whether a ticket is Reserved for a Person"<<endl ;
        cout<<"5. Display Passengers of a Flight"<<endl ;
        cout<<"6. Display All Flights"<<endl ;
        cout<<"0. Exit"<<endl ;
        cout<<"Enter your choice: " ;
        cin>>choice ;
        
        int flightId ;
        string name ;
        Flight* flight = nullptr ;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter Flight ID: " ;
                cin>>flightId ;
                flights = add_a_flight(flights , flightId) ;
                break ;
            case 2:
                cout<<"Enter Flight ID: " ;
                cin>>flightId ;
                flight = find_flight(flights , flightId) ;
                if(flight==nullptr)
                {
                    cout<<"Flight not found!"<<endl ;
                    break ;
                }
                cout<<"Enter Passenger Name: " ;
                cin>>name ;
                flight->passengers = reserve_a_ticket(flight->passengers , name) ;
                break ;
            case 3:
                cout<<"Enter Flight ID: " ;
                cin>>flightId ;
                flight = find_flight(flights , flightId) ;
                if(flight==nullptr)
                {
                    cout<<"Flight not found!"<<endl ;
                    break ;
                }
                cout<<"Enter Passenger Name: " ;
                cin>>name ;
                flight->passengers = cancel_a_reservation(flight->passengers , name) ;
                break ;
            case 4:
                cout<<"Enter Flight ID: " ;
                cin>>flightId ;
                flight = find_flight(flights , flightId) ;
                if(flight==nullptr)
                {
                    cout<<"Flight not found!"<<endl ;
                    break ;
                }
                cout<<"Enter Passenger Name: " ;
                cin>>name ;
                if(check_for_a_reserved_ticket(flight->passengers , name))
                    cout<<"Ticket is reserved."<<endl ;
                else
                    cout<<"Ticket not reserved."<<endl ;
                break ;
            case 5:
                cout<<"Enter Flight ID: " ;
                cin>>flightId ;
                flight = find_flight(flights , flightId) ;
                if(flight==nullptr)
                {
                    cout<<"Flight not found!"<<endl ;
                    break ;
                }
                display_passengers(flight->passengers) ;
                break ;
            case 6:
                display_flights(flights) ;
                break ;
            case 0:
                cout<<"Exiting..."<<endl ;
                break ;
            default:
                cout<<"Invalid choice!"<<endl ;
        }
    }while(choice!=0) ;
    return 0 ;
}