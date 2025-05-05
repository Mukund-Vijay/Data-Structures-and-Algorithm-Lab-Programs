/*
            To implement hash adt with quadratic probing with the following functions
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

class Hash_Quadratic
{
    private:
        struct node
        {
            int data;
            int probe;
            bool isfilled;
        };
        vector <node*> Hash_Table[MAX];

    public:
        int getsize();
        void initialize(int);
        bool isfull();
        bool isempty();
        int hash_function(int,int);
        int insert(int,int);
        int del(int,int);
        int search(int,int);
        void display();
};

int main()
{
    Hash_Quadratic obj;
    int data,choice,out,size;
    size=obj.getsize();
    obj.initialize(size);
    cout<<"\n<=======MENU=======>\n";
    cout<<"\n1.Insert Data\n2.Delete Data\n3.Search Data\n4.Display Hash Table\n5.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                cout<<"\nEnter the data to be inserted : ";
                cin>>data;
                out=obj.insert(data,size);

                if(out==0)
                {
                    cout<<"The Hash Table is Full!\n";
                }
                else
                {
                    cout<<data<<" has been inserted successfully!\n";
                }
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
                else if(out==-2)
                {
                    cout<<data<<" is not present in the hash table!\n";
                }
                else
                {
                    cout<<data<<" is present at the index "<<out<<" in the hash table!\n";
                }
                break;

            case 4:
                obj.display();
                break;
            
            default:
                cout<<"\nInvalid Choice!\n";
        }
        cout<<"\n<=======MENU=======>\n";
        cout<<"\n1.Insert Data\n2.Delete Data\n3.Search Data\n4.Display Hash Table\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    return 0;
}

int Hash_Quadratic::getsize()
{
    int size;
    cout<<"\nEnter the size of the hash table : ";
    cin>>size;
    return size;
}

void Hash_Quadratic::initialize(int size)
{
    Hash_Table->resize(size);
    for(int i=0;i<size;i++)
    {
        struct node*newnode=(struct node*)malloc(sizeof(node));
        newnode->data=-1;
        newnode->probe=1;
        newnode->isfilled=false;
        Hash_Table->at(i)=newnode;
    }
}

bool Hash_Quadratic::isfull()
{
    int count=0;
    for(int i=0;i<Hash_Table->size();i++)
    {
        if(Hash_Table->at(i)->isfilled)
        {
            count++;
        }
    }
    
    if(count==Hash_Table->size())
    {
        return true;
    }
    return false;
}

bool Hash_Quadratic::isempty()
{
    int count=0;
    for(int i=0;i<Hash_Table->size();i++)
    {
        if(!Hash_Table->at(i)->isfilled)
        {
            count++;
        }
    }
    
    if(count==Hash_Table->size())
    {
        return true;
    }
    return false;
}

int Hash_Quadratic::hash_function(int data,int size)
{
    return data%size;
}

int Hash_Quadratic::insert(int data,int size)
{
    if(isfull())
    {
        return 0;
    }
    int index=hash_function(data,size);
    int index_copy=index;
    int probe=1;
    int i=1;
    while(true)
    {
        if(!Hash_Table->at(index_copy)->isfilled)
        {
            Hash_Table->at(index_copy)->data=data;
            Hash_Table->at(index_copy)->isfilled=true;
            Hash_Table->at(index_copy)->probe=probe;
            break;
        }
        index_copy=index+i*i+i;
        i++;
        index_copy=index_copy%size;
        probe++;
    }
    return 1;
}

int Hash_Quadratic::del(int data,int size)
{
    if(isempty())
    {
        return -1;
    }
    else
    {
        int index=hash_function(data,size);
        int end=0;
        int i=1;
        while(true)
        {
            if(Hash_Table->at(index)->data==data)
            {
                Hash_Table->at(index)->data=-1;
                Hash_Table->at(index)->isfilled=false;
                Hash_Table->at(index)->probe=1;
                return 1;
            }
            index+=i*i+i;
            index=index%size;
            end++;
            if(end==Hash_Table->size())
            {
                return 0;
            }
        }
    }
}

int Hash_Quadratic::search(int data,int size)
{
    if(isempty())
    {
        return -1;
    }
    else
    {
        int index=hash_function(data,size);
        int end=0;
        int i=1;
        while(true)
        {
            if(Hash_Table->at(index)->data==data)
            {
                return index;
            }
            index+=i*i;
            index=index%size;
            end++;
            if(end==Hash_Table->size())
            {
                return -2;
            }
        }
    }
}

void Hash_Quadratic::display()
{
    if(isempty())
    {
        cout<<"\nThe Hash Table is empty!\n";
    }
    else
    {
        for(int i=0;i<Hash_Table->size();i++)
        {
            cout<<"\n=======================\n"<<i<<". Data : "<<Hash_Table->at(i)->data<<"   Probe : "<<Hash_Table->at(i)->probe<<"\n=======================\n";
        }
    }
}