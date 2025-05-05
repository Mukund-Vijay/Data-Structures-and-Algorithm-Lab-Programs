/*
            To implement hash adt with separate chaining with the following functions
                        1.Insert
                        2.Delete
                        3.Seacrh
                        4.Display
                        5.Exit
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#define MAX 100
using namespace std;

class Hash_Chaining
{
    private:
        struct node
        {
            int data;
            struct node*next;
            struct node*prev;
        };
        vector <node*> Hash_Table[MAX];
    public:
        int getsize();
        void initialize(int);
        bool isempty(int);
        int hash_function(int,int);
        void insert(int,int);
        int del(int,int);
        int search(int,int);
        void display(int);
};

int main()
{
    Hash_Chaining obj;
    int data,choice,out,size;
    size=obj.getsize();
    obj.initialize(size);
    cout<<"\n<=======MENU=======>\n";
    cout<<"\n1.Insert Data\n2.Delete Data\n3.Search Data\n4.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=4)
    {
        switch(choice)
        {
            case 1:
                cout<<"\nEnter the data to be inserted : ";
                cin>>data;
                obj.insert(data,size);
                break;

            case 2:
                cout<<"\nEnter the data to be deleted : ";
                cin>>data;
                out=obj.del(data,size);
                if(out==-1)
                {
                    cout<<"The Hash Table is Empty!\n";
                }
                else if(out==1)
                {
                    cout<<data<<" has been deleted from the hash table!\n";
                }
                else
                {
                    cout<<data<<" is not present in the hash table!\n";
                }
                break;

            case 3:
                cout<<"\nEnter the data to be searched : ";
                cin>>data;
                out=obj.search(data,size);
                if(out==-1)
                {
                    cout<<"The Hash Table is Empty!\n";
                }
                else if(out==0)
                {
                    cout<<data<<" is not present in the hash table!\n";
                }
                else
                {
                    cout<<data<<" is present in the hash table!\n";
                }
                break;
            
            default:
                cout<<"\nInvalid Choice!\n";
        }
        cout<<"\n<=======MENU=======>\n";
        cout<<"\n1.Insert Data\n2.Delete Data\n3.Search Data\n4.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    return 0;
}

int Hash_Chaining::getsize()
{
    int size;
    cout<<"\nEnter the size of the hash table : ";
    cin>>size;
    return size;
}

void Hash_Chaining::initialize(int size)
{
    Hash_Table->resize(size);
    for(int i=0;i<size;i++)
    {
        struct node*newnode=(struct node*)malloc(sizeof(node));
        newnode->data=-1;
        newnode->next=nullptr;
        newnode->prev=nullptr;
        Hash_Table->at(i)=newnode;
    }
}

bool Hash_Chaining::isempty(int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(Hash_Table->at(i)->data==-1)
        {
            count++;
        }
    }
    if(count==size)
    {
        return true;
    }
    return false;
}

int Hash_Chaining::hash_function(int data,int size)
{
    return data%size;
}

void Hash_Chaining::insert(int data,int size)
{
    int index=hash_function(data,size);
    if(Hash_Table->at(index)->data==-1)
    {
        Hash_Table->at(index)->data=data;
    }
    else
    {
        struct node*newnode=(struct node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=nullptr;
        struct node*temp=Hash_Table->at(index);
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

int Hash_Chaining::del(int data,int size)
{
    if(isempty(size))
    {
        return -1;
    }
    else
    {
        int index=hash_function(data,size);
        struct node*delnode=Hash_Table->at(index);
        struct node*temp=delnode;
        while(temp!=nullptr)
        {
            if(temp->data==data)
            {
                if(temp->prev==nullptr)
                {
                    temp->next->prev=nullptr;
                    Hash_Table->at(index)=temp->next;
                    return 1;
                }
                else if(temp->next==nullptr)
                {   
                    temp->prev->next=nullptr;
                    Hash_Table->at(index)=temp->prev;
                    return 1;
                }
                else
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    Hash_Table->at(index)=temp->prev;
                    return 1;
                }
            }
            temp=temp->next;
        }
        return 0;
    }
}

int Hash_Chaining::search(int key,int size)
{
    if(isempty(size))
    {
        return -1;
    }
    
    int index=hash_function(key,size);
    struct node* temp=Hash_Table->at(index);

    while(temp!=nullptr)
    {
        if(temp->data==key)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
