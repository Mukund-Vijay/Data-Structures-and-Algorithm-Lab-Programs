//To write a menu driven program which checks whether the number entered by the user is palindorme,armstrong or a perfect number  

#include <iostream>
#include <stdlib.h>
using namespace std;

int palindrome(int*);
int armstrong(int*);
int perfect(int*);
int digit_count(int*);

int main()
{
    int*num=(int*)malloc(sizeof(int));
    cout<<"\nEnter a number : ";
    cin>>*num;
    cout<<"<=======Menu=======>\n";
    cout<<"1.Palindrome\n2.Armstrong Number\n3.Perfect Number\n4.Exit\n";
    int*choice=(int*)malloc(sizeof(int));
    cout<<"Enter your choice : ";
    cin>>*choice;
    
    while(*choice<1 || *choice>4)
    {
        cout<<"Invalid Choice!\n";
        cout<<"Enter a valid choice : ";
        cin>>*choice;
    }

    while(*choice!=4)
    {
        if(*choice==1)
        {
            int*output=(int*)malloc(sizeof(int));
            *output=palindrome(num);

            if(*output == 1)
            {
                cout<<*num<<" is a palindrome.\n";
            }

            else
            {
                cout<<*num<<" is not a palindrome.\n";
            }
        }

        else if(*choice==2)
        {
            int*output=(int*)malloc(sizeof(int));
            *output=armstrong(num);

            if(*output == 1)
            {
                cout<<*num<<" is an armstrong number.\n";
            }

            else
            {
                cout<<*num<<" is not an armstrong number.\n";
            }
        }

        else if(*choice==3)
        {
            int*output=(int*)malloc(sizeof(int));
            *output=perfect(num);

            if(*output == 1)
            {
                cout<<*num<<" is a perfect number.\n";
            }

            else
            {
                cout<<*num<<" is not a perfect number.\n";
            }
        }

        cout<<"<=======Menu=======>\n";
        cout<<"1.Palindrome\n2.Armstrong Number\n3.Perfect Number\n4.Exit\n";
        cout<<"Enter your choice : ";
        cin>>*choice;
    }

    return 0;
}

int palindrome(int*num)
{
    int*temp=(int*)malloc(sizeof(int));
    *temp=*num;
    int*rev_num=(int*)malloc(sizeof(int));
    *rev_num=0;

    while(*temp!=0)
    {
        *rev_num=*temp%10+10*(*rev_num);
        *temp/=10;
    }

    if(*rev_num == *num)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int digit_count(int*temp)
{
    int*digits_temp=(int*)malloc(sizeof(int));
    *digits_temp=0;
    
    while(*temp!=0)
    {
        (*digits_temp)++;
        *temp/=10;
    }

    return *digits_temp;
}

int armstrong(int*num)
{
    int*temp=(int*)malloc(sizeof(int));
    *temp=*num;
    int*digits=(int*)malloc(sizeof(int));
    *digits=digit_count(temp);
    
    *temp=*num;
    int*sum=(int*)malloc(sizeof(int));
    int*product=(int*)malloc(sizeof(int));
    *sum=0;
    int*i=(int*)malloc(sizeof(int));
    int*j=(int*)malloc(sizeof(int));

    for(*i=0;*i<*digits;(*i)++)
    {
        *product=1;
        int*last_digit=(int*)malloc(sizeof(int));
        *last_digit=*temp%10;

        for(*j=0;*j<*digits;(*j)++)
        {
            *product*=*last_digit;
        }
        
        *sum+=*product;
        *temp/=10;
    }


    if(*sum == *num)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int perfect(int*num)
{
    int*sum=(int*)malloc(sizeof(int));
    int*product=(int*)malloc(sizeof(int));
    *sum=0;
    *product=1;
    int*i=(int*)malloc(sizeof(int));

    for(*i=1;*i<*num;(*i)++)
    {
        if(*num%(*i) == 0)
        {
            *sum+=*i;
            *product*=*i;
        }
    }

    if(*sum == *product)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}