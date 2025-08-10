#include <bits/stdc++.h>
using namespace std;
int a[10000]={1},b[10000]={},c[10000]={};
int main(){
    int n;cin>>n;
    string s;
    
    while(n--){
        cin>>s;
        int l=s.length();
        memset(b,0,sizeof(b));
        for(int i=0;i<l;i++) b[l-i]=s[i]-'0';
        
        memset(c,0,sizeof(c));
        for(int i=1;i<=1000;i++)
            for(int j=1;j<=l;j++)
                c[i+j-1]+=a[i]*b[j];
                
        for(int i=1;i<=2000;i++){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        
        int len=2000;
        while(c[len]==0&&len>1) len--;
        memcpy(a,c,sizeof(c));
    }
    
    int len=2000;
    while(a[len]==0&&len>1) len--;
    for(int i=len;i>=1;i--) cout<<a[i];
}
