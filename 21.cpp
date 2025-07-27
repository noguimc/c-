#include <bits/stdc++.h>
using namespace std;
int main(){
    int n[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>n[i][j];
        }
    }
    int a=0,b=0;
    cin>>a>>b;
    
    for(int i=0;i<3;i++){
        int c = n[i][a];
        n[i][a] = n[i][b];
        n[i][b] = c;
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<n[i][j]<<" ";
        }
        cout<<endl;
    }
}