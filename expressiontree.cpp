/*
        To contruct an expression tree using a binary tree with the following operations
                                        1.Postfix Epression
                                        2.Expression Tree Construction
                                        3.Preorder 
                                        4.Inorder
                                        5.Postorder
                                        6.Exit
*/

#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

class ExpressionTree
{
    private:
        struct node
        {
            char data;
            struct node*left;
            struct node*right;
        };
        struct node*root;

    public:
        ExpressionTree()
        {root=nullptr;}
        node* getroot();
        string getpostfix();
        void construct(string);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
};

int main()
{
    ExpressionTree obj;
    int choice;
    string exp;
    cout<<"\n<=======Menu=======>\n";
    cout<<"1.Construct Expression Tree\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                obj.construct(obj.getpostfix());
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


            default:
                cout<<"Invalid Choice!\n";
        }
        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Construct Expression Tree\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
}

ExpressionTree::node *ExpressionTree::getroot()
{
    return root;
}

string ExpressionTree::getpostfix()
{
    string exp;
    cout<<"Enter your postfix expression : ";
    cin>>exp;
    return exp;
}

void ExpressionTree::construct(string exp)
{
    stack <node*> st;
    for(int i=0;exp[i]!='\0';i++)
    {
        struct node* newnode=(struct node*)malloc(sizeof(node));
        newnode->data=exp[i];
        newnode->left=nullptr;
        newnode->right=nullptr;

        if(isalnum(exp[i]))
        {
            st.push(newnode);
        }
        else
        {
            newnode->right=st.top();
            st.pop();
            newnode->left=st.top();
            st.pop();
            st.push(newnode);
        }
    }
    root=st.top();
    st.pop();
}

void ExpressionTree::preorder(node*root)
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

void ExpressionTree::inorder(node*root)
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

void ExpressionTree::postorder(node*root)
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