#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[]={6,2,1,4},sum=0,n=4;
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            for(int i=l;i<=r;i++){
                sum+=a[i];
            }
        }
    }
    cout<<sum<<endl;
}