#include <iostream>
#include <stack>
using namespace std;
int evaluate(string str)
{
    string nstr="";
    stack<char>s;
    stack<int>n;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==')')
        {
            while(s.top()!='(')
            {
                nstr=nstr+s.top();
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
            nstr=nstr+str[i];
        }
    }
    while(!s.empty())
    {
        nstr=nstr+s.top();
        s.pop();
    }
    for(int i=0;i<nstr.length();i++)
    cout<<nstr[i];
    int c;
    for(int i=0;i<nstr.length();i++)
    {
        if(nstr[i]>=48 && nstr[i]<=57)
        {
            n.push((int)nstr[i]);
        }
        else
        {
            int a=n.top();
            n.pop();
            int b=n.top();
            n.pop();
            if(nstr[i]=='+')
            c=a+b;
            else if(nstr[i]=='-')
            c=a-b;
            else if(nstr[i]=='*')
            c=a*b;
            else if(nstr[i]=='/')
            c=a/b;
            n.push(c);
        }
    }
    cout<<n.top();
}
int main()
{
    string str="(2+3)-(16-2)+4";
    evaluate(str);
}