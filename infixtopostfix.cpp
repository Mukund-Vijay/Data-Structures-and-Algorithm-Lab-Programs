//To convert the given infix expression to postfix

#include <iostream>
#include <sstream>
#include <stack>
#include <string.h>
#define MAX 100
using namespace std;

class Conversion
{
    private:
        string postfix;
    public:
        Conversion()
        {postfix="";}
        bool operand_or_operator(char);
        int precedence(char);
        int associativity(char);
        string get_infix();
        bool check_infix(string);
        int operators(char);
        string convert_infix(string);
        int evaluation(string);
};

int main()
{
    Conversion obj;
    string exp=obj.get_infix();
    bool output=obj.check_infix(exp);
    if(!output)
    {
        cout<<"Invalid Expression!";
    }
    else
    {
        string postfix_exp=obj.convert_infix(exp);
        cout<<"The Postfix equivalent of "<<exp<<" is "<<postfix_exp<<endl;
        float res=obj.evaluation(postfix_exp);
        cout<<exp<<" = "<<res;
    }
    
    return 0;
}

bool Conversion::operand_or_operator(char chr)
{
    if(isalnum(chr))
    {
        return true;
    }

    else
    {
        return false;
    }
}

int Conversion::precedence(char chr)
{
    if(chr=='=')
    {
        return 1;
    }
    else if(chr=='+'||chr=='-')
    {
        return 2;
    }
    else if(chr=='*'||chr=='/'||chr=='%')
    {
        return 3;
    }
}

int Conversion::associativity(char chr)
{
    if(chr=='=')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

string Conversion::get_infix()
{
    string temp_exp;
    cout<<"Enter the infix expression : ";
    cin>>temp_exp;
    return temp_exp;
}

bool Conversion::check_infix(string exp)
{
    if(!(operand_or_operator(exp[0]) && operand_or_operator(exp[exp.length()-1])) && exp[exp.length()-1]!=')')
    {
        return false;
    }

    else
    {
        for(int i=0;exp[i]!='\0';i++)
        {
            if(!(operand_or_operator(exp[i]) || operand_or_operator(exp[i+1])) && (exp[i]!='(' && exp[i]!=')') && (exp[i+1]!='(' && exp[i+1]!=')'))
            {
                return false;
            }
        }
        return true;
    }
}

string Conversion::convert_infix(string exp)
{
    stack <char> operators;
    
    for(int i=0;exp[i]!='\0';i++)
    {
        if(operand_or_operator(exp[i]))
        {
            postfix+=exp[i];
        }
        
        else
        {
            while(!operators.empty() && precedence(operators.top())>=precedence(exp[i]) || !associativity(exp[i]) && operators.top()!='(')
            {
            postfix+=operators.top();
            operators.pop();
            }
            operators.push(exp[i]);
            
        }
    }

    while(!operators.empty())
    {
        postfix+=operators.top();
        operators.pop();
    }

    
    string true_postfix="";

    for(int i=0;postfix[i]!='\0';i++)
    {
        if(postfix[i]!='(' && postfix[i]!=')')
        {
            true_postfix+=postfix[i];
        }
    }
    return true_postfix;
}

int Conversion::operators(char chr)
{
    switch(chr)
    {
        case '=':
            return 1;
        
        case '+':
            return 2;
        
        case '-':
            return 3;

        case '*':
            return 4;

        case '/':
            return 5;

        case '%':
            return 6;
    }
}

int Conversion::evaluation(string postfix_exp)
{
    stack <int> operand;
    
    for(int i=0;postfix_exp[i]!='\0';i++)
    {
        if(operand_or_operator(postfix_exp[i]))
        {
            operand.push((postfix_exp[i])-'0');
        }

        else if(operators(postfix_exp[i])==2)
        {
            float temp=operand.top();
            operand.pop();
            float temp1=temp+operand.top();
            operand.pop();
            operand.push(temp1);
        }

        else if(operators(postfix_exp[i])==3)
        {
            float temp=operand.top();
            operand.pop();
            float temp1=operand.top()-temp;
            operand.pop();
            operand.push(temp1);
        }

        else if(operators(postfix_exp[i])==4)
        {
            float temp=operand.top();
            operand.pop();
            float temp1=temp*operand.top();
            operand.pop();
            operand.push(temp1);
        }

        else if(operators(postfix_exp[i])==5)
        {
            float temp=operand.top();
            operand.pop();
            float temp1=operand.top()/temp;
            operand.pop();
            operand.push(temp1);
        }

        else
        {
            int temp=operand.top();
            operand.pop();
            int temp1=operand.top()%temp;
            operand.pop();
            operand.push(temp1);
        }
    }

    float result=operand.top();
    operand.pop();
    return result;
}
