#include <bits/stdc++.h>
using namespace std;
int main(){
    int max=0,sum=0,n=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            sum=0;
            for(int i=l;i<=r;i++){
                sum+=a[i];
            }if (sum>max){
                max=sum;
            }
        }
    }
    if(max>0){
        cout<<max<<endl;
    }else{
        cout<<'0'<<endl;
    }
    
}