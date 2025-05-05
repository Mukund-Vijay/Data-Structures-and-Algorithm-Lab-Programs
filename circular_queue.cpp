/*
        To implement circular queue ADT using Array data structure of size 5
                            1.Enque
                            2.Deque
                            3.Peek
                            4.Display
                            5.Exit
*/

#include <iostream>
#define MAX 5
using namespace std;

class Circular_Queue
{
    private:
        int circular_queue[MAX];
        int front,rear;
    public:
        Circular_Queue()
        {front=-1;rear=-1;}
        bool enque(int);
        int deque();
        int peek();
        void display();
};

int main()
{
    Circular_Queue obj;
    int data,choice,output;
    cout<<"\n<=======Menu=======>\n";
    cout<<"1.Enque\n2.Deque\n3.Peek\n4.Display\n5.Exit\n";
    cout<<"Enter your choice : ";
    cin>>choice;

    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter the data : ";
                cin>>data;
                output=obj.enque(data);

                if(output)
                {
                    cout<<data<<" has been enqued sucessfully!\n";
                }
                else
                {
                    cout<<"The Queue is Full!\n";
                }
                break;
            
            case 2:
                output=obj.deque();

                if(output==-1)
                {
                    cout<<"Queue is Empty!\n";
                }
                else
                {
                    cout<<output<<" is kicked out of the queue!\n";
                }
                break;

            case 4:
                obj.display();
                break;
        }
        cout<<"\n<=======Menu=======>\n";
        cout<<"1.Enque\n2.Deque\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
    }
    return 0;
}

bool Circular_Queue::enque(int data)
{
    if(rear==MAX-1)
    {
        return false;
    }
    else if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        circular_queue[front]=data;
        return true;
    }
    rear=(rear+1)%MAX;
    circular_queue[rear]=data;
    return true;
}

int Circular_Queue::deque()
{
    if(front==-1)
    {
        return -1;
    }
    int del=circular_queue[front];
    front++;
    rear=(rear-1)%MAX;
    return del;
}

void Circular_Queue::display()
{
    if(front==-1)
    {
        cout<<"Queue is Empty!\n";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<circular_queue[i]<<"---";
        }
        cout<<circular_queue[front];
    }
}