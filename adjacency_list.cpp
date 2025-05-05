/*
                            To implement graph ADT using adjacency list with the following operations
                                                1.Insert 
                                                2.Delete
                                                3.Search
                                                4.Display
                                                5.Delete
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#define MAX 20
using namespace std;

class ADJ_LIST
{
    private:
        struct node
        {
            int data;
            struct node*next;
        };
        int edges;
        vector <node*> adj_list[MAX];
    public:
        int setedges();
        void resize(int);
        void initialize();
        bool bound_check(int);
        bool insert_edges(int,int);
        int delete_edges(int,int);
        int search_edges(int,int);
        void display();
};

int main()
{
    ADJ_LIST obj;
    int choice,edge1,edge2,num_edges;
    bool out;
    int out1;
    num_edges=obj.setedges();
    obj.resize(num_edges);
    obj.initialize();

    do
    {
        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert Edges\n2.Delete Edges\n3.Search Edges\n4.Display List\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter the first edge : ";
                cin>>edge1;
                cout<<"\nEnter the second edge : ";
                cin>>edge2;
                out=obj.insert_edges(edge1,edge2);

                if(out)
                {
                    cout<<"The edge ("<<edge1<<","<<edge2<<") has been inserted successfully!\n";
                }
                else
                {
                    cout<<"The edge ("<<edge1<<","<<edge2<<") is out of range!\n";
                }
                break;
            case 2:
                cout<<"\nEnter the first edge : ";
                cin>>edge1;
                cout<<"\nEnter the second edge : ";
                cin>>edge2;
                out1=obj.delete_edges(edge1,edge2);
                if(out1==-1)
                {
                    cout<<"The edge ("<<edge1<<","<<edge2<<") is out of range!\n";
                }
                else if(out1==0)
                {
                    cout<<"There is no link between ("<<edge1<<","<<edge2<<")\n";
                }
                else
                {
                    cout<<"The edge ("<<edge1<<","<<edge2<<") has been deleted successfully!\n";
                }
                break;
            
            case 3:
                cout<<"\nEnter the first edge : ";
                cin>>edge1;
                cout<<"\nEnter the second edge : ";
                cin>>edge2;
                out1=obj.search_edges(edge1,edge2);
                if(out1==-1)
                {
                    cout<<"The edge ("<<edge1<<","<<edge2<<") is out of range!\n";
                }
                else if(out1==0)
                {
                    cout<<"There is no link between ("<<edge1<<","<<edge2<<")\n";
                }
                else
                {
                    cout<<"The edge ("<<edge1<<","<<edge2<<") has been found!\n";
                }
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout<<"\nExiting...\n";
                break;
            default:
                cout<<"\nInvalid Choice!\n";
        }
    }while(choice!=5);

    return 0;
}

int ADJ_LIST::setedges()
{
    cout<<"\nEnter the number of edges : ";
    cin>>edges;
    return edges;
}

void ADJ_LIST::resize(int num_edges)
{
    adj_list->resize(num_edges);
}

void ADJ_LIST::initialize()
{
    for(int i=0;i<edges;i++)
    {
        struct node*newnode=(struct node*)malloc(sizeof(node));
        newnode->next=nullptr;
        newnode->data=i+1;
        adj_list->at(i)=newnode;
    }
}

bool ADJ_LIST::bound_check(int edge)
{
    return edge>edges;
}

bool ADJ_LIST::insert_edges(int edge1,int edge2)
{
    bool out1=bound_check(edge1);
    bool out2=bound_check(edge2);
    if(out1&&out2)
    {
        return false;
    }
    struct node*newnode=(struct node*)malloc(sizeof(node));
    newnode->data=edge2;
    newnode->next=nullptr;
    struct node*temp=adj_list->at(edge1-1);
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return true;
}

int ADJ_LIST::delete_edges(int edge1,int edge2)
{
    bool out1=bound_check(edge1);
    bool out2=bound_check(edge2);
    if(out1&&out2)
    {
        return -1;
    }
    struct node*temp=adj_list->at(edge1-1);
    while(temp->next!=nullptr)
    {
        if(temp->next->data==edge2)
        {
            temp->next=temp->next->next;
            return 1;
        }
        else
        {
            temp=temp->next;
        }
    }
    return 0;
}

int ADJ_LIST::search_edges(int edge1,int edge2)
{
    bool out1=bound_check(edge1);
    bool out2=bound_check(edge2);
    if(out1&&out2)
    {
        return -1;
    }
    struct node*temp=adj_list->at(edge1-1);
    while(temp->next!=nullptr)
    {
        temp=temp->next;
        if(temp->data==edge2)
        {
            return 1;
        }
    }
    return 0;
}


void ADJ_LIST::display()
{
    cout<<endl;
    for(int i=0;i<edges;i++)
    {
        cout<<adj_list->at(i)->data<<" : ";
        struct node*temp=adj_list->at(i);
        while(temp->next!=nullptr)
        {
            temp=temp->next;
            cout<<temp->data<<"->";
        }
        cout<<"NULL";
        cout<<endl;
    }
}