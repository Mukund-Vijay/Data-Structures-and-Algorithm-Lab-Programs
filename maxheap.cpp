/*
            To construct a priority queue using a max heap with the following functions
                                    1.Insert
                                    2.Delete
                                    3.Display
                                    4.Search
                                    5.Heap Sort
                                    6.Exit
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

class MaxHeap
{
    private:
        vector <int> Heap[MAX];
    public:
        void construction(int);
        int del();
        int search(int);
        void heap_sort();
        void display();
};

int main()
{
    MaxHeap obj;
    int choice,len,key;
    cout<<"\n<=======Menu=======>\n";
    cout<<"\n1.Insert Element\n2.Delete Element\n3.Search Element\n4.Heap Sort\n5.Display\n6.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=6)
    {
        switch(choice)
        {
            case 1:
                cout<<"\nEnter the number of elements to be inserted : ";
                cin>>len;
                obj.construction(len);
                break;
            
            case 2:
                key=obj.del();
                if(key==0)
                {
                    cout<<"\nHeap is empty!\n";
                }
                else
                {
                    cout<<endl<<key<<" is deleted from the heap!\n";
                }
                break;

            case 3:   
                cout<<"\nEnter an element to search : ";
                cin>>key;
                
                if(obj.search(key)==-1)
                {
                    cout<<"Heap is empty!\n";
                }
                else if(obj.search(key)==1)
                {
                    cout<<"Element "<<key<<" found!\n";
                }
                else
                {
                    cout<<"Element "<<key<<" is not found!\n";
                }
                break;

            case 4:
                obj.heap_sort();
                break;

            case 5:
                obj.display();
                break;

            default:
                cout<<"\nInvalid Choice!\n";
        }
        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert Element\n2.Delete Element\n3.Search Element\n4.Heap Sort\n5.Display\n6.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    return 0;
}

void MaxHeap::construction(int len)
{
    Heap->clear();
    Heap->push_back(-1);
    for(int i=1;i<=len;i++)
    {
        int data;
        cout<<"\nEnter a data to insert : ";
        cin>>data;
        Heap->push_back(data);
        int current=i;

        while(current>1)
        {
            int parent=current/2;
            if(Heap->at(current)>Heap->at(parent))
            {
                swap(Heap->at(current),Heap->at(parent));
                current=parent;
            }
            else
            {
                break;
            }
        }
    }
}

int MaxHeap::del()
{
    if(Heap->size()==0)
    {
        return 0;
    }
    else
    {
        int del=Heap->at(1);
        swap(Heap->at(1),Heap->at(Heap->size()-1));
        Heap->pop_back();
        int current=1;

        while(current<=(Heap->size())/2)
        {
            int left_child=2*current;
            int right_child=(2*current)+1;
            int track=current;

            if(left_child<Heap->size() && Heap->at(left_child)>Heap->at(current))
            {
                track=left_child;
            }
            if(right_child<Heap->size() && Heap->at(right_child)>Heap->at(track))
            {
                track=right_child;
            }
            if(track==current)
            {
                break;
            }
        
            swap(Heap->at(track),Heap->at(current));
            current=track;
            
        }
        return del;
    }
}

int MaxHeap::search(int key)
{
    if(Heap->size()==0)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<Heap->size();i++)
        {
            if(Heap->at(i)==key)
            {
                return 1;
            }
        }
        return 0;
    }
}

void MaxHeap::heap_sort()
{
    vector <int> sorted_heap;
    while(Heap->size()>1)
    {
        sorted_heap.push_back(del());
    }
    for(int i=sorted_heap.size()-1;i>=0;i--)
    {
        cout<<sorted_heap.at(i)<<" ";
    }
}

void MaxHeap::display()
{
    for(int i=1;i<Heap->size();i++)
    {
        cout<<Heap->at(i)<<" ";
    }
}
