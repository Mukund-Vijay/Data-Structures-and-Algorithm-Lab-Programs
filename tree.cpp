/*
    To implement Tree ADT using Linked List data structure with the follwing memeber functions
                                1.Insert
                                2.Preorder
                                3.Inorder
                                4.Postorder
                                5.Search
*/

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

class Tree
{
    private:
        struct node
        {
            int data;
            struct node*left;
            struct node*right;
        };
        struct node*root;
    public:
        Tree()
        {root=nullptr;}
        node* getroot();
        void insert(int);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        bool search(int);
};


int main()
{
    Tree obj;
    int choice,data;
    bool out;
    cout<<"\n<=======Menu=======>\n";
    cout<<"1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=6)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter the data : ";
                cin>>data;
                obj.insert(data);
                break;
            
            case 2:
                obj.preorder(obj.getroot());
                break;
            
            case 3:
                obj.inorder(obj.getroot());
                break;

            case 4:
                obj.postorder(obj.getroot());
                break;

            case 5:
                cout<<"Enter the data to search : ";
                cin>>data;
                out=obj.search(data);

                if(out)
                {
                    cout<<data<<" is found in the tree.\n";
                }
                else
                {
                    cout<<data<<" is not found in the tree.\n";
                }
                break;

            default:
                cout<<"Invalid Choice!\n";
        }

        cout<<"\n<=======Menu=======>\n";
        cout<<"1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
}

Tree::node *Tree::getroot()
{
    return root;
}

void Tree::insert(int data)
{   
    struct node*newnode=(struct node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;

    if(root==nullptr)
    {
        root=newnode;
    }

    else
    {   
        struct node*temp=root;
        while(true)
        {
            char direction;
            cout<<"Left or Right(L/R) of "<<temp->data<<"? : ";
            cin>>direction;
        
            while(tolower(direction)!='l' && tolower(direction)!='r')
            {
                cout<<"Invalid Direction!\n";
                cout<<"Left or Right(L/R) of "<<temp->data<<"? : ";
                cin>>direction;
            }
            
            if(tolower(direction)=='l')
            {
                if(temp->left)
                {
                    temp=temp->left;
                }
                else
                {
                    temp->left=newnode;
                    break;
                }
            }
            
            else
            {
                if(temp->right)
                {
                    temp=temp->right;
                }
                else
                {
                    temp->right=newnode;
                    break;
                }
            }
        }
    }   
}

bool Tree::search(int num)
{
    if(root==nullptr)
    {
        return false;
    }
    queue <node*> que;
    que.push(root);

    while(!que.empty())
    {
        node*temp=que.front();
        que.pop();

        if(temp->data==num)
        {
            return true;
        }
        
        if(temp->left)
        {
            que.push(temp->left);
        }

        if(temp->right)
        {
            que.push(temp->right);
        }
    }
    return false;
}

void Tree::preorder(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void Tree::inorder(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void Tree::postorder(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}