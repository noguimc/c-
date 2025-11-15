#include <bits/stdc++.h>
using namespace std;
int main(){
    string name;
    cin>>name;
    string a[name.length()];
    for(int i=0;i<name.length();i++){
        a[i]=name[i];
    }
    int sum=0,n=name.length(),ok=1;
    for(int l=0;l<n;l++){
        for(int r=l+1;r<n;r++){  
            ok=1;
            string c[r-l+1],d[r-l+1];
            for(int i=l;i<=r;i++){
                c[i-l]=a[i];  
                d[r-i]=a[i];  
            }
            for(int i=0;i<=r-l;i++){  
                if(c[i]!=d[i]){
                    ok=0;
                    break;
                }
            }
            if(ok==1){
                sum+=1;
            }
        }
    }
    cout<<sum<<endl;
}