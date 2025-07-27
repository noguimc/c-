#include <bits/stdc++.h>

using namespace std;
int a[5]={45,12,53,2,35};
int main(){
    
    for (int i=1;i<5;i++) {
        int k=a[i];  
        int j=i-1;
        
        while (j>=0&&a[j]>k) {
            a[j+1]=a[j];
            j--;
        }
        
        a[j+1]=k;
    }
    for (int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}