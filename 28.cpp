#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[100],b;string n;
    memset(a,0,sizeof(a));
    cin>>n;
    int len=n.length();
    for(int i=0;i<len;i++){
        a[i]=n[i]-'0';
    }
    cin>>b;
    a[1]+=b;
    for (int i=1;i<=len;i++){
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    while(a[len+1]){
        len++;
        a[len+1]+=a[len]/10;
        a[len]%=10;
    }
    for(int i=len-1;i>=1;i--){
       
        cout<<a[i];
        
    }
}