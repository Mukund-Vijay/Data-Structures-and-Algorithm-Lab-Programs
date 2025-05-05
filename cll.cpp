//To implement ciruclar linked list using classes
#include <iostream>
#include <stdlib.h>
using namespace std;

class CLL
{
    private:
        struct node
        {
            int data;
            struct node*next;
        }*head,*tail;

    public:
        CLL()
        {head=NULL;tail=NULL;}
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
};

int main()
{
    CLL obj;
    int data,pos,choice,del,output;
    cout<<"\n<=======Menu=======>\n";
    cout<<"\n1.Insert at the Beginning\n2.Insert at the End\n3.Insert at the given Index\n4.Delete at the Beginning\n5.Delete at the End\n6.Delete at the given Index\n7.Search for an Element\n8.Display the Linked List\n9.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=9)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter the Data : ";
                cin>>data;
                obj.insertbeg(data);
                break;

            case 2:
                cout<<"Enter the Data : ";
                cin>>data;
                obj.insertend(data);
                break;

            case 3:
                cout<<"Enter the Data : ";
                cin>>data;
                cout<<"Enter the position : ";
                cin>>pos;
                obj.insertpos(data,pos);
                break;
            
            case 4:
                del=obj.delbeg();
                if(del==0)
                {
                    cout<<"Error!The List is Empty!\n";
                }
                else
                {
                    cout<<"The Deleted Node is : "<<del<<endl;
                }
                break;

            case 5:
                del=obj.delend();
                if(del==0)
                {
                    cout<<"Error!The List is Empty!\n";
                }
                else
                {
                    cout<<"The Deleted Node is : "<<del<<endl;
                }
                break;

            case 6:
                cout<<"Enter the position : ";
                cin>>pos;
                del=obj.delpos(pos);
                if(del==0)
                {
                    cout<<"Error!The List is Empty!\n";
                }
                else if(del == -1)
                {
                    cout<<"Error!Index is out of range!\n";
                }
                else
                {
                    cout<<"The Deleted Node is : "<<del<<endl;
                }
                break;

            case 7:
                cout<<"Enter a number to search : ";
                cin>>data;
                output=obj.search(data);
                if(output==0)
                {
                    cout<<"The Number "<<data<<" is not present in the list.\n";
                }
                else
                {
                    cout<<"The Number "<<data<<" is found "<<output<<" times in the list.\n";
                }
                break;
            
            case 8:
                obj.display();
                break;
            
            case 9:
                cout<<"Exit!\n";
                break;

            default:
                cout<<"Invalid Choice!\n";
        }

        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert at the Beginning\n2.Insert at the End\n3.Insert at the given Index\n4.Delete at the Beginning\n5.Delete at the End\n6.Delete at the given Index\n7.Search for an Element\n8.Display the Linked List\n9.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    return 0;
}

void CLL::insertbeg(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        tail=newnode;
    }
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    tail->next=head;
}

void CLL::insertend(int data)
{
    if(head==NULL)
    {
        insertbeg(data);
    }

    else
    {
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        tail->next=newnode;
        tail=newnode;
        newnode->next=head;
    }
}

void CLL::insertpos(int data,int pos)
{
    if(head==NULL)
    {
        insertbeg(data);
    }

    else
    {
        int len;
        len=1;
        struct node*temp=head;  
        while(temp!=tail)
        {
            len++;
            temp=temp->next;
        }
        if(pos==1)
        {
            insertbeg(data);
        }
        else if(pos==len)
        {
            insertend(data);
        }
        else if(pos>len || pos<1)
        {
            cout<<"Index Out of Range!\n";
        }
        else
        {
            struct node*newnode=(struct node*)malloc(sizeof(struct node));    
            temp=head;
            int i=1;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->data=data;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}

int CLL::delbeg()
{
    if(head==NULL)
    {
        return 0;
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
        return delnode;
    }
}

int CLL::delend()
{
    if(head==NULL)
    {
        return 0;
    }

    else
    {
        struct node*temp=head;
        int delnode=tail->data;
        if(head==tail)
        {
            head=NULL;
            tail=NULL;
        }
        else
        {
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            tail=temp;
            temp->next=head;
        }
        return delnode;
    }
}

int CLL::delpos(int pos)
{
    if(head==NULL)
    {
        return 0;
    }

    else
    {
        int len;
        len=1;
        struct node*temp=head;
        while(temp!=tail)
        {
            len++;
            temp=temp->next;
        }
        if(pos==1)
        {
            delbeg();
        }
        else if(pos==len)
        {
            delend();
        }
        else if(pos>len || pos<1)
        {
            return -1;
        }
        else
        {   
            temp=head;
            int i=1;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            int delnode=temp->next->data;
            temp->next=temp->next->next;
            return delnode
        }
    }
}

int CLL::search(int data)
{
    int count=0;
    struct node*temp=head;
    while(temp->next!=head)
    {
        if(data==temp->data)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;
}

void CLL::display()
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
        cout<<temp->data<<"->";
        temp=temp->next;
        cout<<temp->data;
        cout<<"\n";
    }
}