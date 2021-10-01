#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int n=s.length();
    
    if(s.length()==1)
        cout << "1\n";
    else{
        
        int p[n][n];
        
        for(int i=0;i<n;i++)
            p[i][i]=1;
        
        int size=2;
        
        while(size<=n){
            for(int i=0;i<=n-size;i++){
                int j=i+size-1;
                
                if(s[i]==s[j] && size==2)
                    p[i][j]=2;
                else if(s[i]==s[j]){
                    p[i][j]=p[i+1][j-1]+2;
                }
                else
                    p[i][j]=max(p[i][j-1],p[i+1][j]);
            }
            size++;
        }
        
        cout << p[0][n-1] << "\n";
        
    }
    
    
}
