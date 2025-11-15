#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
    cin>>a;
    int b[a+2];
    for (int i=0;i<a;i++){
        cin>>b[i];
    }
    int x,y;
    cin>>x>>y;
    x=x-1;
    for(int i=a;i>=x;i--){
        b[i+1]=b[i];
    }
    b[x]=y;
    for (int i=0;i<(a+1);i++){
        cout<<b[i];
    }
}