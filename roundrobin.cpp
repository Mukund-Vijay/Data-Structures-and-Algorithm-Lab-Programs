//To implement round robin fashion using circular linked list
#include <iostream>
#include <stdlib.h>
#include "header.h"
using namespace std;

int main()
{
    roundrobin obj;
    int time,choice;
    int cpu_time=5;
    cout<<"\n<=======Menu=======>\n";
    cout<<"\n1.Insert Process\n2.Execute\n3.Display\n4.Exit\n";
    cout<<"\nEnter your Choice : ";
    cin>>choice;
    
    while(choice!=4)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter the time required to complete the process : ";
                cin>>time;
                obj.insert_process(time);
                break;
            
            case 2:
                obj.execute(cpu_time);
                break;
            
            case 3:
                obj.display();
                break;

            case 4:
                cout<<"Exit!\n";
                break;
            
            default:
                cout<<"Invalid Choice!\n";
        }
        
        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert Process\n2.Execute\n3.Display\n4.Exit\n";
        cout<<"\nEnter your Choice : ";
        cin>>choice;
    }
    
    return 0;
}