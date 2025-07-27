#include <bits/stdc++.h>
using namespace std;
bool ppd(int a,int b){
    return a>b;
}
int main(){
    int a,c=0;
    cin>>a;
    int b[a];
    for (int i=0;i<a;i++){
        cin>>c;
        if (c<10){
            b[i]=c*11;
        }else{
            b[i]=c;
        }

    }

    sort(b,b+a,ppd);
    for (int i=0;i<a;i++){
        if (b[i]%11==0){
            b[i]=b[i]/11;
        }
    }
    for (int i=0;i<a;i++){
        cout<<b[i]<<endl;
    }
}