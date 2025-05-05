/*
        A game which consist of three players has to enter a word of size three each. If the word entered by the player is distinct
        he gets 3 points,if two has entered the same then those two get 1 point each and if all the players entered the same then 
        none gets a point
                                    Sample IP : abc def abc
                                    Sample OP : 1 3 1
*/

#include <iostream>
using namespace std;

class words
{
    public:
        void input(string*,string*,string*,int);
        void process(string*,string*,string*,int);
};

int main()
{
    words obj;
    int testcases;
    cout<<"\nEnter the number of testcases : ";
    cin>>testcases;

    for(int i=0;i<testcases;i++)
    {
        int num;
        cout<<"\nEnter the number of words of each player : ";
        cin>>num;
        string player1[num];
        string player2[num];
        string player3[num];
        obj.input(player1,player2,player3,num);
        obj.process(player1,player2,player3,num);
    }
    return 0;
}

void words::input(string*player1,string*player2,string*player3,int num)
{
    cout<<endl;
    for(int j=0;j<num;j++)
    {
        cout<<"Enter word "<<j+1<<" of player 1 : ";
        cin>>player1[j];
    }
    cout<<endl;

    for(int j=0;j<num;j++)
    {
        cout<<"Enter word "<<j+1<<" of player 2 : ";
        cin>>player2[j];
    }
    cout<<endl;

    for(int j=0;j<num;j++)
    {
        cout<<"Enter word "<<j+1<<" of player 3 : ";
        cin>>player3[j];
    }
    cout<<endl;
}

void words::process(string*player1,string*player2,string*player3,int num)
{
    int points1=0;
    int points2=0;
    int points3=0;

    for(int j=0;j<num;j++)
    {
        int count=0;
        for(int k=0;k<num;k++)
        {
            if(player1[j]==player2[k])
            {
                count++;
            }
        }
        for(int k=0;k<num;k++)
        {
            if(player1[j]==player3[k])
            {
                count++;
            }
        }
        if(count==0)
        {
            points1+=3;
        }
        else if(count==1)
        {
            points1+=1;
        }
    }

    for(int j=0;j<num;j++)
    {
        int count=0;
        for(int k=0;k<num;k++)
        {
            if(player2[j]==player1[k])
            {
                count++;
            }
        }
        for(int k=0;k<num;k++)
        {
            if(player2[j]==player3[k])
            {
                count++;
            }
        }
        if(count==0)
        {
            points2+=3;
        }
        else if(count==1)
        {
            points2+=1;
        }
    }

    for(int j=0;j<num;j++)
    {
        int count=0;
        for(int k=0;k<num;k++)
        {
            if(player3[j]==player1[k])
            {
                count++;
            }
        }
        for(int k=0;k<num;k++)
        {
            if(player3[j]==player2[k])
            {
                count++;
            }
        }
        if(count==0)
        {
            points3+=3;
        }
        else if(count==1)
        {
            points3+=1;
        }
    }
    cout<<points1<<" "<<points2<<" "<<points3<<endl;
}