#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a[10000]={},b;string n;
    cin>>n>>b;
    int len=n.length();
    
    for(int i=0;i<len;i++){
        a[len-i]=n[i]-'0';
    }
    
    for(int i=1;i<=len;i++){
        a[i]=a[i]*b;
    }
    
    for(int i=1;i<=len;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    
    while(a[len+1]){
        len++;
        a[len+1]+=a[len]/10;
        a[len]%=10;
    }
    
    while(a[len]==0&&len>1) len--;
    
    for(int i=len;i>=1;i--){
        cout<<a[i];
    }
}