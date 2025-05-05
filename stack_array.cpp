//To implement stack using array

#include <iostream>
#define MAX 5
using namespace std;

class Stack
{
    private:
        int stack[MAX];
        int top;
    
    public:
        Stack()
        {top=-1;}
        int push(int);
        int pop();
        void display();
        int peek();
};

int main()
{
    Stack obj;
    int data,choice,output;
    cout<<"\n<=======MENU=======>\n";
    cout<<"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter an element to push : ";
                cin>>data;
                output=obj.push(data);
            
                if(output)
                {
                    cout<<"Element pushed into the stack successfully!\n";
                }

                else
                {
                    cout<<"Stack Overflow!\n";
                }
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
        cout<<"\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    return 0;
}

int Stack::push(int data)
{
    if(top>=4)
    {
        return 0;
    }

    else
    {
        top++;
        cout<<top<<endl;
        stack[top]=data;
        return 1;
    }
}

int Stack::pop()
{
    if(top == -1)
    {
        return 0;
    }

    else
    {
        int del_ele=stack[top];
        top-=1;
        return del_ele;
    }
}

int Stack::peek()
{
    if(top == -1)
    {
        return 0;
    } 

    else
    {
        return stack[top];
    }
}

void Stack::display()
{
    if(top == -1)
    {
        cout<<"Error!Stack is Empty!\n";
    }

    else
    {
        for(int i=top;i>=0;i-=1)
        {
            cout<<"===\n "<<stack[i]<<"\n===\n";
        }
    }
}