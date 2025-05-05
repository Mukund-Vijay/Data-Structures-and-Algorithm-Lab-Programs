//To implement stack using singly linked list

#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack
{
    private:
        struct node
        {
            int data;
            struct node*next;
        };
        struct node*top;
    public:
        Stack()
        {top=NULL;}
        void push(int);
        int pop();
        void display();
        int peek();
};

int main()
{
    Stack obj;
    int data,choice,output;
    cout<<"\n<=======MENU=======>\n";
    cout<<"\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter an element to push : ";
                cin>>data;
                obj.push(data);
                break;
            
            case 2: 
                output=obj.pop();
                
                if(output)
                {
                    cout<<"The Deleted Element is : "<<output<<endl;
                }

                else
                {
                    cout<<"Stack Underflow!\n";
                }
                break;
            
            case 3:
                output=obj.peek();

                if(output)
                {
                    cout<<"Top of the Stack : "<<"\n===\n "<<output<<"\n===\n";
                }

                else
                {
                    cout<<"Error!The stack is empty!\n";
                }
                break;
            
            case 4:
                obj.display();
                break;
            
            default:
                cout<<"Invalid Choice!\n";
        }

        cout<<"\n<=======MENU=======>\n";
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    return 0;
}

void Stack::push(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}

int Stack::pop()
{
    if(top==NULL)
    {
        return 0;
    }

    else
    {
        int delnode=top->data;
        top=top->next;
        return delnode;
    }
}

int Stack::peek()
{
    if(top==NULL)
    {
        return 0;     
    }

    else
    {
        return top->data;
    }
}

void Stack::display()
{
    if(top==NULL)
    {
        cout<<"Error!Stack is Empty!\n";
    }

    else
    {
        struct node*temp=top;
        while(temp!=NULL)
        {
            cout<<"===\n "<<temp->data<<"\n===\n";
            temp=temp->next;
        }
    }
}