/*
            Given a set of datas, consider it as a block and find what is the maximum number of blocks that the first level can hold 
            you can shift at max 1 block at a time and a(i)<a(j) to shift from a(j) to a(i)
                                        Sample IP : 1 2 3
                                        Sample OP : 3 2 1
*/

#include <iostream>
#include <deque>
#include <stack>
using namespace std;

class Block
{
    private:
        deque <int> deq;
        stack <int> st;
    public:
        void setdeque(int*,int);
        void blockshift();
        void display(int*,int);
};

int main()
{
    Block obj;
    int testcase,blocks,data;
    cout<<"\nEnter the number of test cases : ";
    cin>>testcase;

    for(int i=0;i<testcase;i++)
    {
        cout<<"\nEnter the number of blocks : ";
        cin>>blocks;
        int arr[blocks];

        for(int j=0;j<blocks;j++)
        {
            cout<<"Enter a data : ";
            cin>>arr[j];
        }

        obj.setdeque(arr,blocks);
        obj.blockshift();
        obj.display(arr,blocks);
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

void Block::setdeque(int*arr,int blocks)
{
    for(int i=0;i<blocks;i++)
    {
        deq.push_back(*(arr+i));
    }
}

void Block::blockshift()
{
    while(deq.size()!=1)
    {
        if(deq.front()<=deq.back())
        {
            deq.front()++;
            deq.back()--;
        }
        else
        {
            st.push(deq.back());
            deq.pop_back();
        }
    }
    st.push(deq.front());
    deq.pop_front();
}

void Block::display(int*arr,int blocks)
{
    cout<<"\nBlocks before shifting : ";
    for(int i=0;i<blocks;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Blocks after shifting : ";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}