/*
    Given the weights of the contestants,subtract the highest weight from the contestants weight
                                        Sample IP : 5 7 3 4
                                        Sample OP : -2 2 -4 -3
*/

#include <iostream>
#define MAX 100
using namespace std;

class Weight
{
    private:
        int out[MAX];
    public:
        void input(int*,int);
        void process(int*,int);
        void display(int);
};

int main()
{
    Weight obj;
    int testcase;
    cout<<"\nEnter the number of testcases : ";
    cin>>testcase;

    for(int i=0;i<testcase;i++)
    {
        int ele;
        cout<<"\nEnter the number of elements : ";
        cin>>ele;
        int weights[ele];
        obj.input(weights,ele);
        obj.process(weights,ele);
        obj.display(ele);
    }
    return 0;
}

void Weight::input(int*weights,int ele)
{
    cout<<endl;
    for(int i=0;i<ele;i++)
    {
        cout<<"Enter the weight of contestant "<<i+1<<" : ";
        scanf("%d",weights+i);
    }
}

void Weight::process(int*weights,int ele)
{
    int max1=0;
    int max2=0;
    int count=0;

    for(int i=0;i<ele-1;i++)
    {
        if(weights[i]==weights[i+1])
        {
            count++;
        }
    }

    if(count+1==ele)
    {
        max1=max2=weights[0];

    }

    else
    {
        for(int i=0;i<ele;i++)
        {
            if(max1<weights[i])
            {
                max1=weights[i];
            }
        }
    
        for(int i=0;i<ele;i++)
        {
            if(max2<weights[i] && max1>weights[i])
            {
                max2=weights[i];
            }
        }
    }

    for(int i=0;i<ele;i++)
    {
        if(weights[i]<max1)
        {
            out[i]=weights[i]-max1;
        }
        else
        {
            out[i]=max1-max2;
        }
    }
}

void Weight::display(int ele)
{
    for(int i=0;i<ele;i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<endl;
}