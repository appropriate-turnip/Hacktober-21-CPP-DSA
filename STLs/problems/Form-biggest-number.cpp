#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a,string b)
{
    // first append b at end of a
    string ab=a.append(b);

    // now append a at end of b
    string ba= b.append(a);

    // now compare two as which one is bigger
    return ab.compare(ba) > 0 ? 1:0;
}
void printLargestValue(vector<string> v)
{
    sort(v.begin(),v.end(),cmp);

    for(auto i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<"\n";
}

int main()
{
    int T; //Test Cases
    cin>>T;
    while(T--)  
    {
        vector<string> v;
        int n;
        cin>>n;
        string s;
        for(int  i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(s);
        } 
        printLargestValue(v);
    }


    return 0;
}