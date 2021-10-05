
//Problem Name: Longest Valid Parentheses

//Difficulty:Medium

//Statement: Given a string (consisting '(' ,')' ). Find the length of longest valid parentheses.

//Example:((())))()--length of longest valid parentheses is 8--->  ((()))()

#include<bits/stdc++.h>
using namespace std;


// function to find length of longest valid parentheses
 int longestValidParentheses(string s)
 {
        stack<int>index;
        stack<char>cc;
        index.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                cc.push('(');
                index.push(i);
                
            }
            else
            {
                if(!cc.empty())
                {
                    index.pop();
                    cc.pop();
                    
                    ans=max(ans,i-index.top());
                }
                else
                    index.push(i);
            }
        }
        return ans;
 }
 

//main function


    int main()
    {
        string s;
        cin>>s;
        cout<<"The length of longest valid parentheses for given string is "<<longestValidParentheses(s)<<"\n";
        
    }
       
