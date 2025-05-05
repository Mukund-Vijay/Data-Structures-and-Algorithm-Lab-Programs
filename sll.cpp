//To implement singly linked list using classes

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
        }*head,*tail;

    public:
        SLL()
        {head=NULL;tail=NULL;}
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
        void display_rev();
        void revlink();
};

int main()
{
    SLL obj;
    int data,pos,choice,del,output;
    cout<<"\n<=======Menu=======>\n";
    cout<<"\n1.Insert at the Beginning\n2.Insert at the End\n3.Insert at the given Index\n4.Delete at the Beginning\n5.Delete at the End\n6.Delete at the given Index\n7.Search for an Element\n8.Display the Linked List\n9.Displau Reverse\n10.Reverse the Link\n11.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice<1 || choice>11)
    {
        cout<<"Invalid Choice!\n";
        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert at the Beginning\n2.Insert at the End\n3.Insert at the given Index\n4.Delete at the Beginning\n5.Delete at the End\n6.Delete at the given Index\n7.Search for an Element\n8.Display the Linked List\n9.Display Reverse\n10.Reverse the Link\n11.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }

    while(choice!=11)
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

                else if(output == -1)
                {
                    cout<<"Error!The List is Empty\n";
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
                obj.display_rev();
                break;

            case 10:
                obj.revlink();
                break;

            case 11:
                cout<<"Exit!!\n";
                break;

            default:
                cout<<"Invalid Choice!\n";
        }

        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert at the Beginning\n2.Insert at the End\n3.Insert at the given Index\n4.Delete at the Beginning\n5.Delete at the End\n6.Delete at the given Index\n7.Search for an Element\n8.Display the Linked List\n9.Display Reverse\n10.Reverse the Link\n11.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;

        while(choice<1 || choice>11)
        {
            cout<<"Invalid Choice!\n";
            cout<<"<=======Menu=======>\n";
            cout<<"1.Insert at the Beginning\n2.Insert at the End\n3.Insert at the given Index\n4.Delete at the Beginning\n5.Delete at the End\n6.Delete at the given Index\n7.Search for an Element\n8.Display the Linked List\n9.Exit\n";
            cout<<"Enter your choice : ";
            cin>>choice;
        }
    }
    return 0;
}

void SLL::insertbeg(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(node));
    newnode->data=data;
    if(head==NULL)
    {
        tail=newnode;
    }
    else
    {
        tail=head;
    }
    newnode->next=head;
    head=newnode;
}

void SLL::insertend(int data)
{
    if(head==NULL)
    {
        insertbeg(data);
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

void SLL::insertpos(int data,int pos)
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
        while(temp->next!=NULL)
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
            struct node*newnode=(struct node*)malloc(sizeof(node));    
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

int SLL::delbeg()
{
    if(head==NULL)
    {
        return 0;
    }

    else
    {
        int delnode=head->data;
        head=head->next;
        return delnode;
    }
}

int SLL::delend()
{
    if(head==NULL)
    {
        return 0;
    }

    else
    {
        struct node*temp=head;
        int delnode=tail->data;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        return delnode;
    }
}

int SLL::delpos(int pos)
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
        while(temp->next!=NULL)
        {
            len++;
            temp=temp->next;
        }
        cout<<len<<endl;
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
            return delnode;
        }
    }
}

int SLL::search(int data)
{
    if(head==NULL)
    {
        return -1;
    }

    else
    {
        int count=0;
        struct node*temp=head;
        while(temp->next!=NULL)
        {
            if(data==temp->data)
            {
                count++;
            }
            temp=temp->next;
        }
    return count;
    }
}

void SLL::display()
{
    if(head==NULL)
    {
        cout<<"The List is Empty.\n";
    }

    else
    {
        struct node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}

void SLL::display_rev()
{
    if(head==NULL)
    {
        cout<<"The List is Empty.\n";
    }

    else
    {
        int len;
        len=1;
        struct node*temp=head;
        while(temp->next!=NULL)
        {
            len++;
            temp=temp->next;
        }
        temp=head;
        int arr[len];
        for(int i=0;i<len;i++)
        {
            arr[i]=temp->data;
            temp=temp->next;
        }
        for(int i=len-1;i>=0;i-=1)
        {
            cout<<arr[i]<<"->";
        }
        cout<<"NULL\n";
    }
}

void SLL::revlink()
{
    struct node*prevnode=NULL;
    struct node*currentnode=head;
    struct node*nextnode=head;
    while(currentnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}