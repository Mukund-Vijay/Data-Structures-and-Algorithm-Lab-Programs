//Header file consisting of member functions of the source code roundrobin.cpp
#include <iostream>
using namespace std;

class roundrobin
{
    private:
        struct node
        {
            int data;
            struct node*next;
        }*head,*tail;

    public:
        roundrobin()
        {head=NULL;tail=NULL;}
        void insertbeg(int);
        void insert_process(int);
        void execute(int);
        void display();
};

void roundrobin::insertbeg(int time)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        tail=newnode;
    }
    newnode->data=time;
    newnode->next=head;
    head=newnode;
    tail->next=head;
}

void roundrobin::insert_process(int time)
{
    if(head==NULL)
    {
        insertbeg(time);
    }

    else
    {
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=time;
        tail->next=newnode;
        tail=newnode;
        newnode->next=head;
    }
}

void roundrobin::execute(int cpu_time)
{
    if(head==NULL)
    {
        cout<<"Error!No Processes to execute.\n";
    }

    else
    {
        int delnode=head->data;

        if(head==tail)
        {
            head=NULL;
            tail=NULL;   
        }
        else
        {
            head=head->next;
            tail->next=head;
        }
        if(delnode>cpu_time)
        {
            cout<<"Your Alloted time is over!Please get to the end of the queue!\n";
            int rem_process=delnode-cpu_time;
            insert_process(rem_process);
        }
        else
        {
            cout<<"Your process has been executed successfully!\n";
        }
    }
}
void roundrobin::display()
{
    if(head==NULL)
    {
        cout<<"The List is Empty!\n";
    }
    else
    {
        struct node*temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
}