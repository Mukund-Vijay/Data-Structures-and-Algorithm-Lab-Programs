/*
        In a given series of integer inputs,remove the leftmost element until the elements left have frequency of atmost 1 and print the number of moves
                                            Sample IP : 3 1 4 3
                                            Sample OP : 1
*/

#include <iostream>
#include <queue>
#define MAX 20
using namespace std;

class series
{
    private:
        int series[MAX];

    public:
        int getsize();
        void getseries(int);
        void process();
        bool isdistinct(int,int);
        void display(int); 
};

int main()
{
    series obj;
    int testcases;
    cout<<"\nEnter the number of testcases : ";
    cin>>testcases;

    for(int i=0;i<testcases;i++)
    {
        obj.process();
    }
    return 0;
}

int series::getsize()
{
    int size;
    cout<<"\nEnter the number of elements : ";
    cin>>size;
    return size;
}

void series::getseries(int size)
{
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>series[i];
    }
}

void series::process()
{
    int size=getsize();
    getseries(size);
    queue <int> que;
    for(int i=0;i<size;i++)
    {
        que.push(series[i]);
    }
    
    for(int i=0;i<size;i++)
    {
        if(!isdistinct(i,size))
        {
            que.pop();
        }
    }

    cout<<size-que.size()<<endl;
}

bool series::isdistinct(int i,int size)
{
    for(int j=i;j<size;j++)
    {
        int count=0;
        for(int k=i;k<size;k++)
        {
            if(series[j]==series[k])
            {
                count++;
            }
        }
        if(count>1)
        {
            return false;
        }
    }
    return true;
}

void series::display(int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<series[i]<<" ";
    }
    cout<<endl;
}
