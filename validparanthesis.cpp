//To check whether the given string of paranthesis are valid or not

#include <iostream>
#include <stack>
using namespace std;

class ValidParanthesis
{
    private:
        stack <char> st;
    
    public:
        bool isvalid(string);
};

int main()
{
    ValidParanthesis obj;
    int choice,output;
    string str;
    cout<<"\n<=======MENU=======>\n";
    cout<<"1.Check Balance\n2.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    while(choice!=2)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter a string : ";
                cin>>str;
                output=obj.isvalid(str);

                if(output)
                {
                    cout<<"Valid!\n";
                }

                else
                {
                    cout<<"Not Valid!\n";
                }
                break;
        
            default:
                cout<<"Invalid Choice!\n";
        }
        cout<<"\n<=======MENU=======>\n";
        cout<<"\n1.Check Balance\n2.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
    }
    return 0;
}

bool ValidParanthesis::isvalid(string str)
{
    if(str[0]==')')
    {
        return false;
    }

    else
    {
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]=='(')
            {
                st.push(str[i]);
            }

            else if(!st.empty())
            {
                if(str[i]==')' && st.top()=='(')
                {
                    st.pop();
                }
            }

            else
            {
                return false;
            }
        }
    }

    if(st.empty())
    {
        return true;
    }

    else
    {
        return false;
    }
}