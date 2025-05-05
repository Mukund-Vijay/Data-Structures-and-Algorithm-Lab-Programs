//A Header file consisting of the member functions to be operated on linked lists
#include <iostream>
#include <stdlib.h>
using namespace std;

class SLL
{
    private:
        struct node
        {
            int data;
            struct node*next;
        };
        struct node*head;
        struct node*tail;
    
    public:
        SLL();
        struct node* gethead();
        void insert_asc(int);
        void merge(SLL&,SLL&);
        void display();
}obj1,obj2,obj3;

SLL::SLL()
{
    head=NULL;
    tail=NULL;
}

SLL::node* SLL::gethead()
{
    return head;
}

void SLL::insert_asc(int data)
{
    if(head == NULL)
    {
        struct node*newnode=(struct node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
        tail=newnode;
    }

    else if(head->next==NULL)
    {
        if(head->data>data)
        {
            struct node*newnode=(struct node*)malloc(sizeof(node));
            newnode->data=data;
            newnode->next=head;
            head=newnode;
        }

        else
        {
            struct node*newnode=(struct node*)malloc(sizeof(node));
            newnode->data=data;
            newnode->next=NULL;
            tail->next=newnode;   
            tail=newnode;
        }
    }

    else
    {
        if(head->data>data)
        {
            struct node*newnode=(struct node*)malloc(sizeof(node));
            newnode->data=data;
            newnode->next=head;
            head=newnode;
        }
        
        else if(tail->data<data)
        {
            struct node*newnode=(struct node*)malloc(sizeof(node));
            newnode->data=data;
            newnode->next=NULL;
            tail->next=newnode;   
            tail=newnode;
        }

        else
        {
            struct node*temp=head;
            while(temp->next->data<data)
            {        
                temp=temp->next;
            }
            struct node*newnode=(struct node*)malloc(sizeof(node));
            newnode->data=data;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    

}

void SLL::merge(SLL& obj1,SLL& obj2)
{
    struct node*temp1=obj1.head;
    struct node*temp2=obj2.head;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data>temp2->data)
        {
            obj3.insert_asc(temp2->data);
            temp2=temp2->next;
        }
        else
        {
            obj3.insert_asc(temp1->data);
            temp1=temp1->next;
        }
    }

    while(temp1!=NULL)
    {
        obj3.insert_asc(temp1->data);
        temp1=temp1->next;
    }

    while(temp2!=NULL)
    {
        obj3.insert_asc(temp2->data);
        temp2=temp2->next;
    }
}


void SLL::display()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}