/*Implementing Queue ADT using Array Data Structure of size 5
                            1.Enqueue
                            2.Dequeue
                            3.Peek
                            4.Display
                            5.Exit
*/

#include <iostream>                             
#include <cstdlib>
using namespace std;

class Queue_SLL
{
    private:
    struct node
    {
        int data;
        struct node*next;
    }*head,*tail;
    public:
        Queue_SLL()
        {head=NULL;tail=NULL;}
        void enqueue(int);
        int dequeue();
        int peek();
        void display();
};

int main()
{
    Queue_SLL obj;
    int choice,data,output;
    cout<<"\n<========Menu=======>";
    cout<<"\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter a data to insert : ";
                cin>>data;
                obj.enqueue(data);
                break;

            case 2:
                output=obj.dequeue();

                if(output == -1)
                {
                    cout<<"Queue is empty!\n";
                }

                else
                {
                    cout<<output<<" has been kicked out of the queue.\n";
                }
                break;

            case 3:
                output=obj.peek();

                if(output == -1)
                {
                    cout<<"Queue is empty!\n";
                }
                else
                {
                    cout<<output<<" is the first in the queue.\n";
                }
                break;
            
            case 4:
                obj.display();
                break;

            default:
                cout<<"Invalid Choice!\n";
        }
        cout<<endl;
        cout<<"\n<========Menu=======>";
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
}

void Queue_SLL::enqueue(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(node));
    newnode->data=data;

    if(head==NULL)
    {
        head=newnode;
        tail=head;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
}

int Queue_SLL::dequeue()
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        int delnode=head->data;
        head=head->next;
        return delnode;
    }
}

int Queue_SLL::peek()
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        return head->data;
    }
}

void Queue_SLL::display()
{
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}
