/*To take a string containing + in it and return a string which removes + and 
  the immediate left element to it
                    Sample IP - 45fdg+++ab+c
                    Sample OP - 45ac
*/

#include <iostream>
#include <stack>
using namespace std;

class Q4
{
    private:
        string final_str;
    public:
        Q4()
        {final_str="";}
        int countplus(string);
        int length(string);
        string process(string);
        string reverse(string);
};

int main()
{
    Q4 obj;
    string str;
    cout<<"\nEnter an expression with plus : ";
    cin>>str;
    int count=obj.countplus(str);

    if(count==0)
    {
        cout<<"Orginal String : "<<str<<endl;
        cout<<"Modified String : "<<str;
    }
    else
    {
        string modified_str=obj.process(str);
        cout<<"Orginal String : "<<str<<endl;
        cout<<"Modified String : "<<modified_str;
    }
    cout<<endl<<endl;
    return 0;
}

int Q4::countplus(string str)
{
    int count=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='+')
        {
            count++;
        }
    }
    return count;
}

int Q4::length(string temp_str)
{
    int len=0;
    for(int i=0;temp_str[i]!='\0';i++)
    {
        len++;
    }
    return len;
}

string Q4::reverse(string temp_str)
{
    string temp_modified="";
    for(int i=length(temp_str)-1;i>=0;i--)
    {
        temp_modified+=temp_str[i];
    }
    return temp_modified;
}

string Q4::process(string str)
{
    stack <char> st;
    string temp_str="";
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='+' && !st.empty())
        {
            st.pop();
        }
        else if(str[i]!='+')
        {
            st.push(str[i]);
        }
    }
    while(!st.empty())
    {
        temp_str+=st.top();
        st.pop();
    }
    string modified_str=reverse(temp_str);
    return modified_str;
}