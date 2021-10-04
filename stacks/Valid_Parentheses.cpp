//Problem: here is solution to a well known problem on stacks--"Valid Parentheses"
//here we are using stack to check whether a  given string(containing '(',')','{','}','[',']')  contains a valid parentheses or not
//example: (),   {},    [],   {}(){},   [{}],  {{(([]))}} are valid 
//         ],    ([,    {{},  (((())] are strings with invalid parentheses


#include<bits/stdc++.h>
using namespace std;


//function to check valid parentheses
    bool isValid(string s)
    {
        
        stack<char>st;//STL stack
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                if((st.top()=='('&&s[i]==')')||(st.top()=='{'&&s[i]=='}')||(st.top()=='['&&s[i]==']'))
                    st.pop();
                else
                    return false;
                    
                    
            }
        }
        return st.empty();
    }
    
   
   
   //main function
    int main()
    {
        string s;
        cin>>s;
        if(isValid(s))
        {
            cout<<"Valid Parentheses"<<"\n";
        }
        else
        cout<<"Invalid Parentheses"<<"\n";
        return 0;
        
    }
       
