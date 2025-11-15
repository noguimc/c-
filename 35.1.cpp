#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int b[a];
    for (int i=0;i<a;i++){
        cin>>b[i];
    }
    sort(b,b+a);
    for (int i=0;i<(a-1);i++){
        if(b[i]==b[i+1]){
            cout<<b[i];
        }
    }




    return 0;
}