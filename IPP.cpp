#include <iostream>
#include <stack>
#include <string>
using namespace std;
void infixToPostfix(stack <char>s,string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==')')
        {
            while(s.top()!='(')
            {
                cout<<s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='(')
        {
            s.push(str[i]);
        }
        else
        {
            cout<<str[i];
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
void prefixToInfix(stack <string>s,string str)
{
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            string a=s.top();
            s.pop();
            string b=s.top();
            s.pop();
            string c="("+a+str[i]+b+")";
            s.push(c);
        }
        else
        {
            string ns=string(1,str[i]);
            s.push(ns);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
void prefixToPostfix(stack <string>s,string str)
{
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            string a=s.top();
            s.pop();
            string b=s.top();
            s.pop();
            string c=a+b+str[i];
            s.push(c);
        }
        else
        {
            string ns=string(1,str[i]);
            s.push(ns);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
void postfixToPrefix(stack <string>s,string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            string a=s.top();
            s.pop();
            string b=s.top();
            s.pop();
            string c=str[i]+b+a;
            s.push(c);
        }
        else
        {
            string ns=string(1,str[i]);
            s.push(ns);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
void postfixToInfix(stack <string>s,string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            string a=s.top();
            s.pop();
            string b=s.top();
            s.pop();
            string c="("+b+str[i]+a+")";
            s.push(c);
        }
        else
        {
            string ns=string(1,str[i]);
            s.push(ns);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
void infixToPrefix(stack <char>s,string str)
{
    string rev="";
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]=='(')
        rev=rev+")";
        else if(str[i]==')')
        rev=rev+"(";
        else
        rev=rev+str[i];        
    }
    //infix->postfix
    string nstr="";
    for(int i=0;i<rev.length();i++)
    {
        if(rev[i]==')')
        {
            while(s.top()!='(')
            {
                nstr=s.top()+nstr;
                s.pop();
            }
            s.pop();
        }
        else if(rev[i]=='+' || rev[i]=='-' || rev[i]=='*' || rev[i]=='/' || rev[i]=='(')
        {
            s.push(rev[i]);
        }
        else
        {
            nstr=rev[i]+nstr;
        }
    }
    while(!s.empty())
    {
        nstr=s.top()+nstr;
        s.pop();
    }
    for(int i=0;i<nstr.length();i++)
    cout<<nstr[i];
}
int main()
{
    string str="A+(B*C)";
    stack <char>s;
    infixToPrefix(s,str);
}