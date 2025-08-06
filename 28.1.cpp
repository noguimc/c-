#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[100];string n,b;
    memset(a,0,sizeof(a));
    cin>>n;
    int len=n.length();
    for(int i=1;i<=len;i++){
        a[i]=n[len-i]-'0';
    }
    cin>>b;
    int len2=b.length();
    for (int i=1;i<=len2;i++){
        a[i]-=b[len2-i]-'0';
    }

    for(int i=1;i<=len;i++){
        while(a[i]<0){
            a[i+1]--;
            a[i]+=10;
        }
    }
    while(len>1&&a[len]==0){
        len--;
    }
    for(int i=len;i>=1;i--){
        cout<<a[i];
    }
}