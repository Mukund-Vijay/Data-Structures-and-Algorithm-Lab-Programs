//Singly Linked List additional operations
#include <iostream>
#include <stdlib.h>
#include "sll2.h"
using namespace std;

int main()
{
    int data,choice,display_choice;
    cout<<"\nMenu\n";
    cout<<"\n1.Insert List 1\n2.Insert List 2\n3.Merge into List 3\n4.Display\n5.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    
    while(choice>5 || choice<1)
    {
        cout<<"Invalid Choice!\n";
        cout<<"\n<=======Menu=======>\n";
        cout<<"\n1.Insert List 1\n2.Insert List 2\n3.Merge into List 3\n4.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    
    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter the Data : ";
                cin>>data;
                obj1.insert_asc(data);
                break;
            
            case 2:
                cout<<"Enter the Data : ";
                cin>>data;
                obj2.insert_asc(data);
                break;
            case 3:
                obj3.merge(obj1,obj2);
                break;

            case 4:
                cout<<"Enter 1 for displaying list 1 or 2 for displaying list 2 or 3 for displaying the merged list : ";
                cin>>display_choice;
                
                while(display_choice>3 || display_choice<1)
                {
                    cout<<"Invalid Choice!\n";
                    cout<<"Enter 1 for displaying list 1 or 2 for displaying list 2 or 3 for displaying the merged list : ";
                    cin>>display_choice;
                }   
                
                if(display_choice==1)
                {
                    obj1.display();
                }

                else if(display_choice==2)
                {
                    obj2.display();
                }

                else
                {
                    obj3.display();
                }
                break;
        }

        cout<<"\nMenu\n";
        cout<<"\n1.Insert List 1\n2.Insert List 2\n3.Merge into List 3\n4.Display\n5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    
        while(choice>5 || choice<1)
        {
            cout<<"Invalid Choice!\n";
            cout<<"\nMenu\n";
            cout<<"\n1.Insert List 1\n2.Insert List 2\n3.Merge into List 3\n4.Exit\n";
            cout<<"\nEnter your choice : ";
            cin>>choice;
        }
    }
}