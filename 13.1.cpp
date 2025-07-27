#include <bits/stdc++.h>
using namespace std;




int main() {
    int n=0,m=0,b=0;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b=b+a[i][j];
            
        }cout<<b<<endl;
        b=0;
    }
    return 0;
}