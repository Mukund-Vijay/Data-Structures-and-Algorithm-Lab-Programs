/*Implementing Queue ADT using Array Data Structure of size 5
                            1.Enqueue
                            2.Dequeue
                            3.Peek
                            4.Display
                            5.Exit
*/

#include <iostream>                             
#define MAX 5
using namespace std;

class Queue_Arr
{
    private:
        int queue[MAX];
        int front,rear;
    public:
        Queue_Arr()
        {front=-1;rear=-1;}
        bool enqueue(int);
        int dequeue();
        int peek();
        void display();
};

int main()
{
    Queue_Arr obj;
    int choice,data,output;
    cout<<"\n<========Menu=======>";
    cout<<"\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter a data to insert : ";
                cin>>data;
                output=obj.enqueue(data);

                if(output)
                {
                    cout<<data<<" has been inserted in the queue successfully.\n";
                }
                else
                {
                    cout<<"Queue is full!\n";
                }
                break;

            case 2:
                output=obj.dequeue();

                if(output == -1)
                {
                    cout<<"Queue is empty!\n";
                }

                else
                {
                    cout<<output<<" has been kicked out of the queue.\n";
                }
                break;

            case 3:
                output=obj.peek();

                if(output == -1)
                {
                    cout<<"Queue is empty!\n";
                }
                else
                {
                    cout<<output<<" is the first in the queue.\n";
                }
                break;
            
            case 4:
                obj.display();
                break;

            default:
                cout<<"Invalid Choice!\n";
        }
        cout<<endl;
        cout<<"\n<========Menu=======>";
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
}

bool Queue_Arr::enqueue(int data)
{
    if(rear==MAX-1)
    {
        return false;
    }
    else
    {
        if(front==-1)
        {
            front++;
        }
        rear++;
        queue[rear]=data;
    }
}

int Queue_Arr::dequeue()
{
    if(front==-1 || rear==-1)
    {
        return -1;
    }
    else
    {
        int del=queue[front];
        int temp=front;
        while(temp<=rear)
        {
            queue[temp]=queue[temp+1];
            temp++;
        }
        rear--;
        return del;
    }
}

int Queue_Arr::peek()
{
    if(front==-1 || rear==-1)
    {
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void Queue_Arr::display()
{
    if(front==-1 || rear==-1)
    {
        cout<<"Queue is Empty!\n";
    }
    else
    {
        for(int i=0;i<rear;i++)
        {
            cout<<queue[i]<<"---";
        }
        cout<<queue[rear];
    }
}