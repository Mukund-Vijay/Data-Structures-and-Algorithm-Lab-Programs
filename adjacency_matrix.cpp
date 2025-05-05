/*
                            To implement graph ADT using adjacency matrix with the following operations
                                            1.Insert 
                                            2.Delete
                                            3.Search
                                            4.Display
                                            5.Exit
*/

#include <iostream>
#define MAX 20
using namespace std;

class ADJ_MAT
{
    private:
        int edges;
        int adj_mat[MAX][MAX];
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
    ADJ_MAT obj;
    int choice,edge1,edge2,num_edges;
    bool out;
    int out1;
    num_edges=obj.setedges();
    obj.resize(num_edges);
    obj.initialize();

    do
    {
        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert Edges\n2.Delete Edges\n3.Search Edges\n4.Display Matrix\n5.Exit\n";
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

int ADJ_MAT::setedges()
{
    cout<<"\nEnter the number of edges : ";
    cin>>edges;
    return edges;
}

void ADJ_MAT::resize(int num_edges)
{
    adj_mat[num_edges][num_edges];
}

void ADJ_MAT::initialize()
{
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<edges;j++)
        {
            adj_mat[i][j]=0;
        }
    }
}

bool ADJ_MAT::bound_check(int edge)
{
    return edge>edges;
}

bool ADJ_MAT::insert_edges(int edge1,int edge2)
{
    int temp;
    bool out1=bound_check(edge1);
    bool out2=bound_check(edge2);
    if(out1&&out2)
    {
        return false;
    }
    adj_mat[edge1-1][edge2-1]=1;
    return true;
}

int ADJ_MAT::delete_edges(int edge1,int edge2)
{
    bool out1=bound_check(edge1);
    bool out2=bound_check(edge2);
    if(out1&&out2)
    {
        return -1;
    }
    else if(adj_mat[edge1-1][edge2-1]==0)
    {
        return 0;
    }
    adj_mat[edge1-1][edge2-1]=0;
    return 1;
}

int ADJ_MAT::search_edges(int edge1,int edge2)
{
    bool out1=bound_check(edge1);
    bool out2=bound_check(edge2);
    if(out1&&out2)
    {
        return -1;
    }
    else if(adj_mat[edge1-1][edge2-1]==0)
    {
        return 0;
    }
    return 1;
}

void ADJ_MAT::display()
{
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<edges;j++)
        {
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }
}