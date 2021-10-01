#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int p[n+1];
    
    p[0]=1;
    p[1]=1;
    
    for(int i=2;i<=n;i++){
        p[i]=0;
        
        for(int j=0;j<i;j++){
            p[i]+=p[i-j-1]*p[j];
        }
    }
    
    cout << p[n] << "\n";
    
    return 0;
    
}
