#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    string b;
    cin>>b;
    
    for(int i=0;i<a;i++){
        if (b[i]=='0'){  
            b[i]='1';    
        }else if (b[i]=='1'){  
            b[i]='0';    
        }
    }
    cout<<b;
    return 0;
}