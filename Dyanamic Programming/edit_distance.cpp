// Problem Link: https://leetcode.com/problems/edit-distance/
#include<bits/stdc++.h>
using namespace std;
int helper(string &s1,string &s2,int n,int m,int i,int j,vector<vector<int>> &dp) {
    if(i==n && j==m) return 0;
    if(j==m) return n-i;
    if(i==n) return m-j;
    if(dp[i][j] != -1)
    return dp[i][j];
    if(s1[i] == s2[j])
    return dp[i][j] = helper(s1,s2,n,m,i+1,j+1,dp);
    else{
        return dp[i][j] = 1 + min(helper(s1,s2,n,m,i+1,j,dp),min(helper(s1,s2,n,m,i,j+1,dp),helper(s1,s2,n,m,i+1,j+1,dp)));
    } 
}
int main() {
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<helper(s1,s2,n,m,0,0,dp);
}