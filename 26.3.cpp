#include <bits/stdc++.h>
using namespace std;
int a[5]={45,12,53,2,35};
int m; 
int main(){
    for (int i=0;i<5;i++){
        m = i; 
        for (int j=i+1;j<5;j++){
            if (a[j] < a[m]){ 
                m = j;
            }
        }
        
        if (m != i) {
            int t = a[i];
            a[i] = a[m];
            a[m] = t;
        }
    }
    for (int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}