#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};

class link
{
    Node* head;
public:
   link()
   {
       head= nullptr;
   }
   void insertatbeg(int val)
   {
       Node* newnode=new Node(val);
       newnode->next=head;
       head=newnode;
   }

   void insertatlast(int val)
   {
       Node* newnode = new Node(val);
       if(head==nullptr)
       {
           head=newnode;
       }
       Node* temp = head;
       while(temp->next!=nullptr)
       {
           temp=temp->next;
       }
       temp->next=newnode;
   }

    void deletenode(int val)
    {
        if(head==nullptr)
        {
            cout<<"Empty";
        }
        if(head->data==val)
        {
            Node* temp = head;
            head=head->next;
            delete temp;
        }
        Node* temp = head;
        while(temp->next!=nullptr&&temp->next->data!=val)
        {
            temp=temp->next;
        }
        if(temp->next==nullptr)
        {
            cout<<"Not Found";
        }
        Node* del = temp->next;
        temp->next=temp->next->next;
        delete del;
    }

    void display()
    {
        Node* temp= head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<"   ";
            temp=temp->next;
        }
    }
};
int main()
{
    link l;
    int n,i,t;
    cout<<"Enter no. of Elements : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        l.insertatbeg(t);
    }
    int d,m;
    cout<<"Element to insert at last : ";
    cin>>m;
    l.insertatlast(m);
    l.display();
    cout<<endl;
    cout<<"Element to delete : ";
    cin>>d;
    l.deletenode(20);
    cout<<"After deletion : ";
    l.display();
}
