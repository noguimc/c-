#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b=0,c=0;
    cin>>a;
    for (int i=0;i<a-1;i++){
        c=b;
        cin>>b;
        if(b-c>1){
            cout<<c+1<<endl;
        }
    }
    return 0;
}