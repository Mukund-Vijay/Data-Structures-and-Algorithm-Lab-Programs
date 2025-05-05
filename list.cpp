//To implement list ADT using classes

#include <iostream>
using namespace std;
#define max 5

class List
{
    private:
        int arr[max];
        int current;

    public:
        List()
        {current=-1;}
        int insertbeg(int);
        int insertend(int);
        int insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
        void rotate(int);
};

int main()
{
    List l1;
    int data,pos,num,rot,choice,output;
    cout<<"<=======Menu=======>\n";
    cout<<"1.Insert at the Begining\n2.Insert at the End\n3.Insert at a Position\n4.Delete at the Begining\n5.Delete at the End\n6.Delete at a Position\n7.Search an Element\n8.Display\n9.Rotate the List\n10.Exit\n"; 
    cout<<"Enter your choice : ";
    cin>>choice;

    while(choice>10 || choice<1)
    {
        cout<<"Invalid Choice!\n";
        cout<<"<=======Menu=======>\n";
        cout<<"1.Insert at the Begining\n2.Insert at the End\n3.Insert at a Position\n4.Delete at the Begining\n5.Delete at the End\n6.Delete at a Position\n7.Search an Element\n8.Display\n9.Rotate the List\n10.Exit\n"; 
        cout<<"Enter your choice : ";
        cin>>choice;
    }

    while(choice!=10)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter the Data : ";
                cin>>data;
                output=l1.insertbeg(data);

                if(output == 0)
                {
                    cout<<"Insertion Failed!\n";
                }

                else
                {
                    cout<<"Insertion Successfull!\n";
                }

                break;

            case 2:
                cout<<"Enter the Data : ";
                cin>>data;
                output = l1.insertend(data);

                if(output == 0)
                {
                    cout<<"Insertion Failed!\n";
                }

                else
                {
                    cout<<"Insertion Successfull!\n";
                }
                
                break;

            case 3:
                cout<<"Enter the Data : ";
                cin>>data;
                cout<<"Enter the Postion : ";
                cin>>pos;
                output=l1.insertpos(data,pos);

                if(output == 0)
                {
                    cout<<"Insertion Failed!\n";
                }

                else
                {
                    cout<<"Insertion Successfull!\n";
                }

                break;

            case 4:
                output=l1.delbeg();

                if(output == -1)
                {
                    cout<<"Deletion Failed!\n";
                }

                else
                {
                    cout<<"The Deleted Element is : "<<output<<endl;
                }

                break;

            case 5:
                output=l1.delend();

                if(output == -1)
                {
                    cout<<"Deletion Failed!\n";
                }

                else
                {
                    cout<<"The Deleted Element is : "<<output<<endl;
                }

                break;

            case 6:
                cout<<"Enter the Position : ";
                cin>>pos;
                output=l1.delpos(pos);

                if(output == -1)
                {
                    cout<<"Deletion Failed!\n";
                }

                else
                {
                    cout<<"The Deleted Element is : "<<output<<endl;
                }

                break;

            case 7:
                cout<<"Enter an element to search : ";
                cin>>num;
                output=l1.search(num);
                 
                if(output==0)
                {
                    cout<<"Element "<<num<<" is not found in the list.\n";
                }

                else
                {
                    cout<<"Element "<<num<<" is found "<<output<<" times in the list.\n";
                }

                break;

            case 8:
                l1.display();
                break;

            case 9:
                cout<<"Enter the value by which you want to swap : ";
                cin>>rot;
                l1.rotate(rot);
                break;

            case 10:
                cout<<"Exit!\n";

            default:
                cout<<"Invalid Choice!"<<endl;
        }

        cout<<"<=======Menu=======>\n";
        cout<<"1.Insert at the Begining\n2.Insert at the End\n3.Insert at a Position\n4.Delete at the Begining\n5.Delete at the End\n6.Delete at a Position\n7.Search an Element\n8.Display\n9.Rotate the List\n10.Exit\n"; 
        cout<<"Enter your choice : ";
        cin>>choice;
    }
    return 0;
}

int List::insertbeg(int data)
{
    if(current == 4)
    {
        cout<<"Stack OverFlow!\nDelete an element to add more!\n";
        return 0;
    }

    else
    {
        int temp=current;
        temp++;
        while(temp!=0)
        {
            arr[temp]=arr[temp-1];
            temp-=1;
        }
        arr[temp]=data;
        current++;
        return 1;
    }
}

int List::insertend(int data)
{
    if(current == 4)
    {
        cout<<"Stack Overflow!\nDelete an element to add more!\n";
        return 0;
    }

    else
    {
        current++;
        arr[current]=data;
        return 1;
    }
}

int List::insertpos(int data,int pos)
{
    if(current == -1 || pos==1)
    {
        int out=insertbeg(data);
        return out;
    }

    else if(pos==current+1)
    {
        int out=insertend(data);
        return out;
    }

    else
    {
        if(pos>current+1 || pos<1)
        {
            cout<<"Out of Range!\n";
            return 0;
        }

        else
        {
            int temp=current;
            temp++;
            while(temp!=pos-1)
            {
                arr[temp]=arr[temp-1];
                temp-=1;
            }
            arr[temp]=data;
            current++;
            return 1;
        }
    }
}

int List::delbeg()
{
    if(current == -1)
    {
        return -1;
    }

    else
    {
        int del=arr[0];
        int temp=0;
        while(temp!=current)
        {
            arr[temp]=arr[temp+1];
            temp++;
        }
        current--;
        return del;
    }
}

int List::delend()
{
    if(current == -1)
    {
        return -1;
    }

    else
    {
        int del=arr[current];
        arr[current]=arr[current-1];
        current--;
        return del;
    }
}

int List::delpos(int pos)
{
    if(current == -1)
    {
        return -1;
    }

    else
    {
        if(pos == 1)
        {
            int out=delbeg();
            return out;
        }

        else if(pos == current+1)
        {
            int out=delend();
            return out;
        }
        
        else if(pos>current+1 || pos<1)
        {
            cout<<"Out of Range!\n";
            return -1;
        }

        else
        {
            int del=arr[pos-1];
            for(int i=pos-1;i<=current;i++)
            {
                arr[i]=arr[i+1];
            }
            current--;
            return del;
        }
    }
}

int List::search(int num)
{
    int count=0;
    for(int i=0;i<=current;i++)
    {
        if(arr[i]==num)
        {
            cout<<"The element "<<num<<" is found at the index "<<i<<".\n";
            count++;
        }
    }

    return count;
}

void List::display()
{
    if(current == -1)
    {
        cout<<"List is Empty!\n";
    }

    else
    {
        for(int i=0;i<=current;i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
}

void List::rotate(int rot)
{
    if(current == -1 || current == 0)
    {
        cout<<"Rotation cannot be performed with such low number of elements!\nAdd more!\n";
    }   

    else
    {
        if(rot>current || rot<0)
        {
            cout<<"Rotation cannot be performed with this value!\n";
        }

        else
        {
            int arr_cpy[current+1];
            for(int i=0;i<=current;i++)
            {
                if(i+rot<=current)
                {
                    arr_cpy[i+rot]=arr[i];
                }

                else
                {
                    arr_cpy[(i+rot)%(current+1)]=arr[i];
                }
            }

            cout<<"The Rotated Array is : ";

            for(int i=0;i<=current;i++)
            {
                cout<<arr_cpy[i]<<"\t";
            }
            cout<<endl;
        }
    }
}
